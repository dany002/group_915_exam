//
// Created by moldo on 6/27/2022.
//

#ifndef GROUP_915_TEACHERREPO_H
#define GROUP_915_TEACHERREPO_H
#include <vector>
#include "../Domain/Teacher.h"

class TeacherRepo {
private:
    std::vector<Teacher> teachers;
public:
    TeacherRepo();
    ~TeacherRepo() {}
    void add_teacher(const Teacher& t);
    std::vector<Teacher> get_all();
    void read_file();
    void save_file();
};


#endif //GROUP_915_TEACHERREPO_H
