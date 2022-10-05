#pragma once

#include <QThread>

class WorkerThread  : public QThread
{
	Q_OBJECT

public:
	WorkerThread(QObject *parent);
	~WorkerThread();
};
