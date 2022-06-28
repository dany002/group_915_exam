//
// Created by moldo on 6/28/2022.
//

#ifndef GROUP_915_VISUALTIME_H
#define GROUP_915_VISUALTIME_H

#include <QWidget>
#include "../Controller/Controller.h"
#include "ui_VisualTime.h"


class VisualTime : public QWidget {
Q_OBJECT

public:
    explicit VisualTime(Controller& control, QWidget *parent = nullptr);

    ~VisualTime() override;

private:
    Ui::VisualTime *ui;
    Controller& control;
};


#endif //GROUP_915_VISUALTIME_H
