//Proxy�Ƚ���Ҫ���ǣ�Proxy��RealSubject����̳���Subject
//����Proxy��RealSubject��������ͬ�Ľӿڣ��û��������ֵ��õ���Proxy����RealSubject
//��������Proxyͨ��Delegate������������RealSubject
//����ֻ���ڵ���RealSubject��API��ʱ��Ž������ʵ����
//ÿһ��������һ����Ӧ�Ĵ�����ΪRealSubject��ʵ�����ǽ���Proxy������
#pragma once
namespace DesignPattern
{
	class Subject
	{
	public:
		Subject(){};
		virtual ~Subject(){};
	public:
		virtual void Request() = 0;
	};

	class SubjectProxy
		: public Subject
	{
	public:
		SubjectProxy();
		//���������У���Proxy����RealSubject�������ڴ��ͷ�
		virtual ~SubjectProxy();
	public:
		virtual void Request();
	private:
		//ָ���Ӧ���������
		Subject * m_pRealSubject;
	};

	class RealSubject
		: public Subject
	{
		virtual void Request();
	};
}