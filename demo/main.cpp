#include <student.hpp>

int main(int argc, char* argv[]) {
    std::string jsonPath;
    if (argc < 2){
        throw std::runtime_error("Path is not exist");
    } else {
        jsonPath = argv[1];
    }

    std::ifstream file{jsonPath};
    if (!file) {
        throw std::runtime_error{"unable to open json: " + jsonPath};
    }

    json data;
    file >> data;

    if (data["_meta"]["count"] != data["items"].size()){
        throw std::runtime_error{"_meta doesn't equal number of students"};
    }

    if (!data["items"].is_array()){
        throw std::runtime_error{"items is not array"};
    }

    std::vector<Student> students = read_file(data);
    print(students, std::cout);
}