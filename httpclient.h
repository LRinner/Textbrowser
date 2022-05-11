#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <QObject>
#include <QAbstractSocket>
#include <QCoreApplication>
#include<QTcpSocket>

const int timeout=5000;
const int port=80;
class HttpClient : public QObject
{
    Q_OBJECT
public:
    explicit HttpClient(QObject *parent = nullptr);
    void connected();
       void readyRead();
       void HTTP(QString& host);

signals:
    void scanFinished(QString Notification);

public slots:


private:
    QTcpSocket *m_socket;
    QByteArray m_hostname;
    QString m_notification;
};

#endif // HTTPCLIENT_H
