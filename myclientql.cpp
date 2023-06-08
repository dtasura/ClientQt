#include "myclientql.h"
#include "ui_myclientql.h"

MyClientQl::MyClientQl(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyClientQl)
{
    ui->setupUi(this);
}

MyClientQl::~MyClientQl()
{
    delete ui;
}

