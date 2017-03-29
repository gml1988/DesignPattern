#include "Flyweight.h"

using DesignPattern::Flyweight;
using DesignPattern::ConcreteFlyweightA;
using DesignPattern::ConcreteFlyweightB;
using DesignPattern::ConcreteFlyweightC;
using DesignPattern::FlyweightFactory;

int main()
{
	FlyweightFactory * pFlyweightFactory = new FlyweightFactory();
	pFlyweightFactory->GetFlyWeight( "ConcreteFlyweightA" )->Operation();
	pFlyweightFactory->GetFlyWeight( "ConcreteFlyweightB" )->Operation();
	pFlyweightFactory->GetFlyWeight( "ConcreteFlyweightA" )->Operation();
	pFlyweightFactory->GetFlyWeight( "ConcreteFlyweightC" )->Operation();

	delete pFlyweightFactory;
	std::cin.get();
	return 0;
}