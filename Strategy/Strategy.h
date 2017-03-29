//������Bridgeģʽ�����㷨����һ�¸������Strategy�������㷨���ࣩ����
//��State�಻ͬ���ǣ�Strategy�����Զ��Ľ����л����ڲ�û��һ���Զ��任Strategy����û���Զ��任���߼�������Ҫ���û���ָ������һϵ��Strategy����ѡ��
//��Context����Strategy Interface�����ã�������DoAlgorithm��ʱ��Context���Խ������thisָ����Ϊ��������
//����Strategy�Ϳ��Իص�Context�õ���Ӧ����Ϣ

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