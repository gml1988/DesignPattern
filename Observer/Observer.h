//不同的同一个类在不同的Observable注册成了Observer，那么不同的Observable进行Notify
//一个Observable可以在多个方面进行通知，这样可以维护多个Observer的列表，不同的Notify可以添加不同的名字
//这样在不同的Notify中会通知不同列表中的Observer
//这样的话，对于每一个特殊的事件，需要有不同的Attach，Detach和Notify
//也可以在不同的Observer的Update中加入了一个Aspect的参数，这样的话，就可以在Update中针对不同的Aspect参数进行不同的操作

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