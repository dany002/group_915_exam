//
// Created by moldo on 6/27/2022.
//

#ifndef GROUP_915_TEACHER_H
#define GROUP_915_TEACHER_H
#include <string>

class Teacher {
private:
    std::string name;

public:
    Teacher(const std::string &name);

    const std::string &getName() const;

    void setName(const std::string &name);
};


#endif //GROUP_915_TEACHER_H
