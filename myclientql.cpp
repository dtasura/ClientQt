#include "myclientql.h"
#include "ui_myclientql.h"

MyClientQl::MyClientQl(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyClientQl)
{
    ui->setupUi(this);
    clientSocket = new QTcpSocket(this);
    in.setDevice(clientSocket);
    connect(ui->btnClose, &QAbstractButton::clicked, this, &QWidget::close);
    connect(ui->btnConnect, &QAbstractButton::clicked, this, &MyClientQl::requestMessage);
    // escucha la respuesta del servidor a la request que se realizo.
    connect(clientSocket, &QIODevice::readyRead, this, &MyClientQl::readMessage);
    connect(clientSocket, &QIODevice::destroyed, this, &MyClientQl::closedCNX);
}

MyClientQl::~MyClientQl()
{
    delete ui;
}

void MyClientQl::requestMessage()
{
    qDebug() << "request message";
    QString ipAddress = ui->textIp->text();
    QString port = ui->textPort->text();
    clientSocket->connectToHost(ipAddress, port.toInt());
    qDebug() << "ip: " + ipAddress;
    qDebug() << "port: " + port;
}

void MyClientQl::readMessage()
{
    qDebug() << "readMessage ...";
    in.startTransaction();
    QString message;
    // divice a la izquierda >> string
    in >> message;
    if (!in.commitTransaction()) {
        qDebug() << "error in data stream";
        return;
    }
    ui->lblMessage->setText(message);
}

void MyClientQl::closedCNX()
{
    qDebug() << "closeCNX";
}

