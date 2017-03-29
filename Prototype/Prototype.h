//Prototype提供了一个Clone接口，将自身的一份完整的拷贝的指针返回
//Prototype中都应该支持复制构造函数
//可以在一个Factory中存储若干个Prototype，这样需要进行Create不同的元素的时候
//用对应类型的Prototype就可以进行复制
//相当于在Factory中有若干个钥匙的模子，每来一个客户，就取其需要的模子进行进行复制，然后将拷贝给用户
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
		//复制构造函数的时候，记得需要拷贝其父类的成员
		ConcretePrototypeC( const ConcretePrototypeC& prototypeC ) : ConcretePrototypeA( prototypeC ){ m_cExtendData = prototypeC.m_cExtendData; }
		virtual ~ConcretePrototypeC(){};
	public:
		Prototype * Clone();
	private:
		char m_cExtendData;
	};
}