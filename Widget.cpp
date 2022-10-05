#include "Widget.h"
#include <qtimer.h>
#include <qdebug.h>
#include "Worker.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    qDebug() << "Ui Thread : " << QThread::currentThread();

    thread = new QThread(this);

    /*
    thread = QThread::create([]() {

        QTimer* timer = new QTimer();

        //*********    Connecting slots   *********
        connect(timer, &QTimer::timeout, []() {
            qDebug() << "Time Out. Running in thread : " << QThread::currentThread();
        });

        timer->start(1000);    
    });

    connect(thread, &QThread::started, []() {
        qDebug() << "Thread started ID: " << QThread::currentThread();
    });

    connect(thread, &QThread::finished, []() {
        qDebug() << "Thread finished ID: " << QThread::currentThread();
    });

    

    thread->start();
    */

}

Widget::~Widget()
{
    delete thread;
}

void Widget::on_startButton_clicked()
{
    Worker* worker = new Worker();
    worker->moveToThread(thread);

    connect(thread, &QThread::started, worker, &Worker::doWork);
    connect(thread, &QThread::finished, [](){
        qDebug() << "Thread finished";
    });

    connect(thread, &QThread::finished, worker, &Worker::deleteLater);

    thread->start();
}

void Widget::on_stopButton_clicked()
{
    thread->exit();
}

void Widget::on_infoButton_clicked()
{
    qDebug() << "Thread running : " << thread->isRunning();
}
