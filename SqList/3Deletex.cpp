//对于一个含有n个整数元素的顺序表L，删除其中所有值为x的元素
#include<iostream>
using namespace std;


//方法1：整体建表法，将不为x的元素重新建在一个新的顺序表中，最后输出即可
template<typename T>
void Deletex1(SqList<T>&L,int x){
    int k=0;
    for(int i=0;i<L.length;i++){
        if(L.data[i]!=x){
            L.data[k]=L.data[i];
            k++;
        }
    }
    L.length=k;
};


//方法2：元素移动法,把不为x的元素最终都移动到该有的位置上
template<typename T>
void Deletex2(SqList<T>,int x){
    int k=0;
    for(int i=0;i<L.length;i++){
        if(L.data[i]!=x){
            L.data[i-k]=L.data[i];
        }
        else{
            k++;
        }
    }
    L.length-=k;
};

//方法3：区间划分法：将L划分为两个区间，前一部分是“不为x的元素”，后一部分是“x元素区间”
template<typename T>
void Deletex3(SqList<T>,int x){
    int i=-1;
    int j=0;
    while(j<L.length){
        if(L.data[j]!=x){
            i++;
            if(i!=j){
                swap(L.data[i],L.data[j]);
            }
        }
        j++;
    }
    L.length=i+1;
};
