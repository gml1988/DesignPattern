#include "Decorator.h"
#include <iostream>

namespace DesignPattern
{
	void ConcreteComponentA::Operation()
	{
		std::cout<<"ConcreteComponentA::Operation()"<<std::endl;
	}

	void ConcreteComponentB::Operation()
	{
		std::cout<<"ConcreteComponentB::Operation()"<<std::endl;
	}

	void Decorator::Operation()
	{
		m_pComponent->Operation();
	}

	void ConcreteDecoratorOne::Operation()
	{
		Decorator::Operation();
		ExtraOperationOne();
	}

	void ConcreteDecoratorOne::ExtraOperationOne()
	{
		std::cout<<"ConcreteDecoratorOne::ExtraOperationOne()"<<std::endl;
	}

	void ConcreteDecoratorTwo::Operation()
	{
		Decorator::Operation();
		ExtraOperationTwo();
	}

	void ConcreteDecoratorTwo::ExtraOperationTwo()
	{
		std::cout<<"ConcreteDecoratorTwo::ExtraOperationTwo()"<<std::endl;
	}
}