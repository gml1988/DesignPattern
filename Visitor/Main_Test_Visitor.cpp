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

	//һ�㶼�ǿͻ��˷���Accept�������Ӷ�Visitor��ʼ����
	//�����Ƚ��ܣ����˲��ܷ���O(��_��)O����
	pElementA->Accept( pConcreteVisitorOne );
	pElementA->Accept( pConcreteVisitorTwo );

	pElementB->Accept( pConcreteVisitorOne );
	pElementB->Accept( pConcreteVisitorTwo );

	std::cin.get();
	return 0;
}