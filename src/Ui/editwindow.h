//
// Created by moldo on 6/28/2022.
//

#ifndef GROUP_915_EDITWINDOW_H
#define GROUP_915_EDITWINDOW_H

#include <QWidget>
#include "../Controller/Controller.h"
#include "ui_EditWindow.h"


class EditWindow : public QWidget, public Observer {
Q_OBJECT

public:
    explicit EditWindow(Controller& control, Teacher& teacher,QWidget *parent = nullptr);

    ~EditWindow() override;

    virtual void update() override;
private:
    Ui::EditWindow *ui;
    Controller& control;
    Teacher& teacher;
    void connectSignalsAndSlots();
    void edit_title();
    void edit_email();
    int get_selected_index() const;


};


#endif //GROUP_915_EDITWINDOW_H
