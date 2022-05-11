#include "httpclient.h"
#include<QDebug>
#include<QCoreApplication>


HttpClient::HttpClient(QObject *parent) : QObject(parent)
{


       // Signal ->  Slot-Verbindung
       connect(m_socket, &QTcpSocket::connected, this, &HttpClient::connected);
       connect(m_socket, &QTcpSocket::readyRead, this, &HttpClient::readyRead);
}

void HttpClient::HTTP(QString& host)
{
       m_socket->connectToHost(host, port); // TCP Connect
       if (!m_socket->waitForConnected(5000)) {

           m_socket-> disconnectFromHost();
           m_notification="Konnte keine Verbindung aufbauen";
           emit scanFinished(m_notification);
       }


}
void HttpClient::connected()
{
    // normgerechter HTTP Request zum Server
    m_socket->write("GET / HTTP/1.1\r\nHost:" + m_hostname + "\r\n\r\n");
}

void HttpClient::readyRead()
{
    // HTTP-Antwort vom Server

    m_notification=m_socket->readAll();
    emit scanFinished(m_notification);
    m_socket->disconnectFromHost();
}

