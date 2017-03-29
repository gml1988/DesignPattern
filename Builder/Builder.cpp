#include "Builder.h"

namespace DesignPattern
{
	//Director负责进行策划进行生产的顺序，组装的流程
	void Director::ConstructProductOne( Builder * pBuilder )
	{
		pBuilder->BuildProduct();
		pBuilder->BuildPartA();
		pBuilder->BuildPartB();
		pBuilder->BuildPartC();
	}

	//不同的Construct可以有不同的组装流程，可以有一些Part不对Product进行配置
	//或者对多添加一些修饰及额外的操作，或者设定的属性值可以不一样
	void Director::ConstructProductTwo( Builder * pBuilder )
	{
		pBuilder->BuildProduct();
		pBuilder->BuildPartB();
		pBuilder->BuildPartB();
	}

	void ConcreteBuilderA::BuildProduct()
	{
		m_pProduct = new Product();
	}

	//不同的ConcreteBuilder的生产部件的具体实现方式不一样,
	//有可能是生成一个部件继承树中不同的子类的实例
	void ConcreteBuilderA::BuildPartA()
	{
		m_pProduct->AddPartA( 1 );
	}

	void ConcreteBuilderA::BuildPartB()
	{
		m_pProduct->AddPartB( "PartA" );
	}

	void ConcreteBuilderA::BuildPartC()
	{
		m_pProduct->AddPartC( 1.5 );
	}

	void ConcreteBuilderB::BuildProduct()
	{
		m_pProduct = new Product();
	}

	void ConcreteBuilderB::BuildPartA()
	{
		m_pProduct->AddPartA( 2 );
	}

	void ConcreteBuilderB::BuildPartB()
	{
		m_pProduct->AddPartB( "PartB" );
	}

	void ConcreteBuilderB::BuildPartC()
	{
		m_pProduct->AddPartC( 2.5 );
	}
}