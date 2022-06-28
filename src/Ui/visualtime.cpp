//
// Created by moldo on 6/28/2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_VisualTime.h" resolved

#include "visualtime.h"
#include "ui_VisualTime.h"
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>

VisualTime::VisualTime(Controller &control, QWidget *parent)
: QWidget(parent), control(control), ui(new Ui::VisualTime)
{
    ui->setupUi(this);
    QPieSeries* series = new QPieSeries();
    for(const auto& teacher : this->control.get_teachers()){
        int number_of_students = this->control.get_all_students_for_a_teacher(teacher.getName()).size();
        series->append(teacher.getName().c_str(), number_of_students);
    }
    QChart* chart = new QChart();
    chart->addSeries(series);

    QChartView* chartView = new QChartView(chart);
    chartView->setParent(ui->horizontalFrame);
}


VisualTime::~VisualTime() {
    delete ui;
}



