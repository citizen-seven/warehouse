#include "Tree.h"

#ifndef MATH_H
#define MATH_H


class Math
{
	private:
		string::iterator S;
		string str;
		int error;
	public:
		Math();
		~Math();
		string GetEquation();
		void PrepareEquation();
		void GetSkip();
		CNode* GetNum();                      //Num :: = ['0' - '9'] +
		CNode* GetExp();                      //Exp :: = MulDiv {['+' '-']MulDiv}*
		CNode* GetMulDiv();                   //MulDiv :: = Pas {['*' '/'] Pas}*
		CNode* GetPas();                      //Pas:: = '(' Exp ')' | Num | F
		int Debug() { return error; }
};

#endif