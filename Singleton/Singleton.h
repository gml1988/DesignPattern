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
		//���Խ���friend����ȥ����Ȼ������Ĺ��캯����ΪPublic
		//�������Ĺ��캯��Ϊprotected����ô����Singleton<SingletonExample>�����SingletonExample�Ĺ��캯��
		//������Ҫ��Singleton<SingletonExample>�趨Ϊ��Ԫ��
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