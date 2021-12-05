#ifndef INCLUDE_STUDENT_HPP_
#define INCLUDE_STUDENT_HPP_

#include <fstream>
#include <iostream>
#include <string>
#include <any>
#include <vector>
#include <stdexcept>
#include <nlohmann/json.hpp>
#include <algorithm>

using nlohmann::json;

struct Student{
    std::string name;
    std::any group;
    std::any avg;
    std::any debt;
};

auto get_name(const json& j) -> std::string;

auto get_debt(const json& j) -> std::any;

auto get_avg(const json& j) -> std::any;

auto get_group(const json& j) -> std::any;

void from_json(const json& j, Student& s);

std::vector<Student> read_file(json data);
void print(const std::vector<Student>& students, std::ostream& os);
void print(const Student& student, std::ostream& os);

#endif // INCLUDE_STUDENT_HPP_

