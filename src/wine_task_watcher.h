#ifndef WINE_TASK_WATCHER_H
#define WINE_TASK_WATCHER_H

#include <QMainWindow>
#include <QThread>

class QDelay : public QThread{
public:
    static void msleep(unsigned long msecs)
    {
        QThread::msleep(msecs);
    }
    static void sleep(unsigned long secs)
    {
        QThread::sleep(secs);
    }
    static void usleep(unsigned long usecs)
    {
        QThread::usleep(usecs);
    }
};

namespace Ui {
class Wine_Task_Watcher;
}

class Wine_Task_Watcher : public QMainWindow
{
    Q_OBJECT

public:
    explicit Wine_Task_Watcher(QWidget *parent = nullptr);
    ~Wine_Task_Watcher();

private slots:
    void run();
    void check_EXE();
    void re_Check();
    void Start();
    void EXE_addItem(QString a);
    void on_Close_clicked();

private:
    Ui::Wine_Task_Watcher *ui;
};

#endif // Wine_Task_Watcher
