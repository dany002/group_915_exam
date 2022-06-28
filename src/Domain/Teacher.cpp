//
// Created by moldo on 6/27/2022.
//

#include "Teacher.h"

Teacher::Teacher(const std::string &name) : name(name) {}

const std::string &Teacher::getName() const {
    return name;
}

void Teacher::setName(const std::string &name) {
    Teacher::name = name;
}
