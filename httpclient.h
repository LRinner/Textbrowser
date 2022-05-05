#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <QObject>
#include<QTcpSocket>

class HttpClient : public QObject
{
    Q_OBJECT
public:
    explicit HttpClient(int argc, char* argv[], QObject *parent = nullptr);


signals:
    void scanFinished(QByteArray m_hostname,bool status);

public slots:
       void connected();
          void readyRead();

private:
    QTcpSocket *m_socket;
    QByteArray m_hostname;
};

#endif // HTTPCLIENT_H
