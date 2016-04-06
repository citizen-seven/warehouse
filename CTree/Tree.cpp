#include "Tree.h"

CNode:: CNode()
{
	left = NULL;
	right = NULL;
	prev = NULL;
	num = 0;
	sign = '^';
	var = '$';
}

CNode:: ~CNode()
{
	if (left != NULL)  delete left;
	if (right != NULL)  delete right;
	//if (prev != NULL)  delete prev;
}

CNode* CNode:: TieLeft(CNode* MyLeft)
{
	left = MyLeft;
	MyLeft -> prev = this;
	return this;
}

CNode* CNode:: TieRight(CNode* MyRight)
{
	right = MyRight;
	MyRight -> prev = this;
	return this;
}

void CNode:: PutNum(c_type tp, double nm)
{
	type = tp;
	num = nm;
}

void CNode:: PutSign(c_type tp, char sg)
{
	type = tp;
	sign = sg;
}

void CNode:: PutVar(c_type tp, char vr)
{
	type = tp;
	var = vr;	
}

void CNode:: GoDump(int tab)
{
	if(this != NULL)
    {
        int i = 0;
        left -> GoDump(tab + 1);
        for(i = 0; i < tab; i++) printf("  ");
        switch(GetType())
    	{
    		case (0):{ cout << GetNum(); break; }
    		case (1):{ cout << GetSign(); break; }
    		case (2):{ cout << GetVar(); break; }
    	}
    	cout << endl;
        right -> GoDump(tab + 1);
    }
}

/*
	cout << GetType() << " ";
    cout << GetNum() << " ";
    cout << GetSign() << " ";
    cout << GetVar() << " ";
    */