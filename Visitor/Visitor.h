//Element有不同的子类ConcreteElementA和ConcreteElementB
//对于Visitor的虚基类接口就有针对ConcreteElementA和ConcreteElementB的访问接口
//只是不同的Visitor子类对于ConcreteElementA和ConcreteElementB的访问可以有不同的实现
//缺点：这样的话，如果Element多了一个ConcreteElement的子类，
//那么所有的Visitor以及其子类都需要添加对于新加入的ConcreteElement的访问接口
#pragma once

namespace DesignPattern
{
	class Visitor;

	class Element
	{
	public:
		Element(){};
		virtual ~Element(){};
	public:
		virtual void Accept( Visitor * pVisit ) = 0;
	};

	class ConcreteElementA : public Element
	{
	public:
		ConcreteElementA(){};
		virtual ~ConcreteElementA(){};
	public:
		virtual void Accept( Visitor * pVisit );
		//这些具体的Operation是供Visitor调用的，要么将所有的Visitor都声明为友元类
		//要么将这些Operation声明为public
		void OperationA();
	};

	class ConcreteElementB : public Element
	{
	public:
		ConcreteElementB(){};
		virtual ~ConcreteElementB(){};
	public:
		virtual void Accept( Visitor * pVisit );
		void OperationB();
	};

	class Visitor
	{
	public:
		Visitor(){};
		virtual ~Visitor(){};
	public:
		//在虚基类Visitor端就需要知道Element端的所有继承关系，需要有所有的对应Element子类的访问接口
		virtual void VisitConcreteElementA( ConcreteElementA * pConcreteElementA ) = 0;
		virtual void VisitConcreteElementB( ConcreteElementB * pConcreteElementB ) = 0;
	};

	class ConcreteVisitorOne : public Visitor
	{
	public:
		ConcreteVisitorOne(){}
		virtual ~ConcreteVisitorOne(){};
	public:
		virtual void VisitConcreteElementA( ConcreteElementA * pConcreteElementA );
		virtual void VisitConcreteElementB( ConcreteElementB * pConcreteElementB ); 
	};

	class ConcreteVisitorTwo : public Visitor
	{
	public:
		ConcreteVisitorTwo(){};
		virtual ~ConcreteVisitorTwo(){};
	public:
		virtual void VisitConcreteElementA( ConcreteElementA * pConcreteElementA );
		virtual void VisitConcreteElementB( ConcreteElementB * pConcreteElementB );
	};
}