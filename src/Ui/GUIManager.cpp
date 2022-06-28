//
// Created by moldo on 6/28/2022.
//

#include "GUIManager.h"
#include "../Ui/teacherwindow.h"

GUIManager::GUIManager(Controller &control): control{control} {
    std::vector<Teacher> teachers = control.get_teachers();
    for(const auto& it: teachers){
        auto* teacher_window = new TeacherWindow(control, it);
        control.attachObserver(teacher_window);
        teacher_window->show();
    }
}

GUIManager::~GUIManager() {
    this->control.save_file();
}
