#include "Worker.h"
#include <qtimer.h>
#include <qdebug.h>
#include <qthread.h>

Worker::Worker(QObject* parent) : QObject(parent)
{
}

Worker::~Worker()
{
	qDebug() << "Worker destroyed Thread ID: " << QThread::currentThread();
}
void Worker::doWork() {
	QTimer* timer = new QTimer();
	connect(timer, &QTimer::timeout,[]() {
		qDebug() << "Time out. Thread ID: " << QThread::currentThread();
	});

	timer->setInterval(1000);
	timer->start();
}