#include <stdio.h>
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <stdlib.h>
#include <assert.h>

using namespace std;

class CStack
{
    private:
        int data_[];
        int size_;
        static int counter;
        int myOk();
    public:
        CStack();
        ~CStack();
        void myPush(int val);
        void myPop();
        void myDump();
};

int CStack::counter = 0;

CStack::CStack():
    data_({}),
    size_(0)
    {
        ++counter;
        if(counter > 1)
            {
                cout<<"You have already made 5 stacks.\nAre you sure want to make more?\nEnter password.. ";
                char* password = new char[100];
                cin>>password;
                if (strcmp("Angel1963\0", password))
                    {
                        cout<<"You enter incoorect password";
                        exit(-1);
                    }

            }

    }

CStack::~CStack()
{
    int i;
    for(i =0; i < size_; i++)
    {
        data_[i] = 0x0BAD;
    }
    size_ = 0;
}

int CStack::myOk()
{
    if (size_ > 0) return 1;
    else return 0;
}

void CStack::myDump()
{
    if (myOk() == 0)
        { cout<<"Sack is incoorect"; exit(-2); }
    int i;
    for(i = 0; i < size_; i++)
        printf("%d", data_[i]);

}

void CStack::myPush(int val)
{
    data_[size_] = val;
    size_++;
}

void CStack::myPop()
{
    data_[size_ - 1] = 0x0BAD;
    size_--;
}

int main()
{
    CStack MyStack, MyStack1;

    MyStack.myPush(10);
    MyStack.myDump;
    MyStack.myPush(15);
    MyStack.myDump;
    MyStack.myPop();
    MyStack.myDump;
}
