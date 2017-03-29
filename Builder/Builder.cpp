#include "Builder.h"

namespace DesignPattern
{
	//Director������в߻�����������˳����װ������
	void Director::ConstructProductOne( Builder * pBuilder )
	{
		pBuilder->BuildProduct();
		pBuilder->BuildPartA();
		pBuilder->BuildPartB();
		pBuilder->BuildPartC();
	}

	//��ͬ��Construct�����в�ͬ����װ���̣�������һЩPart����Product��������
	//���߶Զ����һЩ���μ�����Ĳ����������趨������ֵ���Բ�һ��
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

	//��ͬ��ConcreteBuilder�����������ľ���ʵ�ַ�ʽ��һ��,
	//�п���������һ�������̳����в�ͬ�������ʵ��
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