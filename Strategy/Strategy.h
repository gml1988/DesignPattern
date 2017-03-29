//类似于Bridge模式，将算法部分一致给具体的Strategy（管理算法的类）来做
//与State类不同的是，Strategy不会自动的进行切换，内部没有一个自动变换Strategy族中没有自动变换的逻辑，这需要由用户来指定（从一系列Strategy族中选择）
//在Context中有Strategy Interface的引用，并且在DoAlgorithm的时候，Context可以将自身的this指针作为参数传入
//这样Strategy就可以回调Context得到相应的信息

#pragma once

namespace DesignPattern
{
	class IStrategy;

	class StrategyContext
	{
	public:
		StrategyContext( IStrategy * pIStrategy ) : m_pIStrategy( pIStrategy ){};
		virtual ~StrategyContext(){};
	public:
		virtual void ContextInterface();
	private:
		IStrategy * m_pIStrategy;
	};

	class IStrategy
	{
	public:
		IStrategy(){};
		virtual ~IStrategy(){};
	public:
		virtual void AlgorithmInterface( StrategyContext * pStrategyContext ) = 0;
	};

	class ConcreteStrategyA : public IStrategy
	{
	public:
		ConcreteStrategyA(){};
		virtual ~ConcreteStrategyA(){};
	public:
		virtual void AlgorithmInterface( StrategyContext * pStrategyContext ); 
	};

	class ConcreteStrategyB : public IStrategy
	{
	public:
		ConcreteStrategyB(){};
		virtual ~ConcreteStrategyB(){};
	public:
		virtual void AlgorithmInterface( StrategyContext * pStrategyContext ); 
	};
}