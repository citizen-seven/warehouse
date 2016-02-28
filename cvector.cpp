#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>

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
        int Vsize()
        {
            return size_;
        }
        CVector operator + (CVector val)
        {
            assert(size_ == val.Vsize());
            CVector exp;
            int i;
            for(i = 0; i < size_; i++)
                exp[i] = data_[i] + val[i];
            return exp;
        }
        int& operator [] (int index)
        {
            assert(0 <= index && index < size_);
            return data_[index];
        }
        int& operator () (CVector val) // scalar product
        {
            assert(size_ == val.Vsize());
            int exp = 0;
            int i;
            for(i = 0; i < size_; i++)
                exp += data_[i] * val[i];
            return exp;
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
    CVector V, V1, V2;
    int i;
    for(i = 0; i < V.Vsize(); i++)
    {
        V1[i] = i;
        V2[i] = i +1;
    }
    V1.VDump();
    V2.VDump();
    V.VDump();
    V = V1 + V2;
    V.VDump();
    int sk = V1(V2);
    cout << sk;
    return 0;
}
