#ifndef WARNING1_H
#define WARNING1_H

#include <QDialog>

namespace Ui {
class Warning1;
}

class Warning1 : public QDialog
{
    Q_OBJECT

public:
    explicit Warning1(QWidget *parent = 0);
    ~Warning1();

private:
    Ui::Warning1 *ui;
};

#endif // WARNING1_H
