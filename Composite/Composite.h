//Abstract Class为Component
//Leaf和Composite都会继承Component接口
//但是Leaf只会实现Operation
//Composite需要实现Component中所有的接口
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
		//对于Leaf节点，只需要实现Operation接口就可以了
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