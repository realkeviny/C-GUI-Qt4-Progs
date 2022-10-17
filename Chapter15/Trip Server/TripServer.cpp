#include <QtCore>
#include "ClientSocket.h"
#include "TripServer.h"

TripServer::TripServer(QObject* parent):QTcpServer(parent)
{
	
}

void TripServer::incomingConnection(int socketId)
{
	ClientSocket* socket = new ClientSocket(this);
	socket->setSocketDescriptor(socketId);
}

