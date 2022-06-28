//
// Created by moldo on 6/28/2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_TeacherWindow.h" resolved

#include "teacherwindow.h"
#include "ui_TeacherWindow.h"
#include <iostream>
#include <QMessageBox>
#include "editwindow.h"
#include <fstream>
#include "visualtime.h"

TeacherWindow::TeacherWindow(Controller &control, const Teacher &teacher, QWidget *parent) :
        QWidget(parent), control(control), teacher(teacher), ui(new Ui::TeacherWindow){
    ui->setupUi(this);
    this->connectSignalsAndSlots();
    this->setWindowTitle(QString::fromStdString(teacher.getName()));
    this->update();
}


TeacherWindow::~TeacherWindow() {
    delete ui;
}

void TeacherWindow::connectSignalsAndSlots() {
    this->ui->addButton->setEnabled(false);
    QObject::connect(this->ui->search_lineEdit, &QLineEdit::textChanged, this, &TeacherWindow::filter_list);
    QObject::connect(this->ui->addButton, &QPushButton::clicked, this, &TeacherWindow::add_button);
    QObject::connect(this->ui->all_students_listWidget, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(itemClickedSlot(QListWidgetItem *)));
    QObject::connect(this->ui->editButton, &QPushButton::clicked, this, &TeacherWindow::edit_time);
    QObject::connect(this->ui->generate_fileButton, &QPushButton::clicked, this, &TeacherWindow::generate_file);
    QObject::connect(this->ui->visualButton, &QPushButton::clicked, this, &TeacherWindow::visual_time);
}

void TeacherWindow::update() {
    this->ui->coordinated_students_listWidget->clear();
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
    for(auto &s: help){
        auto it = std::find(this->approved_students.begin(), this->approved_students.end(), s);
        if(it != this->approved_students.end()){
            std::string etc = s.toString();
            auto i = new QListWidgetItem(QString::fromStdString(etc));
            i->setBackground(QColor(0,255,0));
            this->ui->coordinated_students_listWidget->addItem(i);
        }
        else
            this->ui->coordinated_students_listWidget->addItem(QString::fromStdString(s.toString()));
    }

}

void TeacherWindow::filter_list() {
    this->ui->all_students_listWidget->clear();
    std::vector<Student> all_students = this->control.get_students();
    std::string partial_name = this->ui->search_lineEdit->text().toStdString();
    std::vector<Student> help_list;
    for(auto &s : all_students)
        if(strstr(s.getName().c_str(),partial_name.c_str()))
            help_list.push_back(s);
    for(auto &s : help_list)
        this->ui->all_students_listWidget->addItem(QString::fromStdString(s.toString()));
}

int TeacherWindow::get_selected_index() const {
    QModelIndexList selected_indexes = this->ui->all_students_listWidget->selectionModel()->selectedIndexes();
    if(selected_indexes.empty()){
        return -1;
    }
    int selected_index = selected_indexes.at(0).row();
    return selected_index;
}

void TeacherWindow::itemClickedSlot(QListWidgetItem *itemClicked) {
    int selected_index = this->get_selected_index();
    if (selected_index == -1){
        this->ui->addButton->setEnabled(false);
        return;
    }
    this->ui->addButton->setEnabled(true);
}

void TeacherWindow::add_button() {
    int selected_index = this->get_selected_index();

    std::vector<Student> all_students = this->control.get_students();
    std::string partial_name = this->ui->search_lineEdit->text().toStdString();
    std::vector<Student> help_list;
    for(auto &s : all_students)
        if(strstr(s.getName().c_str(),partial_name.c_str()))
            help_list.push_back(s);

    Student s = help_list[selected_index];
    if(!s.getCoordinator().empty()){
        QMessageBox::critical(this, "Error", "The selected student has already a coordinator!");
        this->ui->addButton->setEnabled(false);
        return;
    }
    this->control.update_coordinator(s, this->teacher.getName());
    this->ui->addButton->setEnabled(false);
    this->filter_list();
}

void TeacherWindow::edit_time() {
    auto* edit_window = new EditWindow(control, teacher);
    control.attachObserver(edit_window);
    edit_window->show();
}

void TeacherWindow::generate_file() {

    QModelIndexList selected_indexes = this->ui->coordinated_students_listWidget->selectionModel()->selectedIndexes();
    if(selected_indexes.empty()){
        QMessageBox::critical(this, "Error", "No student was selected!");
        return;
    }
    int selected_index = selected_indexes.at(0).row();

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
    if(s.getTitle() == "No title"){
        QMessageBox::critical(this, "Error", "Student has no title!");
        return;
    }
    std::string file_name = s.getName();
    file_name += ".txt";
    std::ofstream fout(file_name);
    fout << teacher.getName() << " approves the thesis " << s.getTitle() << " authored by " << s.getName() << ".";
    this->approved_students.push_back(s);
    fout.close();
    this->update();
}

void TeacherWindow::visual_time() {
    //auto* visual = new VisualTime(control);
    //visual->show();
}
