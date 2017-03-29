//Prototype�ṩ��һ��Clone�ӿڣ��������һ�������Ŀ�����ָ�뷵��
//Prototype�ж�Ӧ��֧�ָ��ƹ��캯��
//������һ��Factory�д洢���ɸ�Prototype��������Ҫ����Create��ͬ��Ԫ�ص�ʱ��
//�ö�Ӧ���͵�Prototype�Ϳ��Խ��и���
//�൱����Factory�������ɸ�Կ�׵�ģ�ӣ�ÿ��һ���ͻ�����ȡ����Ҫ��ģ�ӽ��н��и��ƣ�Ȼ�󽫿������û�
#include <string>
namespace DesignPattern
{
	using std::string;

	class Prototype
	{
	public:
		Prototype(){};
		virtual ~Prototype(){};
	public:
		virtual Prototype * Clone() = 0;
	};

	class ConcretePrototypeA
		: public Prototype
	{
	public:
		ConcretePrototypeA( int iData ) : m_iData( iData ){};
		ConcretePrototypeA( const ConcretePrototypeA& prototypeA ){ m_iData = prototypeA.m_iData; }
		virtual ~ConcretePrototypeA(){};
	public:
		Prototype * Clone();
	private:
		int m_iData;
	};

	class ConcretePrototypeB
		: public Prototype
	{
	public:
		ConcretePrototypeB( string strData ) : m_strData(strData){};
		ConcretePrototypeB( const ConcretePrototypeB& prototypeB ){ m_strData = prototypeB.m_strData; }
		virtual ~ConcretePrototypeB(){};
	public:
		Prototype * Clone();
	private:
		string m_strData;	
	};

	class ConcretePrototypeC
		: public ConcretePrototypeA
	{
	public:
		ConcretePrototypeC( int iData, char cData ) : ConcretePrototypeA( iData ), m_cExtendData( cData ){};
		//���ƹ��캯����ʱ�򣬼ǵ���Ҫ�����丸��ĳ�Ա
		ConcretePrototypeC( const ConcretePrototypeC& prototypeC ) : ConcretePrototypeA( prototypeC ){ m_cExtendData = prototypeC.m_cExtendData; }
		virtual ~ConcretePrototypeC(){};
	public:
		Prototype * Clone();
	private:
		char m_cExtendData;
	};
}