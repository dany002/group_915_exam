//
// Created by moldo on 6/28/2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_EditWindow.h" resolved

#include <QMessageBox>
#include "editwindow.h"
#include "ui_EditWindow.h"


EditWindow::~EditWindow() {
    delete ui;
}

EditWindow::EditWindow(Controller &control, Teacher &teacher, QWidget *parent):
        QWidget(parent), control(control), teacher(teacher), ui(new Ui::EditWindow)
{
    ui->setupUi(this);
    this->connectSignalsAndSlots();
    this->update();
}

void EditWindow::connectSignalsAndSlots() {
    QObject::connect(this->ui->update_emailButton, &QPushButton::clicked, this, &EditWindow::edit_email);
    QObject::connect(this->ui->update_titleButton, &QPushButton::clicked, this, &EditWindow::edit_title);

}

void EditWindow::edit_title() {
    int selected_index = this->get_selected_index();
    if(selected_index < 0){
        QMessageBox::critical(this, "Error", "No student was selected");
        return;
    }
    std::vector<Student> coordinated_students = this->control.get_all_students_for_a_teacher(this->teacher.getName());
    std::sort(coordinated_students.begin(), coordinated_students.end(), [&](const Student& a, const Student& b){ return a.getYear() > b.getYear();});
    std::vector<Student> help;
    for(auto &s : coordinated_students)
        if(s.getYear() == 2022)
            help.push_back(s);
    for(auto &s : coordinated_students){
        if(s.getYear() == 2022)
            break;
        else
            help.push_back(s);
    }
    Student s = help[selected_index];
    this->control.update_title(s, this->ui->title_lineEdit->text().toStdString());
}

void EditWindow::edit_email() {
    int selected_index = this->get_selected_index();
    if(selected_index < 0){
        QMessageBox::critical(this, "Error", "No student was selected");
        return;
    }
    std::vector<Student> coordinated_students = this->control.get_all_students_for_a_teacher(this->teacher.getName());
    std::sort(coordinated_students.begin(), coordinated_students.end(), [&](const Student& a, const Student& b){ return a.getYear() > b.getYear();});
    std::vector<Student> help;
    for(auto &s : coordinated_students)
        if(s.getYear() == 2022)
            help.push_back(s);
    for(auto &s : coordinated_students){
        if(s.getYear() == 2022)
            break;
        else
            help.push_back(s);
    }
    Student s = help[selected_index];
    this->control.update_email(s, this->ui->email_lineEdit->text().toStdString());
}

void EditWindow::update() {
    this->ui->listWidget->clear();
    std::vector<Student> coordinated_students = this->control.get_all_students_for_a_teacher(this->teacher.getName());
    std::sort(coordinated_students.begin(), coordinated_students.end(), [&](const Student& a, const Student& b){ return a.getYear() > b.getYear();});
    std::vector<Student> help;
    for(auto &s : coordinated_students)
        if(s.getYear() == 2022)
            help.push_back(s);
    for(auto &s : coordinated_students){
        if(s.getYear() == 2022)
            break;
        else
            help.push_back(s);
    }
    for(auto &s: help)
        this->ui->listWidget->addItem(QString::fromStdString(s.toString()));
}


int EditWindow::get_selected_index() const {
    QModelIndexList selected_indexes = this->ui->listWidget->selectionModel()->selectedIndexes();
    if(selected_indexes.empty()){
        return -1;
    }
    int selected_index = selected_indexes.at(0).row();
    return selected_index;
}
