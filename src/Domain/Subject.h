//
// Created by moldo on 6/28/2022.
//

#ifndef GROUP_915_SUBJECT_H
#define GROUP_915_SUBJECT_H

#include "../Domain/Observer.h"
#include <vector>

class Subject {
private:
    std::vector<Observer*> observers;
public:
    void notify();
    void attachObserver(Observer* o);
};


#endif //GROUP_915_SUBJECT_H
