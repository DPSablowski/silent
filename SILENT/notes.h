#ifndef NOTES_H
#define NOTES_H

#include <QDialog>

namespace Ui {
class Notes;
}

class Notes : public QDialog
{
    Q_OBJECT

public:
    explicit Notes(QWidget *parent = 0);
    ~Notes();

private:
    Ui::Notes *ui;
};

#endif // NOTES_H
