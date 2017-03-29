//��ͬ��ͬһ�����ڲ�ͬ��Observableע�����Observer����ô��ͬ��Observable����Notify
//һ��Observable�����ڶ���������֪ͨ����������ά�����Observer���б���ͬ��Notify������Ӳ�ͬ������
//�����ڲ�ͬ��Notify�л�֪ͨ��ͬ�б��е�Observer
//�����Ļ�������ÿһ��������¼�����Ҫ�в�ͬ��Attach��Detach��Notify
//Ҳ�����ڲ�ͬ��Observer��Update�м�����һ��Aspect�Ĳ����������Ļ����Ϳ�����Update����Բ�ͬ��Aspect�������в�ͬ�Ĳ���

#pragma once
#include <vector>
#include <string>

namespace DesignPattern
{
	using std::vector;

	class IObservable;
	class IObserver
	{
	public:
		IObserver(){};
		virtual ~IObserver(){};
	public:
		virtual void Update( IObservable* pObservable ) = 0;
	};

	class IObservable
	{
	public:
		IObservable(){};
		virtual ~IObservable(){};
	public:
		virtual void AttachObserver( IObserver * pObserver ) = 0;
		virtual void DetachObserver( IObserver * pObserver ) = 0;
		virtual void NotifyObserver() = 0;
	};

	class ConcreteObservable : public IObservable
	{
	public:
		ConcreteObservable(){};
		ConcreteObservable( std::string str ) : m_stringData(str){};
		virtual ~ConcreteObservable(){};
	public:
		virtual void AttachObserver( IObserver * pObserver );
		virtual void DetachObserver( IObserver * pObserver );
		virtual void NotifyObserver();
		virtual std::string GetStringValue();
	private:
		std::vector<IObserver*> m_ObserverVector;
		std::string m_stringData;
	};

	class ConcreteObserver : public IObserver
	{
	public:
		ConcreteObserver( int iData ) : m_iData( iData ) {};
		virtual ~ConcreteObserver(){};
	public:
		virtual void Update( IObservable* pObservable );
	private:
		int m_iData;
	};
}