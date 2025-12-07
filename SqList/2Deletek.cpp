//假设有一个整数顺序表L，设计一个算法用于删除从序号i开始的k个元素
#include<iostream>
using namespace std;

template<typename T>
bool Deletek(SqList<T>&L,int i,int k){
    if(i<0||k<1||i+k<1||i+k>L.length){
        return false;
    }
    for(int j=i+k;j<L.length;j++){
        L.data[j-k]=L.data[j];
    }
    L.length-=k;
    return true;
};