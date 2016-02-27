#include <stdio.h> // why do you include same libraries twice. And moreover, include C library?
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <stdlib.h>  // ?
#include <assert.h>  // ?

using namespace std;

class CStack
{
    private:
        int data_[]; // you HAVE to have size. it is not a dynamic array
        int size_;
        static int counter;
        int myOk();
    public:
        CStack();
        ~CStack();
        void myPush(int val);  // just Push for name is fine.
        void myPop();          // what does Pop has to do? should it, for example, return popped element?
        void myDump();
};

int CStack::counter = 0;

CStack::CStack():
    data_({}), // supported starting std=c++11 and must NOT be parenthesized
               // both data_{0} and data_{} is possible.
    size_(0)  // FINE, lets make a ZERO size stack and wonder why nothing is working...
    {
        ++counter;
        if(counter > 1)
            {
                cout<<"You have already made 5 stacks.\nAre you sure want to make more?\nEnter password.. ";
                char* password = new char[100];
                cin>>password;                        // >> as well as << are operators. same as +\-\* and so on. use spaces. 
                if (strcmp("Angel1963\0", password))  // I DO hope that is your password for VK
                    {
                        cout<<"You enter incoorect password";
                        exit(-1);
                    }

            }

    }

CStack::~CStack()
{
    int i;
    for(i =0; i < size_; i++)   // misprint: space is missing
    {
        data_[i] = 0x0BAD;
    }
    size_ = 0;
}

int CStack::myOk()
{
    if (size_ > 0) return 1;   // this is insufficient condition. size_ must be al least less then MAX_SIZE 
    else return 0;
}

void CStack::myDump()
{
    if (myOk() == 0)
        { cout<<"Sack is incoorect"; exit(-2); } // I don't get why do you have to abort the program if you have size <= 0?..
    int i;
    for(i = 0; i < size_; i++)
        printf("%d", data_[i]);

}

void CStack::myPush(int val)
{
    // Stack check is missing
    data_[size_] = val;
    size_++;
}

void CStack::myPop()
{
    // Stack check is missing
    data_[size_ - 1] = 0x0BAD;
    size_--;
}

int main()
{
    CStack MyStack, MyStack1;

    MyStack.myPush(10);
    MyStack.myDump;     // this is a FUNCTION, so it should be a function call 
    MyStack.myPush(15);
    MyStack.myDump;
    MyStack.myPop();
    MyStack.myDump;
    // return is missing
}
