#include <QtGui/QApplication>
#include <QtGui>
#include "main_window.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget window;
    window.setFixedSize(320, 240);
    window.setWindowTitle(QApplication::translate("homework", "Homework 10"));
    window.show();

    QPushButton *button = new QPushButton(QApplication::translate("homework", "Don't PUSH!"), &window);
    button->move(20, 20);
    button->show();

    QPushButton *button2 = new QPushButton(QApplication::translate("homework", "Don't PUSH!"), &window);
    button2->move(220, 20);
    button2->show();

    QLineEdit *line = new QLineEdit(QApplication::translate("homework", "TEST"), &window);
    line->move(100, 120);
    line->show();

    QLabel *label = new QLabel(QApplication::translate("homework", "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"), &window);
    label->move(0, 225);
    label->show();

    return app.exec();
}
