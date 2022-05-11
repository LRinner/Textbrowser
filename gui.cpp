#include "gui.h"


Gui::Gui(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    connect(&m_scanner, &HttpClient::scanFinished, this, &Gui::showResult);

}

    void Gui::on_goButton_clicked()
    {
        QString host=hostEntry->text();

        m_scanner.readyRead();

    }
    void Gui::showResult(QString m_hostname)
    {

        resultBrowser->append(m_hostname);



    }

