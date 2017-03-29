#include "Visitor.h"
#include <iostream>

namespace DesignPattern
{
	void ConcreteElementA::Accept(DesignPattern::Visitor *pVisit)
	{
		std::cout<<"ConcreteElementA::Accept"<<std::endl;
		pVisit->VisitConcreteElementA( this );
	}

	void ConcreteElementA::OperationA()
	{
		std::cout<<"ConcreteElementA::OperationA"<<std::endl;
	}

	void ConcreteElementB::Accept( Visitor * pVisit )
	{
		std::cout<<"ConcreteElementB::Accept"<<std::endl;
		pVisit->VisitConcreteElementB( this );
	}

	void ConcreteElementB::OperationB()
	{
		std::cout<<"ConcreteElementB::OperationB()"<<std::endl;
	}

	//不同的ConcreteVisitor对于不同的ConcreteElement有不同的实现方式
	void ConcreteVisitorOne::VisitConcreteElementA( ConcreteElementA * pConcreteElementA )
	{
		std::cout<<"ConcreteVisitorOne::VisitConcreteElementA()"<<std::endl;
		pConcreteElementA->OperationA();
		pConcreteElementA->OperationA();
	}

	void ConcreteVisitorOne::VisitConcreteElementB(ConcreteElementB *pConcreteElementB)
	{
		std::cout<<"ConcreteVisitorOne::VisitConcreteElementB()"<<std::endl;
		pConcreteElementB->OperationB();
		pConcreteElementB->OperationB();
	}

	void ConcreteVisitorTwo::VisitConcreteElementA(ConcreteElementA * pConcreteElementA )
	{
		std::cout<<"ConcreteVisitorTwo::VisitConcreteElementA()"<<std::endl;
		pConcreteElementA->OperationA();
	}

	void ConcreteVisitorTwo::VisitConcreteElementB(ConcreteElementB * pConcreteElementB )
	{
		std::cout<<"ConcreteVisitorTwo::VisitConcreteElementB()"<<std::endl;
		pConcreteElementB->OperationB();
	}
}