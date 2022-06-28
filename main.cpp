#include <QApplication>
#include <QPushButton>
#include "src/Repository/StudentRepo.h"
#include "src/Repository/TeacherRepo.h"
#include "src/Controller/Controller.h"
#include "src/Ui/GUIManager.h"
#include <iostream>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    StudentRepo stud;
    TeacherRepo teac;
    Controller control(stud, teac);
    GUIManager gui(control);

    return a.exec();
}
