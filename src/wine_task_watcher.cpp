/* Who does not know how to start WOW (Agent.exe) or
   Steam PC and after closing these or parts of this task are still active.

   This is of course annoying as they can take up a lot of system resources.

   That's why I wrote this little tool, it allows you to start an exe task
   with wine or wine64 and after finishing this task you can see if everything
   that requires CPU load is finished.

    Wine Task Watcher – Version 0.1
--> created 23.11.2018 by Marc-André Tragé

*/
#include "wine_task_watcher.h"
#include "ui_wine_task_watcher.h"
#include <QTextStream>
#include <QProcess>
#include <QDir>

//
static QString EXE_OK,
               EXE_ERROR,
               Wine,Wine_App_Path,
               Type,arg_A,arg_B,
               msg_A = "Wine 64 Bit",
               msg_B = "Wine 32 Bit",
               msg_C = "All Wine Tasks were successfully completed!",
               msg_D = "Is running now!";

//
void Wine_Task_Watcher::run(){
    system(qPrintable(Wine + " \'" + Wine_App_Path + "\'"));
}

//
void Wine_Task_Watcher::check_EXE(){
    QProcess         process;
                     process.start("pgrep -l .exe");
                     process.waitForFinished(-1);
    QString stdout = process.readAllStandardOutput(),
            stderr = process.readAllStandardError();
    EXE_OK         = stdout;
    EXE_ERROR      = stderr;
}

//
Wine_Task_Watcher::Wine_Task_Watcher(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Wine_Task_Watcher)
{
    ui->setupUi(this);
    QStringList arguments = qApp->arguments();

    arg_A = arguments.at(1).toUtf8();
    arg_B = arguments.at(2).toUtf8();

    Wine_App_Path = arg_B;

    if(arg_A=="64"){
        Type = msg_A;
        Wine = "wine64";
    }
    else{
        Type = msg_B;
        Wine = "wine";
    }
    this->setWindowTitle(Type + ": " + Wine_App_Path);
    Start();
}

//
void Wine_Task_Watcher::EXE_addItem(QString a){
    ui->EXE_Task->clear();
    qApp->processEvents();
    QTextStream ts(&a);
    QString line;
    do{
        line = ts.readLine();
        if(line!=""){
            ui->EXE_Task->addItem(line);
            qApp->processEvents();
        }
    }
    while (!line.isNull());
}

//
void Wine_Task_Watcher::re_Check(){
    show();
    raise();
    activateWindow();
    if(EXE_OK!=""){
        check_EXE();
        QDelay::msleep(100);
        EXE_addItem(EXE_OK);
        qApp->processEvents();
        re_Check();
    }
    else{
        QString info = msg_C;
        ui->EXE_Info->setText(info);
        EXE_addItem(EXE_OK);
        qApp->processEvents();
        ui->EXE_Info->setText(info);
        QDelay::msleep(250);
        EXE_addItem(EXE_OK);
    }
}

//
void Wine_Task_Watcher::Start(){
    ui->EXE_Info->setText(msg_D);
    qApp->processEvents();
    hide();
    run();
    QDelay::msleep(1000);
    check_EXE();
    qApp->processEvents();
    re_Check();
}

//
void Wine_Task_Watcher::on_Close_clicked(){
    qApp->exit();
}

//
Wine_Task_Watcher::~Wine_Task_Watcher(){
    delete ui;
}
