#include "Math.h"
#include "Tree.h"

main()
{
	Math test;
	CNode* node = test.GetExp();
	node -> GoDump(0);

	/*if (test.Debug())
		printf("We have problems!!\n");

	CNode* node_Sign = new CNode;
	node_Sign -> PutSign(Sign, '+');

	CNode* node_Num = new CNode;
	node_Num -> PutNum(Number, 2);

	CNode* node_Var = new CNode;
	node_Var -> PutVar(Varible, 'x');

	node_Sign -> TieLeft(node_Num);
	node_Sign -> TieRight(node_Var);
	node_Sign -> GoDump(0);
*/
	delete node;
	return 0;
}