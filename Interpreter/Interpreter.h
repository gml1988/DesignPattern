//在Context中存储的是每一个String变量名对应的Bool值的映射表
//对于同一个BoolExp，在不同的Context下，可能有不同的值
//对于NonTerminalExpression，内部有若干个IBoolExp的成员，Evaluate为两个成员Evaluate结果的逻辑，这是用于维护一个文法的规则
//递归调用其成员的解释操作
//这类似于Composite模式
//只有对Variable才会有String变量名，是TerminalExpression，在此不用再进行递归，可以得到结果（从Context中查询）
//在不同的表达式中只存储了变量名或者通过不同的类来实现不同的逻辑
//至于取值如何，只能通过上下文Context来得到

#pragma once
#include <map>
#include <string>

namespace DesignPattern
{
	using std::map;
	using std::string;
	class Context
	{
	public:
		Context(){};
		virtual ~Context(){};
	public:
		void Assign( std::string strName, bool bValue );
		bool LookUp( std::string strName );
	private:
		std::map<std::string,bool> m_NameValueMap;
	};

	class IBooleanExp
	{
	public:
		IBooleanExp(){};
		virtual ~IBooleanExp(){};
	public:
		virtual bool Interpret( Context * pContext ) = 0;
	};

	class VariableExp : public IBooleanExp
	{
	public:
		VariableExp( std::string strName ) : m_strName( strName ){};
		virtual ~VariableExp(){};
	public:
		virtual bool Interpret( Context * pContext );
	private:
		std::string m_strName;
	};

	class AndExp : public IBooleanExp
	{
	public:
		AndExp( IBooleanExp * pLeft, IBooleanExp * pRight ) : m_pBoolExpLeft( pLeft ), m_pBoolExpRight( pRight ){};
		virtual ~AndExp(){};
	public:
		virtual bool Interpret( Context * pContext );
	private:
		IBooleanExp * m_pBoolExpLeft;
		IBooleanExp * m_pBoolExpRight;
	};

	class OrExp : public IBooleanExp
	{
	public:
		OrExp( IBooleanExp * pLeft, IBooleanExp * pRight ) : m_pBoolExpLeft( pLeft ), m_pBoolExpRight( pRight ){};
		virtual ~OrExp(){};
	public:
		virtual bool Interpret( Context * pContext );
	private:
		IBooleanExp * m_pBoolExpLeft;
		IBooleanExp * m_pBoolExpRight;
	};

	class NotExp : public IBooleanExp
	{
	public:
		NotExp( IBooleanExp * pExp ) : m_pBoolExp( pExp ){};
		virtual ~NotExp(){};
	public:
		virtual bool Interpret( Context * pContext );
	private:
		IBooleanExp * m_pBoolExp;
	};
}