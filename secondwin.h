#ifndef SECONDWIN_H
#define SECONDWIN_H

#include <QDialog>

namespace Ui {
class secondwin;
}

class secondwin : public QDialog
{
    Q_OBJECT

public:
    explicit secondwin(QWidget *parent = nullptr);
    ~secondwin();

private slots:
    void logged();

private:
    Ui::secondwin *ui;
};

#endif // SECONDWIN_H
