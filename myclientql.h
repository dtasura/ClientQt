#ifndef MYCLIENTQL_H
#define MYCLIENTQL_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MyClientQl; }
QT_END_NAMESPACE

class MyClientQl : public QWidget
{
    Q_OBJECT

public:
    MyClientQl(QWidget *parent = nullptr);
    ~MyClientQl();

private:
    Ui::MyClientQl *ui;
};
#endif // MYCLIENTQL_H
