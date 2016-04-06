#include "Math.h"
#include "Tree.h"

Math:: Math():
	error(0)
{
	GetEquation();
}

Math::~Math()
{}

void Math::GetEquation()
{
	ifstream File;
	File.open ("exp.txt");
	if (File.is_open()) printf("File is open\n");
	File >> str;
	//cout << str << endl;
	File.close();
	S = str.begin();
}

void Math::PrepareEquation()
{

}

void  Math::GetSkip()
{
	while(*S == ' ' || *S == 10)
	{
		S++;
	} 
}

CNode* Math::GetNum()
{
	GetSkip();
	double val = 0.0;
	while('0' <= *S && *S <= '9')
	{
		val = val*10 + *S - '0';
		S++;
	}
	CNode* tmp = new CNode;
	tmp -> PutNum(Number, val);
	return tmp;
} 

CNode* Math::GetExp()
{
	GetSkip();
	CNode* tmp= GetMulDiv();
	GetSkip();
	while(*S == '-' || *S =='+')
	{
		if (*S == '+') 
		{
			S++;
			CNode* tmp1 = new CNode;
			tmp1 -> PutSign(Sign, '+');
			tmp1 -> TieLeft(tmp);
			tmp = GetMulDiv();
			tmp1 -> TieRight(tmp);
			tmp = tmp1;
		}
		else if (*S == '-')
		{
			S++;
			CNode* tmp1 = new CNode;
			tmp1 -> PutSign(Sign, '-');
			tmp1 -> TieLeft(tmp);
			tmp = GetMulDiv();
			tmp1 -> TieRight(tmp);
			tmp = tmp1;
		}
		GetSkip();
	}
	return tmp;
}

CNode* Math::GetMulDiv()
{
	GetSkip();
	CNode* tmp= GetPas();
	GetSkip();
	while(*S == '*' || *S == '/')
	{
		if (*S == '*') 
		{
			S++;
			CNode* tmp1 = new CNode;
			tmp1 -> PutSign(Sign, '*');
			tmp1 -> TieLeft(tmp);
			tmp = GetPas();
			tmp1 -> TieRight(tmp);
			tmp = tmp1;
		}
		else if (*S == '/')
		{
			S++;
			CNode* tmp1 = new CNode;
			tmp1 -> PutSign(Sign, '/');
			tmp1 -> TieLeft(tmp);
			tmp = GetPas();
			tmp1 -> TieRight(tmp);
			tmp = tmp1;
		}
		GetSkip();
	}
	return tmp;
}

CNode*  Math::GetPas()
{
	GetSkip();
	CNode* tmp;
	if (*S == '(')
	{
		S++;
		tmp = GetExp();
		GetSkip();
		if (*S != ')')
		error = 1;
		S++;
	}
	else 
	tmp = GetNum();
	return tmp;
}