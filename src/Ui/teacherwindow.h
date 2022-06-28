//
// Created by moldo on 6/28/2022.
//

#ifndef GROUP_915_TEACHERWINDOW_H
#define GROUP_915_TEACHERWINDOW_H

#include <QWidget>
#include "../Controller/Controller.h"
#include "ui_TeacherWindow.h"

class TeacherWindow : public QWidget, public Observer {
Q_OBJECT

public:
    explicit TeacherWindow(Controller& control, const Teacher& teacher, QWidget *parent = nullptr);

    ~TeacherWindow() override;

    virtual void update() override;

private:
    Ui::TeacherWindow *ui;
    Controller& control;
    Teacher teacher;
    std::vector<Student> approved_students;

    void connectSignalsAndSlots();
    void filter_list();
    int get_selected_index() const;
    void add_button();
    void edit_time();
    void generate_file();
    void visual_time();
private slots:
    void itemClickedSlot(QListWidgetItem* itemClicked);
};


#endif //GROUP_915_TEACHERWINDOW_H
// 684