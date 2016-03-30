#include <iostream>
#include <cassert>
// you dont need those libs...
#include <cstring>
#include <cstdlib>
#include <cstdio>
//
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
        CVector<T> operator + (CVector<T>& val)
        {
            assert(size_ == val.Vsize());
            CVector<T> exp;
            int i;
            for(i = 0; i < size_; i++)
                exp[i] = data_[i] + val[i];
            return exp;
        }
        T& operator [] (int index)
        {
            assert(0 <= index && index < size_);
            return data_[index];
        }
        T operator ^ (CVector<T>& val) // scalar product
        {
            assert(size_ == val.Vsize());
            T exp = 0;
            int i;
            for(i = 0; i < size_; i++)
                exp += data_[i] * val[i];
            return exp;
        }
        void VDump();
};

type
int CVector<T>::size_ = 5; 
// what if size_ > MAX_SIZE
// why do you initialize it here as global, rather then using constructors?
// and making it not const global you open it to changes from every method of CVector

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
    // destructor must be obvious. You must know somehow when vector is destroyed.
    // for example: size_ = -1 !!! not possible because you have static size_
}

type
void CVector<T>::VDump()
 {
    int i;
    for(i = 0; i < size_; i++)
        cout << data_[i] << "\t";
    cout << endl;
 }

template <>
CVector<bool> CVector<bool>::operator + (CVector<bool>& val) 
  // what you did here is not +, but ^ (exclusive OR = XOR)
  // it is not a mistake, just saying :) 
  // more reasonable to use operator^
{
	assert(size_ == val.Vsize());
	CVector<bool> exp;
	int i;
	for(i = 0; i < size_; i++)
		exp[i] = (data_[i] + val[i]) % 2;
	return exp;
}


int main()
{
    CVector<double> V, V1, V2;
    int i;
    for(i = 0; i < V.Vsize(); i++)
    {
        V1[i] = i + 0.5;
        V2[i] = i + 1;
    }
    V1.VDump();
    V2.VDump();
    V.VDump();
    V = V1 + V2;
    V.VDump();
    double sk = V1 ^ V2;
    cout << sk << endl;

	CVector<bool> V3, V4, V5;
	for(i = 0; i < V.Vsize(); i++)
		{
		    V3[i] = (7*i) % 2;
		    V4[i] = (5*i+6) % 2;
    	}
	V3.VDump();
    V4.VDump();
    V5 = V3 + V4;
    V5.VDump();
    return 0;
}
