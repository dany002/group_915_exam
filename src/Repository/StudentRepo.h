//
// Created by moldo on 6/27/2022.
//

#ifndef GROUP_915_STUDENTREPO_H
#define GROUP_915_STUDENTREPO_H
#include "../Domain/Student.h"
#include <vector>

class StudentRepo {
private:
    std::vector<Student> students;
public:
    StudentRepo();
    ~StudentRepo() {}
    void add_student(const Student& s);
    std::vector<Student> get_all();
    void update_coordinator(Student s, const std::string& new_name);
    void update_email(Student s, const std::string& new_mail);
    void update_title(Student s, const std::string& new_title);
    void read_file();
    std::vector<Student> get_all_students_for_a_teacher(const std::string& teacher_name);
    void save_file();
};


#endif //GROUP_915_STUDENTREPO_H
