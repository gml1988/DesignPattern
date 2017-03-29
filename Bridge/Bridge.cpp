#include "Bridge.h"
#include <stdio.h>
#include <iostream>

namespace DesignPattern
{
	Abstraction::Abstraction( Implementor * pImp ) : m_pImplementor( pImp )
	{

	}

	Abstraction::~Abstraction()
	{
		if ( m_pImplementor != NULL )
		{
			delete m_pImplementor;
			m_pImplementor = NULL;
		}
	}

	Implementor * Abstraction::CreateConcreteImplementorA()
	{
		Implementor * pImp = new ConcreteImplementorA();
		return pImp;
	}

	Implementor * Abstraction::CreateConcreteImplementorB()
	{
		Implementor * pImp = new ConcreteImplementorB();
		return pImp;
	}

	void Abstraction::Operation()
	{
		m_pImplementor->OperationImp();
	}

	void ConcreteImplementorA::OperationImp()
	{
		std::cout<<"ConcreteImplementorA::OperationImp()"<<std::endl;
	}

	void ConcreteImplementorB::OperationImp()
	{
		std::cout<<"ConcreteImplementorB::OperationImp()"<<std::endl;
	}
}