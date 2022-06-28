//
// Created by moldo on 6/27/2022.
//

#include "Controller.h"

Controller::Controller(const StudentRepo &studRepo, const TeacherRepo &teachrepo)
{
    this->studentRepo = studRepo;
    this->teacherRepo = teachrepo;
}

Controller::~Controller() {

}

void Controller::add_teacher(const Teacher &t) {
    this->teacherRepo.add_teacher(t);
    this->notify();
}

void Controller::add_student(const Student &s) {
    this->studentRepo.add_student(s);
    this->notify();
}

void Controller::update_email(Student s, const std::string& email) {
    this->studentRepo.update_email(s, email);
    this->notify();
}

void Controller::update_coordinator(Student s, const std::string& coordinator) {
    this->studentRepo.update_coordinator(s, coordinator);
    this->notify();
}

void Controller::update_title(Student s, const std::string& title) {
    this->studentRepo.update_title(s, title);
    this->notify();
}

std::vector<Student> Controller::get_students() {
    return this->studentRepo.get_all();
}

std::vector<Teacher> Controller::get_teachers() {
    return this->teacherRepo.get_all();
}

std::vector<Student> Controller::get_all_students_for_a_teacher(const std::string& name) {
    return this->studentRepo.get_all_students_for_a_teacher(name);
}

void Controller::save_file() {
    studentRepo.save_file();
    teacherRepo.save_file();
}
