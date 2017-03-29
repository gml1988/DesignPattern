//Element�в�ͬ������ConcreteElementA��ConcreteElementB
//����Visitor�������ӿھ������ConcreteElementA��ConcreteElementB�ķ��ʽӿ�
//ֻ�ǲ�ͬ��Visitor�������ConcreteElementA��ConcreteElementB�ķ��ʿ����в�ͬ��ʵ��
//ȱ�㣺�����Ļ������Element����һ��ConcreteElement�����࣬
//��ô���е�Visitor�Լ������඼��Ҫ��Ӷ����¼����ConcreteElement�ķ��ʽӿ�
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
		//��Щ�����Operation�ǹ�Visitor���õģ�Ҫô�����е�Visitor������Ϊ��Ԫ��
		//Ҫô����ЩOperation����Ϊpublic
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
		//�������Visitor�˾���Ҫ֪��Element�˵����м̳й�ϵ����Ҫ�����еĶ�ӦElement����ķ��ʽӿ�
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