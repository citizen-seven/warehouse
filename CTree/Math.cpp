#include "Math.h"

Math:: Math():
	error(0)
{
	FILE* File = fopen("exp.txt", "r");
	char* string = (char*)calloc(100, sizeof(char));
	fgets(string, 100, File);
	fclose(File);
	S = string;
	str = string;
}

Math::~Math()
{
	free(str);
	error = 0;
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
	char* debug = S;
	double val = 0.0;
	while('0' <= *S && *S <= '9')
	{
		val = val*10 + *S - '0';
		S++;
	}/*
	if (S == debug)
	{
		error = 1;
		return 0xBAD;
	}*/
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
		} /*
		else
		{
			error = 1;
			return 0xBAD;
		}*/
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
		}/*
		else
		{
			error = 1;
			return 0xBAD;
		}*/
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