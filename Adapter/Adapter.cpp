#include "Adapter.h"
#include <iostream>

namespace DesignPattern
{
	void Adaptee::SpecificRequest()
	{
		std::cout<<"Adaptee::SpecifcRequest"<<std::endl;
	}

	void InheritAdapter::Request()
	{
		Adaptee::SpecificRequest();
	}

	void AggregateAdapter::Request()
	{
		m_pAdaptee->SpecificRequest();
	}
}