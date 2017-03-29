#include "Visitor.h"
#include <iostream>

using DesignPattern::Element;
using DesignPattern::ConcreteElementA;
using DesignPattern::ConcreteElementB;
using DesignPattern::Visitor;
using DesignPattern::ConcreteVisitorOne;
using DesignPattern::ConcreteVisitorTwo;

int main()
{
	Element * pElementA = new ConcreteElementA();
	Element * pElementB = new ConcreteElementB();

	Visitor * pConcreteVisitorOne = new ConcreteVisitorOne();
	Visitor * pConcreteVisitorTwo = new ConcreteVisitorTwo();

	//一般都是客户端发起Accept操作，从而Visitor开始访问
	//主人先接受，客人才能访问O(∩_∩)O哈！
	pElementA->Accept( pConcreteVisitorOne );
	pElementA->Accept( pConcreteVisitorTwo );

	pElementB->Accept( pConcreteVisitorOne );
	pElementB->Accept( pConcreteVisitorTwo );

	std::cin.get();
	return 0;
}