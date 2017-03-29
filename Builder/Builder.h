//Builder��Bridge�����ƣ������ǰѹ���Ĺ��������ⲿ��Builder�������
//����ʵ��ʹ��Director������������װ�����Ĺ���,������ÿ�����岿���Ĵ�����
//Builder���Ƕ�������������Ľӿڣ�����Ĵ�����������ConcreteBuilder��ʵ�֡�
//��ͬ��Builder�������Ĳ�����ͬ��������װ�Ĺ�������ͬ��

//Director�൱�ڰ���ͷ�����������ʦ��������װ��������˳������
//Builder���������ض��ĸ��ֲ����ľ������ͣ�ÿһ�ֲ������Ͷ���һ�ü̳е�����

#pragma once	
#include <iostream>
#include <stdio.h>
#include <string>

namespace DesignPattern
{
	class Builder;

	class Product
	{
	public:
		Product(){ std::cout<<"Constructor of Product"<<std::endl; }
		virtual ~Product(){ std::cout<<"Destructor of Product"<<std::endl; }
	public:
		//���������ò�ͬ�Ĳ���ֵ����ʾPartA��PartB��PartC�в�ͬ������
		void AddPartA( int iData ){ std::cout<<iData<<std::endl; }
		void AddPartB( std::string strData ){ std::cout<<strData<<std::endl; }
		void AddPartC( double dData ){ std::cout<<dData<<std::endl; }
	};

	class Director
	{
	public:
		Director(){};
		virtual ~Director(){};
	public:
		void ConstructProductOne( Builder * pBuilder );
		void ConstructProductTwo( Builder * pBuilder );
	};

	class Builder
	{
		friend class Director;
	public:
		Builder() : m_pProduct( NULL ){};
		virtual ~Builder(){};
		//��Director���е���Construct�����Ҵ���BuilderΪ�����󣬽�������Product���ҽ�����װ
		//�������ҪBuilder�����ؽ��в����������ˣ�������װ�õ�Product
		//���ص�Product��ʵ�����ڴ��ͷŽ���Client��
		virtual Product * GetResult(){ return m_pProduct; };
	protected:
		virtual void BuildProduct() = 0;
		virtual void BuildPartA() = 0;
		virtual void BuildPartB() = 0;
		virtual void BuildPartC() = 0;
	protected:
		Product * m_pProduct;
	};

	class ConcreteBuilderA : public Builder
	{
		friend class Director;
	public:
		ConcreteBuilderA(){};
		virtual ~ConcreteBuilderA(){};
	protected:
		virtual void BuildProduct();
		virtual void BuildPartA();
		virtual void BuildPartB();
		virtual void BuildPartC();
	};

	class ConcreteBuilderB : public Builder
	{
		friend class Director;
	public:
		ConcreteBuilderB(){};
		virtual ~ConcreteBuilderB(){};
	protected:
		virtual void BuildProduct();
		virtual void BuildPartA();
		virtual void BuildPartB();
		virtual void BuildPartC();
	};
}