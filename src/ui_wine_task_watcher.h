/********************************************************************************
** Form generated from reading UI file 'wine_task_watcher.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINE_TASK_WATCHER_H
#define UI_WINE_TASK_WATCHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Wine_Task_Watcher
{
public:
    QWidget *centralWidget;
    QPushButton *Close;
    QListWidget *EXE_Task;
    QTextEdit *EXE_Info;

    void setupUi(QMainWindow *Wine_Task_Watcher)
    {
        if (Wine_Task_Watcher->objectName().isEmpty())
            Wine_Task_Watcher->setObjectName(QStringLiteral("Wine_Task_Watcher"));
        Wine_Task_Watcher->resize(526, 266);
        centralWidget = new QWidget(Wine_Task_Watcher);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Close = new QPushButton(centralWidget);
        Close->setObjectName(QStringLiteral("Close"));
        Close->setGeometry(QRect(13, 220, 500, 36));
        EXE_Task = new QListWidget(centralWidget);
        EXE_Task->setObjectName(QStringLiteral("EXE_Task"));
        EXE_Task->setGeometry(QRect(13, 50, 500, 160));
        EXE_Task->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        EXE_Info = new QTextEdit(centralWidget);
        EXE_Info->setObjectName(QStringLiteral("EXE_Info"));
        EXE_Info->setEnabled(true);
        EXE_Info->setGeometry(QRect(13, 13, 500, 30));
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        EXE_Info->setFont(font);
        EXE_Info->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        EXE_Info->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        EXE_Info->setReadOnly(true);
        Wine_Task_Watcher->setCentralWidget(centralWidget);

        retranslateUi(Wine_Task_Watcher);

        QMetaObject::connectSlotsByName(Wine_Task_Watcher);
    } // setupUi

    void retranslateUi(QMainWindow *Wine_Task_Watcher)
    {
        Wine_Task_Watcher->setWindowTitle(QApplication::translate("Wine_Task_Watcher", "Wine_Task_Watcher", nullptr));
        Close->setText(QApplication::translate("Wine_Task_Watcher", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Wine_Task_Watcher: public Ui_Wine_Task_Watcher {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINE_TASK_WATCHER_H
