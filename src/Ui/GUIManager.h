//
// Created by moldo on 6/28/2022.
//

#ifndef GROUP_915_GUIMANAGER_H
#define GROUP_915_GUIMANAGER_H
#include "../Controller/Controller.h"

class GUIManager {
private:
    Controller& control;
public:
    GUIManager(Controller& control);
    ~GUIManager();
};


#endif //GROUP_915_GUIMANAGER_H
