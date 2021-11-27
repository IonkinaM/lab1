
#ifndef INCLUDE_EXAMPLE_HPP_
#define INCLUDE_EXAMPLE_HPP_
#include <any>
#include <nlohmann/json.hpp>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <gtest/gtest.h>

using nlohmann::json;

struct Student
{
    std::string name;
    std::any group;
    std::any avg;
    std::any debt;
};

auto get_name(const json& _j) -> std::string;

auto get_debt(const json& _j) -> std::any;

auto get_avg(const json& _j) -> std::any;

auto get_group(const json& _j) -> std::any;

void from_json(const json& _j, Student& _st);

std::vector<Student> read_file(json data);
void print(const std::vector<Student>& _st, std::ostream& os);
void print(const Student& _st, std::ostream& os);

#endif // INCLUDE_STUDENT_HPP_
