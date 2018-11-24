#include "wine_task_watcher.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if(argc < 3){
        qInfo(qPrintable("\n\t2 parameters are required!\n"));
    }
    else{
        QString b = argv[1],
                c = argv[2],
                d = "\n\tApplication not exists!\n",
                e = "\n\tFirst parameter 32 or 64 bit?\n";
        if(b=="32" || b=="64"){
            QFile app(c);
            if(c == ""){
                qInfo(qPrintable(d));
            }
            else{
                if(app.exists()){
                    if(c.contains(".exe", Qt::CaseSensitive) || c.contains(".EXE", Qt::CaseSensitive) || c.contains(".Exe", Qt::CaseSensitive)){
                        Wine_Task_Watcher w;
                        w.show();
                        return a.exec();
                    }
                    else{
                        qInfo(qPrintable(d));
                    }
                }
                else {
                    qInfo(qPrintable(d));
                }
            }
        }
        else{
            qInfo(qPrintable(e));
        }
    }
}
