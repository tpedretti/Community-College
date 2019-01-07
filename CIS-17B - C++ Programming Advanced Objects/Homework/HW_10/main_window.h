#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QtGui/QMainWindow>

class QPushButton;
class QLineEdit;
class QLabel;

class main_window : public QMainWindow
{
    Q_OBJECT

public:
    main_window(QWidget *parent = 0);
    ~main_window();
private:
    QPushButton *button;
    QLineEdit *line_edit;
    QLabel *label;
};

#endif // MAIN_WINDOW_H
