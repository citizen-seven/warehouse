#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <assert.h>  // ?  //I did not need

using namespace std;
const int MAX_SIZE = 32;

class CStack
{
    private:
        int data_[MAX_SIZE]; // you HAVE to have size. it is not a dynamic array  //I understand
        int size_;
        static int counter;
        int Ok();
    public:
        CStack();
        ~CStack();
        void Push(int val);  // just Push for name is fine. //Ok
        int Pop();          // what does Pop has to do? should it, for example, return popped element? //Fine
        void Dump();
};

int CStack::counter = 0;

CStack::CStack():
    data_{}, // supported starting std=c++11 and must NOT be parenthesized
               // both data_{0} and data_{} is possible.                            //Ok
    size_(0)
    {
        ++counter;
        if(counter > 3)
            {
                cout << "You have already made 5 stacks.\nAre you sure want to make more?\nEnter password.. ";
                char* password = new char[100];
                cin >> password;                        // >> as well as << are operators. same as +\-\* and so on. use spaces. //I don`t understand
                if (strcmp("Angel1963\0", password))  // I DO hope that is your password for VK // NO
                    {
                        cout << "You enter incoorect password";
                        exit(-1);
                    }

            }

    }

CStack::~CStack()
{
    int i;
    for(i = 0; i < size_; i++)   // misprint: space is missing  //What?
        data_[i] = 0x0BAD;
    size_ = -1;
    counter--;
}

int CStack::Ok()
{
    if (size_ >= 0 && size_ <= MAX_SIZE) return 1;   // this is insufficient condition. size_ must be al least less then MAX_SIZE //Yeah
    else return 0;
}

void CStack::Dump()
{
    if (Ok() == 0)
         cout << "Stack is incoorect"; // I don't get why do you have to abort the program if you have size <= 0?..
                                       // OK, now program says than working with inccorect Stack and miss body of function
    else
    {
        int i;
        for(i = 0; i < size_; i++)
            cout<<data_[i]<<" ";
        cout<<endl;
    }
}

void CStack::Push(int val)
{
    // Stack check is missing //corrected
    if (Ok() == 0)
         cout<<"Stack is incoorect";
    else
    {
        data_[size_] = val;
        size_++;
    }
}

int CStack::Pop()
{
    // Stack check is missing //corrected
    if (Ok() == 0)
    {
         cout<<"Stack is incoorect";
         return 0x0BAD;
    }
    else
    {
        int tmp = data_[size_ - 1];
        data_[--size_] = 0x0BAD;
        return tmp;
    }
}

int main()
{
    CStack MyStack, MyStack1;

    MyStack.Push(10);
    MyStack.Dump();     // this is a FUNCTION, so it should be a function call //Understand
    MyStack.Push(15);
    MyStack.Dump();
    MyStack.Pop();
    MyStack.Dump();
    return 0;  // return is missing //Corrected
}
