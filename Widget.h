#pragma once

#include <QtWidgets/QWidget>
#include "ui_Widget.h"
#include "qthread.h"
#include "iostream"


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_startButton_clicked();

    void on_stopButton_clicked();

    void on_infoButton_clicked();

private:
    Ui::WidgetClass ui;
    QThread* thread;
};
