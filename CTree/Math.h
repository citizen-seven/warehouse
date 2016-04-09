#include "Tree.h"

#ifndef MATH_H
#define MATH_H


class Math
{
	private:
		string::iterator S;
		string str;
	public:
		Math();
		string GetEquation();
		string PrepareEquation();
		void PutStr(string st);
		CNode* GetNum();                      //Num :: = ['0' - '9'] +
		CNode* GetExp();                      //Exp :: = MulDiv {['+' '-']MulDiv}*
		CNode* GetMulDiv();                   //MulDiv :: = Pas {['*' '/'] Pas}*
		CNode* GetPas();                      //Pas:: = '(' Exp ')' | Num | F
};

#endif