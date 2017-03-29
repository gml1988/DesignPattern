//ͨ���ۺϵķ�ʽ
//�ڲ���һ��Adaptee�ĳ�Ա����ָ�룬��ָ��������û����д�������Adapter���й����ʱ��
//��Ϊ���캯�����д��룬�ڵ��ü̳���Target�Ķ��⹦�õĽӿ�Operation��ʱ��ʵ����ί�и���Adaptee��
//Adaptee::SpecialOperation��ʵ��
//���ھۺ��ڲ���Adaptee�ĳ�Աָ�룬���ڴ��йܸ���Adapter�����ͷţ��������Ժͼ̳з�ʽ�Ľ������Ӧ
//////////////////////////////////////////////////////////////////////////
//ͨ���̳еķ�ʽ
//Adapter��Target����public�̳У���Adaptee����private�̳�
//�ڵ��ü̳���Target�Ľӿ�Operation��ʱ��ʵ����ʵʹ�õ���Adaptee��ʵ��
//ʹ��Adaptee::SpecialOperation����ת�������ض�������ľ���ʵ��

#pragma once	

namespace DesignPattern
{
	class Target
	{
	public:
		Target(){};
		virtual ~Target(){};
	public:
		virtual void Request() = 0;
	};

	class Adaptee
	{
	public:
		Adaptee(){};
		virtual ~Adaptee(){};
	public:
		virtual void SpecificRequest();
	};

	class InheritAdapter : public Target, private Adaptee
	{
	public:
		InheritAdapter(){};
		virtual ~InheritAdapter(){};
	public:
		virtual void Request();
	};

	class AggregateAdapter : public Target
	{
	public:
		AggregateAdapter( Adaptee * pAdaptee ) : m_pAdaptee( pAdaptee ){};
		virtual ~AggregateAdapter(){};
	public:
		virtual void Request();
	protected:
		Adaptee * m_pAdaptee;
	};
}