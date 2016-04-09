#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <assert.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#ifndef NODE_H
#define NODE_H


enum c_type
{
	Number,
	Sign,
	Varible,
	Function
};

class CNode
{
	private:
		c_type type;
		double num;
		char sign;
		char var;
		CNode* left;
		CNode* right;
	public:
		CNode();
		CNode(double val);
		CNode(c_type t_type, char data, CNode* left, CNode* right);
		~CNode();
		CNode* TieLeft(CNode* MyLeft);
		CNode* TieRight(CNode* MyRight);

		void PutNum(c_type tp, double num);
		void PutSign(c_type tp, char sg);
		void PutVar(c_type tp, char vr);
		c_type GetType() { return type; }
		double GetNum() { return num; }
		char GetSign() { return sign; }
		char GetVar() { return var; }
		CNode* GoLeft() { return left; }
		CNode* GoRight() { return right; }
		void GoDump(int tab);
};

#endif 