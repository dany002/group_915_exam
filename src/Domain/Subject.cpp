//
// Created by moldo on 6/28/2022.
//

#include "Subject.h"

void Subject::notify() {
    for(auto it : this->observers)
        it->update();
}

void Subject::attachObserver(Observer *o) {
    this->observers.push_back(o);
}
