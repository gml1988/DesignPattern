#include "Proxy.h"
#include <stdio.h>
#include <iostream>

namespace DesignPattern
{
	SubjectProxy::SubjectProxy()
	{
		m_pRealSubject = NULL;
	}

	SubjectProxy::~SubjectProxy()
	{
		delete m_pRealSubject;
		m_pRealSubject = NULL;
	}

	void SubjectProxy::Request()
	{
		if ( m_pRealSubject == NULL )
			m_pRealSubject = new RealSubject();
		m_pRealSubject->Request();
	}

	void RealSubject::Request()
	{
		std::cout<<"RealSubject::Request()"<<std::endl;
	}
}