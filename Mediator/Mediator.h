//在每一个Colleague类中都有一个成员指向一个Mediator
//Mediator中有每一个Colleague的成员，这样就可以知道是哪一个成员传过来的信息
//指针是否相等
//Colleague通过Mediator的指针调用一个API，传入自身的指针this为参数
//不同的Mediator可以有不同的将不同的Colleague之间进行相互协作的逻辑

namespace DesignPattern
{
	class Mediator;

	class Colleague
	{
	public:
		Colleague( Mediator * pMediator ){};
		virtual ~Colleague(){};
	public:
		virtual void NotifyMediator();
	protected:
		Mediator * m_pMediator;
	};

	class ConcreteColleagueA
		: public Colleague
	{
	public:
		ConcreteColleagueA( Mediator * pMediator ) : Colleague( pMediator ){};
		virtual ~ConcreteColleagueA(){};
	};

	class ConcreteColleagueB
		: public Colleague
	{
	public:
		ConcreteColleagueB( Mediator * pMediator ) : Colleague( pMediator ){};
		virtual ~ConcreteColleagueB(){};
	};

	class Mediator
	{
	public:
		Mediator(){};
		virtual ~Mediator(){};
	public:
		virtual void CreateColleague() = 0;
		virtual void NotifiedByColleague( Colleague * pColleague ) = 0;
	};

	class ConcreteMediator
		: Mediator
	{
	public:
		ConcreteMediator(){};
		virtual ~ConcreteMediator(){};
	public:
		virtual void CreateColleague();
		virtual void NotifiedByColleague( Colleague * pColleague );
		Colleague * GetColleagueA1(){ return m_pColleagueA_1; }
		Colleague * GetColleagueA2(){ return m_pColleagueA_2; }
		Colleague * GetColleagueB(){ return m_pColleagueB; }
	private:
		ConcreteColleagueA * m_pColleagueA_1;
		ConcreteColleagueA * m_pColleagueA_2;
		ConcreteColleagueB * m_pColleagueB;
	};
}