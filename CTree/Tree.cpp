#include "Tree.h"

CNode::CNode()
{
    left = NULL;
    right = NULL;
    num = 0;
    sign = 0;
    var = 0;
}

CNode::~CNode()
{
    if (left != NULL)  delete left;
    if (right != NULL)  delete right;
}

CNode* CNode::TieLeft(CNode* MyLeft)
{
    left = MyLeft;
    return this;
}

CNode* CNode::TieRight(CNode* MyRight)
{
    right = MyRight;
    return this;
}

void CNode::PutNum(c_type tp, double nm)
{
    type = tp;
    num = nm;
}

void CNode::PutSign(c_type tp, char sg)
{
    type = tp;
    sign = sg;
}

void CNode::PutVar(c_type tp, char vr)
{
    type = tp;
    var = vr;    
}

void CNode::GoDump(int tab)
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

CNode::CNode(double val)
{
    left = NULL;
    right = NULL;
    type = Number;
    num = val;
    sign = 0;
    var = 0;
}


CNode::CNode(c_type t_type, char t_data, CNode* t_left, CNode* t_right)
{
    if(t_type == Sign)
    {
        left = t_left;
        right = t_right;
        type = Sign;
        num = 0;
        sign = t_data;
        var = 0;
    }
    if(t_type == Varible)
    {
        left = t_left;
        right = t_right;
        type = Varible;
        num = 0;
        sign = 0;
        var = t_data;
    }
}