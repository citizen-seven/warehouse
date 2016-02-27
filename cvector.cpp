#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <stdlib.h>
#include <assert.h>

using namespace std;
const int MAX_SIZE = 32;

class CVector
{
    private:
        static int size_;
        int data_[MAX_SIZE];
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
        cout<<data_[i]<<" ";
    cout<<endl;
 }

int main()
{
    CVector V;
    V.VDump();
    V[0] = 2;
    V[4] = 5;
    V.VDump();
    V[0] = 1;
    V.VDump();
    return 0;
}
