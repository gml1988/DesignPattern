//Builder与Bridge很相似，不过是把构造的工作交给外部的Builder类来完成
//过程实现使用Director，它仅关心组装部件的过程,不关心每个具体部件的创建。
//Builder则是定义出创建部件的接口，具体的创建，则是有ConcreteBuilder来实现。
//不同的Builder，生产的部件不同，但是组装的过程是相同的

//Director相当于包工头或者流程设计师，定义组装和生产的顺序流程
//Builder负责生产特定的各种部件的具体类型（每一种部件类型都是一棵继承的树）

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
		//在这里先用不同的参数值来表示PartA，PartB，PartC中不同的子类
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
		//在Director进行调用Construct，并且传入Builder为参数后，进行生成Product并且进行组装
		//最后还是需要Builder来返回进行部件生产好了，并且组装好的Product
		//返回的Product的实例的内存释放交给Client端
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