//对于包含有n个整数元素的顺序表L，设计一个算法将其中所有元素逆序，
#include<iostream>
using namespace std;

template<typename T>
void Reverse(SqList<T>&L){
    int i=0;j=L.length-1;
    while(i<j){
        swap(L.data[i],L.data[j]);
        i++;
        j--;
    }
};
