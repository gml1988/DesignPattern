#include "Strategy.h"
#include <iostream>

namespace DesignPattern
{
	void StrategyContext::ContextInterface()
	{
		m_pIStrategy->AlgorithmInterface( this );
	}

	void ConcreteStrategyA::AlgorithmInterface( StrategyContext * pStrategyContext )
	{
		std::cout<<"ConcreteStrategyA::AlgorithmInterface"<<std::endl;
	}

	void ConcreteStrategyB::AlgorithmInterface( StrategyContext * pStrategyContext )
	{
		std::cout<<"ConcreteStrategyB::AlgorithmInterface"<<std::endl;
	}
}