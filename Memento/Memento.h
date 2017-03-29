//Memento的构造函数为私有的，外面的类无法构造，并且其成员变量的Set和Get也是Private的
//只有Originator类（友元类）才能进行Memento的构造

namespace DesignPattern
{
	class Memento;

	class Originator
	{
	public:
		Originator( int iState ) : m_iState( iState ){};
		virtual ~Originator(){};
	public:
		Memento * CreateMemento();
		void SetMemento( const Memento * pMemento );
		inline void SetState( int iState ){ m_iState = iState; }
		inline int GetState() const{ return m_iState; }
	private:
		int m_iState;
	};

	class Memento
	{
		//需要将Originator声明为友元类，这样可以访问其构造函数以及
		//Get,Set函数
		friend class Originator;
	public:
		virtual ~Memento(){};
	private:
		//Memento的构造函数，以及成员变量的Get，Set都只能够由其友元类Originator进行访问
		//外界的Client不能随意构造以及改变状态
		Memento( int iState ) : m_iState( iState ){};
		inline int GetState() const{ return m_iState; }
		inline void SetState( int iState ){ m_iState = iState; }
	private:
		int m_iState;
	};
}
