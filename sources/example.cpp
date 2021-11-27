

#include <stdexcept>

#include <example.hpp>



auto get_name(const json& _j) -> std::string 
{
    return _j.get<std::string>();
}

auto get_debt(const json& _j) -> std::any {
    if (_j.is_null())
        return nullptr;
    else if (_j.is_string())
        return _j.get<std::string>();
    else
        return _j.get<std::vector<std::string> >();
}

auto get_avg(const json& _j) -> std::any {
    if (_j.is_null())
        return nullptr;
    else if (_j.is_string())
        return _j.get<std::string>();
    else if (_j.is_number_float())
        return _j.get<double>();
    else
        return _j.get<std::size_t>();
}

auto get_group(const json& _j) -> std::any {
    if (_j.is_string())
        return _j.get<std::string>();
    else
    return _j.get<std::size_t>();
}

void from_json(const json& _j, Student& _st) {
    _st.name = get_name(_j.at("name"));
    _st.group = get_group(_j.at("group"));
    _st.avg = get_avg(_j.at("avg"));
    _st.debt = get_debt(_j.at("debt"));
}
void print(const Student& _st, std::ostream& os){
    if (_st.name.empty()){
        os << "| null\t|";
    } else {
        os << "| " << _st.name << "\t|";
    }

    if (_st.group.type() == typeid(std::nullptr_t)){
        os << "null|";
    } else if (_st.group.type() == typeid(std::string)){
        if (std::any_cast<std::string>(_st.group).length() == 1){
            os << " " << std::any_cast<std::string>(_st.group) << "\t\t\t|";
        } else {
            os << " " << std::any_cast<std::string>(_st.group) << "\t|";
        }
    } else {
        os << " " << std::any_cast<std::size_t>(_st.group)
           << " group\t|";
    }

    if (_st.avg.type() == typeid(std::nullptr_t))
    {
        os << "null\t|";
    } 
    else 
    	if (_st.avg.type() == typeid(std::string))
    		{
        		os << " " << std::any_cast<std::string>(_st.avg) << "\t|";
    		} else 
    			if (_st.avg.type() == typeid(std::double_t))
    				{
        				os << " " << std::any_cast<std::double_t>(_st.avg) << "\t|";
    				} 
    					else 
    						{
        						os << " " << std::any_cast<std::size_t>(_st.avg) << "\t\t|";
    						}

    if (_st.debt.type() == typeid(std::nullptr_t))
    {
        os << " null\t\t|" << std::endl;
    } 
    	else 
    	if (_st.debt.type() == typeid(std::string)) 
    		{
        	os << " " << std::any_cast<std::string>(_st.debt)
                << "\t\t|" <<  std::endl;
    		} 
    			else 
    			{
        		os
        		<< " " << std::any_cast<std::vector<std::string>>(_st.debt).size()
        		<< " items\t|" << std::endl;
    			}
}

void print(const std::vector<Student>& _st , std::ostream& os) 
{
    os << "| name          | group     | avg   | debt      |\n";
    os << "|---------------|-----------|-------|-----------|\n";
    for (auto const& student : _st) 
    {
        print(student, os);
        os << "|---------------|-----------|-------|-----------|\n";
    }
}

std::vector<Student> read_file(json data) 
{
    std::vector<Student> _st;
    for (auto const &item : data.at("items")) 
    {
        Student student;
        from_json(item, student);
        _st.push_back(student);
    }
    return _st;
}
