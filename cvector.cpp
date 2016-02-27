#include <stdio.h> // this is a C library. same comment as in CStack
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <stdlib.h>
#include <assert.h>

using namespace std;

class CVector
{
    private:
        static int size_;
        int data_[]; // SIZE!!
    public:
        CVector();
        ~CVector();
        int& operator [] (int index)
        {
            assert(0 <= index && index < size_);
            return data_[index];
        }
        void VDump();
};

int CVector::size_ = 5;

CVector::CVector()
{
    int i;
    for(i = 0; i < size_; i++)
        data_[i] = 0;
}

CVector::~CVector()
{
    int i;
    for(i = 0; i < size_; i++)
        data_[i] = 0;
}

 void CVector::VDump()
 {
    int i;
    for(i = 0; i < size_; i++)
        cout<<data_[i]<<endl; // spaces
 }

int main()
{
    CVector V;
    V[0] = 1;
    V[1] = 2;
    int a = V[0];
    cout<<a<<endl; // spaces
    V.VDump();
    // return
}
