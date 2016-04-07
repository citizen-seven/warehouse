#include "Math.h"
#include "Tree.h"

Math:: Math()
{
	GetEquation();
	PrepareEquation();
}

Math::~Math()
{}

void Math::GetEquation()
{
	ifstream File;
	File.open ("exp.txt");
	if (File.is_open()) printf("File is open\n");
	getline(File, str);
	//cout << str << endl;
	File.close();
	S = str.begin();
}

void Math::PrepareEquation()
{
	string tmp ;
	try
	{
		while(1)
		{
				if ((*S == ' ') || (*S == 10))
				{
					S++;
				} 
				else if(((*S >= '0') && (*S <= '9')) || (*S == '+') || (*S == '-') || (*S == '*') || (*S == '/') || (*S == '(') || (*S == ')'))
				{
					tmp += *S;
					S++;
				}
				else if(*S == '\0')
				{
					break;
				}
				else
				{
					throw string ("Permission incorrect expression. Please correct it\n") ;
					exit(1);
				}
			
		}
		str = tmp;
		S = str.begin();
		int error = 0, i = 0;
		for (; i < str.size(); i++)
		{
			if (*S == '(') 
			{
				error += 1;
			}
			if (*S == ')')
			{ 
				error -= 1;
			}
			if (error < 0) 
			{
				break;
			}
			S++;
		}
		if(error != 0)
		{
			throw string ("Permission incorrect expression. Check '(' and ')'. Please correct it\n") ;
			exit(1);
		}
	}
	catch(string ex)
	{
		cout << ex << endl;
		exit(1);
	}
	S = str.begin();
	//cout << str << endl;
	return;
}


CNode* Math::GetNum()
{
	double val = 0.0;
	string::iterator debug = S;
	while('0' <= *S && *S <= '9')
	{
		val = val*10 + *S - '0';
		S++;
	}
	try
	{
		if(debug == S)
			throw string ("Expected number. Please correct expression\n");
	}
	catch(string ex)
	{
		cout << ex << endl;
		exit(1);
	}
	CNode* tmp = new CNode;
	tmp -> PutNum(Number, val);
	return tmp;
} 

CNode* Math::GetExp()
{
	CNode* tmp= GetMulDiv();
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
	}
	return tmp;
}

CNode* Math::GetMulDiv()
{
	CNode* tmp= GetPas();
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
	}
	return tmp;
}

CNode*  Math::GetPas()
{
	CNode* tmp;
	if (*S == '(')
	{
		S++;
		tmp = GetExp();
		try
		{
			if (*S != ')')
				throw string ("Expected ')'. Please correct expression\n");
		}
		catch(string ex)
		{
			cout << ex << endl;
			exit(1);
		}
		S++;
	}
	else 
	tmp = GetNum();
	return tmp;
}