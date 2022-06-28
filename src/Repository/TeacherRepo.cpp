//
// Created by moldo on 6/27/2022.
//

#include "TeacherRepo.h"
#include <iostream>
#include <fstream>


void TeacherRepo::add_teacher(const Teacher &t) {
    this->teachers.push_back(t);
}

std::vector<Teacher> TeacherRepo::get_all() {
    return this->teachers;
}

void TeacherRepo::read_file() {
    std::ifstream fin("teachers.in");
    std::string name;
    while(fin >> name)
        this->add_teacher(Teacher(name));
    fin.close();
}

TeacherRepo::TeacherRepo() {
    this->read_file();
}

void TeacherRepo::save_file() {
    std::ofstream fout("teachers.in");
    for(const auto& i : teachers)
        fout << i.getName() << std::endl;
    fout.close();
}
