//
// Created by moldo on 6/27/2022.
//

#ifndef GROUP_915_CONTROLLER_H
#define GROUP_915_CONTROLLER_H
#include "../Repository/StudentRepo.h"
#include "../Repository/TeacherRepo.h"
#include "../Domain/Subject.h"

class Controller : public Subject{
private:
    StudentRepo studentRepo;
    TeacherRepo teacherRepo;
public:
    Controller(const StudentRepo& studRepo, const TeacherRepo& teachrepo);
    ~Controller();
    void add_teacher(const Teacher& t);
    void add_student(const Student& s);
    void update_email(Student s, const std::string& email);
    void update_coordinator(Student s, const std::string& coordinator);
    void update_title(Student s, const std::string& title);
    std::vector<Student> get_students();
    std::vector<Teacher> get_teachers();
    std::vector<Student> get_all_students_for_a_teacher(const std::string& name);
    void save_file();
};


#endif //GROUP_915_CONTROLLER_H
