#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define type template <typename T>

using namespace std;
const int MAX_SIZE = 32;

type
class CVector
{
    private:
        static int size_;
        T data_[MAX_SIZE];
    public:
        CVector();
        ~CVector();
        int Vsize()
        {
            return size_;
        }
        CVector<T> operator + (CVector val)
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
        int& operator ^ (CVector val) // scalar product
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

type
int CVector<T>::size_ = 5;

type
CVector<T>::CVector()
{
    int i;
    for(i = 0; i < size_; i++)
        data_[i] = 0;
}

type
CVector<T>::~CVector()
{
    int i;
    for(i = 0; i < size_; i++)
        data_[i] = 0;
}

type
void CVector<T>::VDump()
 {
    int i;
    for(i = 0; i < size_; i++)
        cout<<data_[i]<<" ";
    cout<<endl;
 }


int main()
{
    CVector<int> V, V1, V2;
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
    int sk = V1 ^ V2;
    cout << sk;
    return 0;
}
