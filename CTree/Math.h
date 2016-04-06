#include "Tree.h"

class Math
{
	private:
		char* S;
		char* str;
		int error;
	public:
		Math();
		~Math();
		void GetSkip();
		CNode* GetNum();                      //Num :: = ['0' - '9'] +
		CNode* GetExp();                      //Exp :: = MulDiv {['+' '-']MulDiv}*
		CNode* GetMulDiv();                   //MulDiv :: = Pas {['*' '/'] Pas}*
		CNode* GetPas();                      //Pas:: = '(' Exp ')' | Num | F
		int Debug()
		{
			return error;
		}
};

