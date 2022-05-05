#ifndef GUI_H
#define GUI_H

#include "ui_gui.h"
#include "httpclient.h"

class Gui : public QWidget, private Ui::Gui
{
    Q_OBJECT

public:
    explicit Gui(QWidget *parent = nullptr);
private slots:
    void on_goButton_clicked();   //from GUI-Widget
    void showResult(QByteArray m_hostname, bool status);

private:
    HttpClient m_scanner;

};

#endif // GUI_H
