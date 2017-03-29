#pragma once
#include <stdio.h>

namespace DesignPattern
{
	class SingletonExample;

	template<class T>
	class Singleton
	{
	public:
		virtual ~Singleton();
	public:
		static T * Instance();
	protected:
		Singleton(){};
	protected:
		static T * m_pInstance;
	};

	template<class T>
	T * Singleton<T>::m_pInstance = 0;

	template<class T>
	Singleton<T>::~Singleton()
	{
		m_pInstance = NULL;
	}

	template<class T>
	T * Singleton<T>::Instance()
	{
		if ( m_pInstance == NULL )
			m_pInstance = new T;
		return m_pInstance;
	}

	class SingletonExample
		: public Singleton<SingletonExample>
	{
		//可以将其friend修饰去掉，然后，下面的构造函数改为Public
		//如果下面的构造函数为protected，那么忧郁Singleton<SingletonExample>会访问SingletonExample的构造函数
		//所以需要将Singleton<SingletonExample>设定为友元类
		friend class Singleton<SingletonExample>;
	public:
		virtual ~SingletonExample(){};
	protected:
		SingletonExample();
	public:
		int GetData(){ return m_iData; }
	private:
		int m_iData;
	};
}