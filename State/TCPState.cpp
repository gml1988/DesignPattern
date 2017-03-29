#include "TCPState.h"
#include <iostream>

namespace DesignPattern
{
	TCPConnection::TCPConnection()
	{
		ChangeState( TCPClosed::Instance() );
	};

	TCPConnection::~TCPConnection()
	{

	}

	//TCPConnection的操作全部为委托为TCPState去做
	void TCPConnection::ActiveOpen() { m_pState->ActiveOpen( this ); }

	void TCPConnection::PassiveOpen(){ m_pState->PassiveOpen( this ); }

	void TCPConnection::Send(){ m_pState->Send( this ); }

	void TCPConnection::Close(){ m_pState->Close( this ); }

	void TCPConnection::Synchronize(){ m_pState->Synchronize( this ); }

	void TCPConnection::ChangeState(DesignPattern::TCPState *pState)
	{
		if ( pState == TCPClosed::Instance() )
			std::cout<<"Change to TCPClosed"<<std::endl;
		else if( pState == TCPEstablished::Instance() )
			std::cout<<"Change to TCPEstablished"<<std::endl;
		else if( pState == TCPListen::Instance() )
			std::cout<<"Change to TCPListen"<<std::endl;
		else
			std::cout<<"Non recognizable TCPState"<<std::endl;

		//由于State使用的是Singleton类，所以在此不需要进行TCPState内存的释放Delete
		m_pState = pState;
	}

	TCPState * TCPClosed::m_pInstance = NULL;
	TCPState * TCPClosed::Instance()
	{
		if ( m_pInstance == NULL )
			m_pInstance = new TCPClosed();
		return m_pInstance;
	}

	TCPState * TCPListen::m_pInstance = NULL;
	TCPState * TCPListen::Instance()
	{
		if ( m_pInstance == NULL )
			m_pInstance = new TCPListen();
		return m_pInstance;
	}

	TCPState * TCPEstablished::m_pInstance = NULL;
	TCPState * TCPEstablished::Instance()
	{
		if ( m_pInstance == NULL )
			m_pInstance = new TCPEstablished();
		return m_pInstance;
	}

	void TCPState::ChangeState(TCPConnection * pConnection, TCPState * pState )
	{
		pConnection->ChangeState( pState );
	}

	void TCPClosed::ActiveOpen( TCPConnection *pConnection )
	{
		ChangeState( pConnection, TCPEstablished::Instance() );
	}

	void TCPClosed::PassiveOpen( TCPConnection * pConnection )
	{
		ChangeState( pConnection, TCPListen::Instance() );
	}

	void TCPEstablished::Transmit( TCPConnection * pConnection )
	{
		std::cout<<"TCPConnection begin to transmit."<<std::endl;
	}

	void TCPEstablished::Close( TCPConnection * pConnection )
	{
		ChangeState( pConnection, TCPClosed::Instance() );
	}
	
	void TCPListen::Send( TCPConnection * pConnection )
	{
		ChangeState( pConnection, TCPEstablished::Instance() );
	}
}