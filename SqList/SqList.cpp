#include<iostream>
using namespace std;

const int initcap=5;        //顺序表的初始容量是5
template<typename T>
class SqList{
public:
    T* data;                //存放顺序表元素空间的指针
    int capacity;           //顺序表的容量
    int length;             //存放顺序表的长度

    //改变顺序表的容量为newcap
    void recap(int newcap){
        if(newcap<=0) return;
        T* olddata=data;
        data=new T[newcap];
        capacity=newcap;
        for(int i=0;i<n;i++){
            data[i]=olddata[i];
        }
        delete[]olddata;
    }
    //该算法是先让olddata指向data空间，
    //为data重新分配一个容量为newcap的空间
    //再将olddata空间中的所有元素复制到data空间中
    //复制中所有元素的序号和长度length不变，最后释放原data空间


    //1.整体建立顺序表
    void CreateList(T a[],int n){
        for(int i=0;i<n;i++){
            if(length==capacity){
                recap(2*length);
            }
            data[length]=a[i];
            length++;
        }
    }

    //2.顺序表的初始化和销毁
    SqList(){
        data=new T[initcap];     //为data分配初始容量的空间
        capacity=initcap;        //初始化容量
        length=0;                //初始时置length=0；
    }

    SqList(const SqList<T>&s){
        capacity=s.capacity;
        length=s.length;
        data=new T[capacity]
        for(int i=0;i<length;i++){
            data[i]=s->data;
        }
    }

}
