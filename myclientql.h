#ifndef MYCLIENTQL_H
#define MYCLIENTQL_H

#include <QWidget>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class MyClientQl; }
QT_END_NAMESPACE

class MyClientQl : public QWidget
{
    Q_OBJECT

public:
    MyClientQl(QWidget *parent = nullptr);
    ~MyClientQl();

private slots:
    void requestMessage();
    void readMessage();
    void closedCNX();

private:
    Ui::MyClientQl *ui;
    QTcpSocket *clientSocket = nullptr;
    QDataStream in;
    QString receiveMessage;
};
#endif // MYCLIENTQL_H
