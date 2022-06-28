//
// Created by moldo on 6/27/2022.
//

#include "Student.h"

Student::Student(const std::string &id, const std::string &name, const std::string &email, int year,
                 const std::string &title, const std::string &coordinator) : id(id), name(name), email(email),
                                                                             year(year), title(title),
                                                                             coordinator(coordinator) {}

const std::string &Student::getId() const {
    return id;
}

void Student::setId(const std::string &id) {
    Student::id = id;
}

const std::string &Student::getName() const {
    return name;
}

void Student::setName(const std::string &name) {
    Student::name = name;
}

const std::string &Student::getEmail() const {
    return email;
}

void Student::setEmail(const std::string &email) {
    Student::email = email;
}

int Student::getYear() const {
    return year;
}

void Student::setYear(int year) {
    Student::year = year;
}

const std::string &Student::getTitle() const {
    return title;
}

void Student::setTitle(const std::string &title) {
    Student::title = title;
}

const std::string &Student::getCoordinator() const {
    return coordinator;
}

void Student::setCoordinator(const std::string &coordinator) {
    Student::coordinator = coordinator;
}

bool Student::operator==(const Student &rhs) const {
    return id == rhs.id &&
           name == rhs.name &&
           email == rhs.email &&
           year == rhs.year &&
           title == rhs.title &&
           coordinator == rhs.coordinator;
}

bool Student::operator!=(const Student &rhs) const {
    return !(rhs == *this);
}

std::string Student::toString() const {
    return id + " - " + name + " - " + email + " - " + std::to_string(year) + " - " + title + " - " + coordinator + '\n';
}
