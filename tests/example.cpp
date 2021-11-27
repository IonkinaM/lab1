
#include "example.hpp"

TEST(Example, EmptyTest) 
{
    EXPECT_TRUE(true);
}

TEST(ExistFile, Test)
{
    std::string jsonPath;
    jsonPath = PATH_TO_JSON;
    std::ifstream file{jsonPath};
    bool val = file.fail();
    EXPECT_EQ(val, false);
}

TEST(Meta, Test)
{
    std::string jsonPath;
    jsonPath = PATH_TO_JSON;
    std::ifstream file{jsonPath};
    json data;
    file >> data;
    std::vector<Student> st;
    st = read_file(data);
    size_t val1 = data.at("_meta").at("count");
    size_t val2 = st.size();
    EXPECT_EQ(val1, val2);
}


TEST(Table, Test)
{
    std::string tmp = R"(| name |  group   | avg  | debt      |
|---------------|-----------|-------|-----------|
|                             Ivanov Petr	     | 1			| 4.25	| null		|
|---------------|-----------|-------|-----------|
| Sidorov Ivan	| 31 group	| 4		| C++		|
|---------------|-----------|-------|-----------|
| Pertov Nikita| IU8-31	                                                                | 3.33	| 3 items	|
|---------------|-----------|-------|-----------|
)";

    std::string jsonPath = PATH_TO_JSON;
    std::ifstream file{jsonPath};
    json data;
    file >> data;
    std::vector<Student> st;
    st = read_file(data);
    std::stringstream os;
    print(st, os);
    EXPECT_EQ(tmp, os.str());
}

TEST(isArray, Test)
{
    std::string jsonPath;
    jsonPath = PATH_TO_JSON;
    std::ifstream file{jsonPath};
    json data;
    file >> data;
    bool val1 = data["items"].is_array();
    EXPECT_EQ(val1, true);
}

TEST(ValidInfo, Test)
{
    std::string jsonPath;
    jsonPath = PATH_TO_JSON;
    std::ifstream file{jsonPath};
    json data;
    file >> data;
    std::vector<Student> st;
    st = read_file(data);
    EXPECT_EQ(std::any_cast<std::string>(st[0].name),"Ivanov Petr");
    EXPECT_EQ(std::any_cast<std::string>(st[0].group),"1");
    EXPECT_EQ(std::any_cast<std::string>(st[0].avg),"4.25");
    EXPECT_EQ(std::any_cast<std::nullptr_t>(st[0].debt), nullptr);

    EXPECT_EQ(std::any_cast<std::string>(st[1].name),"Sidorov Ivan");
    EXPECT_EQ(std::any_cast<std::size_t>(st[1].group),31);
    EXPECT_EQ(std::any_cast<std::size_t>(st[1].avg),4);
    EXPECT_EQ(std::any_cast<std::string>(st[1].debt), "C++");

    EXPECT_EQ(std::any_cast<std::string>(st[2].name),"Pertov Nikita");
    EXPECT_EQ(std::any_cast<std::string>(st[2].group),"IU8-31");
    EXPECT_EQ(std::any_cast<std::double_t>(st[2].avg),3.33);
    std::vector<std::string> temp;
    temp.push_back("C++");
    temp.push_back("Linux");
    temp.push_back("Network");
    EXPECT_EQ(std::any_cast<std::vector<std::string>>(st[2].debt), temp);
}

TEST(DebtType, Test)
{
    std::string jsonPath;
    jsonPath = PATH_TO_JSON;
    std::ifstream file{jsonPath};
    json data;
    file >> data;
    std::vector<Student> st;
    st = read_file(data);
    bool _flag = false;
    for (auto const& student : st) {
        if (student.debt.type() == typeid(std::nullptr_t)){
            _flag = true;
        } else if (student.debt.type() == typeid(std::string)){
            _flag = true;
        } else if (student.debt.type() == typeid(std::vector<std::string>)){
            _flag = true;
        }
    }
    EXPECT_EQ(g_flag, true);
}

TEST(GroupType, Test)
{
    std::string jsonPath;
    jsonPath = PATH_TO_JSON;
    std::ifstream file{jsonPath};
    json data;
    file >> data;
    std::vector<Student> st;
    st = read_file(data);
    bool _flag = false;
    for (auto const& student : st) {
        if (student.group.type() == typeid(std::size_t))
        {
            _flag = true;
        } 
        	else 
        		if (student.group.type() == typeid(std::string))
        		{
            		_flag = true;
			}
    	}
    EXPECT_EQ(_flag, true);
}

TEST(AvgType, Test) 
{
    std::string jsonPath;
    jsonPath = PATH_TO_JSON;
    std::ifstream file{jsonPath};
    json data;
    file >> data;
    std::vector<Student> st;
    st = read_file(data);
    bool _flag = false;
    for (auto const &student : st)
     {
        if (student.avg.type() == typeid(std::size_t))
         {
            _flag = true;
         } 
         else 
         	if (student.avg.type() == typeid(std::string)) 
         		{
            		_flag = true;
        		} 
				else 
					if (student.avg.type() == typeid(std::double_t))
					 {
            					_flag = true;
						}
    }
    EXPECT_EQ(_flag, true);
}
