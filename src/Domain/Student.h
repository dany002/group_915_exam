//
// Created by moldo on 6/27/2022.
//

#ifndef GROUP_915_STUDENT_H
#define GROUP_915_STUDENT_H
#include <string>

class Student {
private:
    std::string id, name, email;
    int year;
    std::string title, coordinator;
public:
    Student(const std::string &id, const std::string &name, const std::string &email, int year,
            const std::string &title, const std::string &coordinator);

    const std::string &getId() const;

    void setId(const std::string &id);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getEmail() const;

    void setEmail(const std::string &email);

    int getYear() const;

    void setYear(int year);

    const std::string &getTitle() const;

    void setTitle(const std::string &title);

    const std::string &getCoordinator() const;

    void setCoordinator(const std::string &coordinator);

    bool operator==(const Student &rhs) const;

    bool operator!=(const Student &rhs) const;

    std::string toString() const;
};


#endif //GROUP_915_STUDENT_H
