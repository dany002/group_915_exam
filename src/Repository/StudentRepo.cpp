//
// Created by moldo on 6/27/2022.
//

#include "StudentRepo.h"
#include <iostream>
#include <fstream>

void StudentRepo::add_student(const Student &s) {
    this->students.push_back(s);
}

std::vector<Student> StudentRepo::get_all() {
    return this->students;
}

void StudentRepo::update_coordinator(Student s, const std::string &new_name) {
    for(auto& stud : this->students) {
        if (stud == s){
            s.setCoordinator(new_name);
            stud = s;
            break;
        }
    }
}

void StudentRepo::update_email(Student s, const std::string &new_mail) {
    for(auto& stud : this->students) {
        if (stud == s){
            s.setEmail(new_mail);
            stud = s;
            break;
        }
    }
}

void StudentRepo::update_title(Student s, const std::string &new_title) {
    for(auto& stud : this->students) {
        if (stud == s){
            s.setTitle(new_title);
            stud = s;
            break;
        }
    }
}

void StudentRepo::read_file() {
    std::ifstream file("students.in");
    std::string line;
    std::string id, name, email, year, title, coordinator;
    id = "";
    name = "";
    email = "";
    year = "";
    title = "";
    coordinator = "";
    if(file.is_open())
        while(std::getline(file, line)){
            int count = 0;
            int pos = 0;
            for (int i = 0; i < line.length(); i++) {
                if (line[i] == ',') {
                    if (count == 0)
                        for (int j = pos; j < i; j++)
                            id += line[j];
                    else if (count == 1)
                        for (int j = pos; j < i; j++)
                            name += line[j];
                    else if (count == 2)
                        for (int j = pos; j < i; j++)
                            email += line[j];
                    else if (count == 3)
                        for (int j = pos; j < i; j++)
                            year += line[j];
                    else if (count == 4)
                        for (int j = pos; j < i; j++)
                            title += line[j];
                    count++;
                    pos = i + 1;
                }
            }
            for (int j = pos; j < line.length(); j++)
                coordinator += line[j];
            this->add_student(Student(id, name, email, std::stoi(year), title, coordinator));
            id = "";
            name = "";
            email = "";
            year = "";
            title = "";
            coordinator = "";
        }
    file.close();
}

StudentRepo::StudentRepo() {
    this->read_file();
}

std::vector<Student> StudentRepo::get_all_students_for_a_teacher(const std::string& teacher_name) {
    std::vector<Student> help;
    for(const auto& i : this->students)
        if(i.getCoordinator() == teacher_name)
            help.push_back(i);
    return help;
}

void StudentRepo::save_file() {
    std::ofstream fout("students.in");
    for(const auto& i : this->students)
        fout << i.getId() << "," << i.getName() << "," << i.getEmail() << "," << i.getYear() << "," << i.getTitle() << "," << i.getCoordinator() << '\n';
    fout.close();
}
