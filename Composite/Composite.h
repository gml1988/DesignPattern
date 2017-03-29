//Abstract ClassΪComponent
//Leaf��Composite����̳�Component�ӿ�
//����Leafֻ��ʵ��Operation
//Composite��Ҫʵ��Component�����еĽӿ�
#pragma once	
#include <stdio.h>
#include <vector>

namespace DesignPattern
{
	class Component
	{
	public:
		Component(){};
		virtual ~Component(){};
	public:
		virtual void Operation(){};
		virtual void Add( Component * pComp ){};
		virtual void Remove( Component * pComp ){};
		virtual Component * GetChild( int index ){ return NULL; }
	};

	class Leaf : public Component
	{
	public:
		Leaf() : Component(){};
		virtual ~Leaf(){};
	public:
		//����Leaf�ڵ㣬ֻ��Ҫʵ��Operation�ӿھͿ�����
		virtual void Operation();
	};

	class Composite : public Component
	{
	public:
		Composite() : Component(){};
		virtual ~Composite(){};
	public:
		virtual void Operation();
		virtual void Add( Component * pComp );
		virtual void Remove( Component * pComp );
		virtual Component * GetChild( int index );
	private:
		std::vector<Component *> m_ComponentVector;
	};
}