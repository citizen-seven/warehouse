enum t_node 
{
	VARIBLE,
	NUMBER,
	OPERATOR,
	FUCNTION
}

class CNode
{
	private:
		t_node type;
		double number;
		char wall;
		int Errors;
	//	CNode* left;
	//	CNode* right;
	//	CNode* parent;
	public:
		CNode() :
		//	left(NULL),
		//	right(NULL),
		//	parent(NULL)
		{}
        ~CNode()
		{}
		getS()
}