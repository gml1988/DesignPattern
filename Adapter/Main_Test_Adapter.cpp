#include "Adapter.h"
#include <iostream>

using DesignPattern::Target;
using DesignPattern::Adaptee;
using DesignPattern::InheritAdapter;
using DesignPattern::AggregateAdapter;

int main()
{
	Target * pAggregateAdapter = new AggregateAdapter( new Adaptee() );
	Target * pInheritAdapter = new InheritAdapter();

	pAggregateAdapter->Request();
	pInheritAdapter->Request();

	std::cin.get();
	return 0;
}