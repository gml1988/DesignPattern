#include "TCPState.h"
#include <iostream>

using DesignPattern::TCPState;
using DesignPattern::TCPClosed;
using DesignPattern::TCPEstablished;
using DesignPattern::TCPListen;
using DesignPattern::TCPConnection;

int main()
{
	TCPConnection * pConnection = new TCPConnection();
	pConnection->PassiveOpen();
	pConnection->ActiveOpen();
	pConnection->Send();
	pConnection->Synchronize();
	pConnection->Close();
	
	std::cin.get();
	return 0;
}