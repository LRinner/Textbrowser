#include "gui.h"
#include<QtDebug>

Gui::Gui(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    connect(&m_scanner, &HttpClient::scanFinished, this, &Gui::showResult);

}

    void Gui::on_goButton_clicked()
    {
        QByteArray host=hostEntry->text().toUtf8();

        m_scanner.readyRead();

    }
    void Gui::showResult(QByteArray m_hostname, bool status)
    {
        qDebug() << m_hostname<<status;
        QString msg=(status==true)? "open":"closed";
        QString result=QString::number(status)+ "->"+msg;
        resultBrowser->append(result);



    }

