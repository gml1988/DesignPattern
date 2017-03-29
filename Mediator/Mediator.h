//��ÿһ��Colleague���ж���һ����Աָ��һ��Mediator
//Mediator����ÿһ��Colleague�ĳ�Ա�������Ϳ���֪������һ����Ա����������Ϣ
//ָ���Ƿ����
//Colleagueͨ��Mediator��ָ�����һ��API�����������ָ��thisΪ����
//��ͬ��Mediator�����в�ͬ�Ľ���ͬ��Colleague֮������໥Э�����߼�

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