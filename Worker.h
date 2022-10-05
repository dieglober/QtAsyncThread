#pragma once
#include <qobject.h>

class Worker : public QObject
{
	Q_OBJECT
public:
	Worker(QObject* parent = nullptr);
	~Worker();

signals:

public slots:
	void doWork();

};

