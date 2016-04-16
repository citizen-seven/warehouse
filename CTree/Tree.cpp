#include "Tree.h"
#include <math.h>

CNode::CNode()
{
    left = NULL;
    right = NULL;
    num = 0;
    sign = 0;
    var = 0;
    func = "";
}

CNode::~CNode()
{
    if (left != NULL)  delete left;
    if (right != NULL)  delete right;
    left = NULL;
    right = NULL;
}
/*
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
*/
void CNode::GoDump(int tab)
{
    if(this != NULL)
    {
        int i = 0;
        left -> GoDump(tab + 1);
        for(i = 0; i < tab - 1; i++)
        { 
            cout <<"    ";
        }
        //cout << "---->";
        switch(type)
        {
            case (0):{ cout << num; break; } //выводит большие числа в виде X.XXXXXe+XX
            case (1):{ cout << sign; break; }
            case (2):{ cout << var; break; }
            case (3):{ cout << func; break; }
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
    func = "";
}

CNode::CNode(char t_var)
{
    left = NULL;
    right = NULL;
    type = Varible;
    num = 0;
    sign = 0;
    var = t_var;
    func = "";
}

CNode::CNode(char t_data, CNode* t_left, CNode* t_right)
{
    left = t_left;
    right = t_right;
    type = Sign;
    num = 0;
    sign = t_data;
    var = '\0';
    func = "";
}

CNode::CNode(string t_str, CNode* t_left)
{
    left = t_left;
    right = NULL;
    type = Function;
    num = 0;
    sign = 0;
    var = 0;
    func = t_str;
}




CNode* const_optimization(const CNode* subtree)
{
    {
        switch (subtree->type)
        {
        case Number:
        {
            return new CNode(subtree->num);
            break;
        }
        case Sign:
        {
             switch (subtree->sign)
             {
             case '+':
             {
                 if ((subtree->left->type == Number) && (subtree->right->type == Number))
                {
                     return new CNode(subtree->left->num + subtree->right->num);
                }
                else    
                {
                    return new CNode('+', const_optimization(subtree->left), const_optimization(subtree->right));
                }
                 break;
            }
             case'-':
            {
                if ((subtree->left->type == Number) && (subtree->right->type == Number))
                {
                    return new CNode(subtree->left->num - subtree->right->num);
                }
                else
                {   
                    return new CNode('-', const_optimization(subtree->left), const_optimization(subtree->right));
                }
                break;
            }
            case '*':
            {
                if ((subtree->left->type == Number) && (subtree->right->type == Number))
                {
                    return new CNode(subtree->left->num * subtree->right->num); 
                }
                else
                {
                    return new CNode('*', const_optimization(subtree->left), const_optimization(subtree->right));
                }
                break;
            }
            case '/':
            {
                if ((subtree->left->type == Number) && (subtree->right->type == Number))
                {
                    return new CNode(subtree->left->num / subtree->right->num); 
                }
                else
                {
                    return new CNode('/', const_optimization(subtree->left), const_optimization(subtree->right));
                }
                     break;
            }
            case'^':
            {
                if ((subtree->left->type == Number) && (subtree->right->type == Number))
                {
                    return new CNode(pow(subtree->left->num, subtree->right->num));
                }
                else
                {
                    return new CNode('^', const_optimization(subtree->left), const_optimization(subtree->right));
                }
                break;
            }
        }
        }
        case Varible:
        {
            return new CNode('x');
            break;
        }
        case Function:
        {
            if (strcmp(subtree->func.c_str(), "sin") == 0)
            {
                return new CNode("sin", const_optimization(subtree->left));
            }
            else if (strcmp(subtree->func.c_str(), "cos") == 0)
            {
                return new CNode("cos", const_optimization(subtree->left));
            }
            else if (strcmp(subtree->func.c_str(), "ln") == 0)
            {
                return new CNode("ln", const_optimization(subtree->left));
            }
            // else if (strcmp(subtree->func.c_str(), "tg") == 0)
            {
                 //return new CNode("/", new CNode (1.0), derivate(subtree->left));
            }
            break;
        }
        }

    }
}

CNode* derivate(const CNode* subtree)
{
    switch (subtree->type)
    {
    case Number:
    {
        return new CNode(0.0);
        break;
    }
    case Sign:
    {
        switch (subtree->sign)
        {
            case '+':
            {
                return new CNode('+', derivate(subtree->left), derivate(subtree->right));
                break;
            }
            case'-':
            {
                return new CNode('-', derivate(subtree->left), derivate(subtree->right));
                break;
            }
            case '*':
            {
                return new CNode('+', new CNode('*',\
                derivate(subtree->left), subtree->right),\
                new CNode('*', subtree->left, derivate(subtree->right)));
                break;
            }
            case '/':
            {
                return new CNode('/', new CNode('-',\
                new CNode('*', derivate(subtree->left),\
                subtree->right), new CNode('*', subtree->left,\
                derivate(subtree->right))), \
                new CNode('^', derivate(subtree->left), new CNode(2.0)));
                break;
            }
            case'^':
            {
                return new CNode('*', new CNode('^',\
                subtree->left, subtree->right),\
                new CNode('+', new CNode('*', new CNode('/',\
                subtree->left, subtree->right),\
                derivate(subtree->left)), new CNode('*', \
                new CNode("ln", subtree->left), derivate(subtree->right))));
                break;
            }
        }
    }
    case Varible:
    {
        return new CNode(1.0);
        break;
    }
    case Function:
    {
        if (strcmp(subtree->func.c_str(), "sin") == 0)
        {
            return new CNode('*', new CNode("cos", subtree->left), derivate(subtree->left));
        }
        else if (strcmp(subtree->func.c_str(), "cos") == 0)
        {
            return new CNode('*', new CNode('-', new CNode(0.0), new CNode("sin", subtree->left)), derivate(subtree->left));
        }
        else if (strcmp(subtree->func.c_str(), "ln") == 0)
        {
            return new CNode('/', new CNode(1.0), derivate(subtree->left));
        }
            // else if (strcmp(subtree->func.c_str(), "tg") == 0)
        {
             //return new CNode("/", new CNode (1.0), derivate(subtree->left));
        }
        break;
    }
    }
}
