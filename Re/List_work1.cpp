/*
---------------题目描述开始---------------
题目：
定义一个 Vector 模板类。
数据成员有顺序表对象的内存区指针，内存区容量，顺序表中数据的长度。
成员函数有
1. 构造函数
2. 析构函数
3. int size()，返回数据长度
4. int capacity(), 返回顺序表容器的长度
5. bool push_back(_Ty element) 从顺序表尾部向表中追加一个数据对象
6. bool insert(int pos, const _Ty &value) 将一个数据对象插入到顺序表中index为pos的位置。
7. bool erase(int pos) 将顺序表中index为pos的位置上的数据对象删除。
8. 在Vector对象上定义操作符 " [ ] "，使用该操作符对顺序表中数据对象以下标方式进行引用。
9. 编写main()函数，对Vector类进行测试。

输入格式：
数据1 数据2 数据3 ...
输出格式
数据1 数据2 数据3 ...

---------------题目描述结束---------------
*/

//在下方写出程序应该包含的头文件


//#include _________
//...
#include<iostream>
using namespace std;

//---------------定义 Vector 模板类---------------
/*
template<...>
class Vector
{
};
*/
template<typename T>
class Vector{
private:
    T *data;
    int cap;
    int length;

public:
    //构造函数
    Vector():data(nullptr),cap(0),length(0){}

    //析构函数
    ~Vector(){
        if(data!=nullptr){
            delete []data;
        }
    }

    //int size()，返回数据长度
    int size(){
        return length;
    }

    //int capacity(), 返回顺序表容器的长度
    int capacity(){
        return cap;
    }

    //bool push_back(_Ty element) 从顺序表尾部向表中追加一个数据对象
    bool push_back(T element){
        if(length>=cap){
            int new_cap=(cap==0)?1:2*cap;

            T* new_data=new T[new_cap];
            for(int i=0;i<length;i++){
                new_data[i]=data[i];
            }
            
            if(data!=nullptr){
                delete [] data;
            }
            data=new_data;
            cap=new_cap;
        }
        data[length]=element;
        length++;
        return true;
    }

    //bool insert(int pos, const _Ty &value) 将一个数据对象插入到顺序表中index为pos的位置。
    bool insert(int pos,const T &value){
        if(length>=cap){
            int new_cap=(cap==0)?1:2*cap;

            T* new_data=new T[new_cap];
            for(int i=0;i<length;i++){
                new_data[i]=data[i];
            }
            
            if(data!=nullptr){
                delete [] data;
            }
            data=new_data;
            cap=new_cap;
        }
        // for(int i=pos;i<length;i++){
        //     data[i+1]=data[i];
        // }
        //这里如果是从前往后移动的话，会造成数据的覆盖，因此应该从后往前移动
        for(int i=length;i>pos;i--){
            data[i]=data[i-1];
        }


        data[pos]=value;
        length++;
        return true;
    }

    //bool erase(int pos) 将顺序表中index为pos的位置上的数据对象删除。
    bool erase(int pos){
        for(int i=pos;i<length-1;i++){
            data[i]=data[i+1];
        }
        length--;
        return true;
    }

    //在Vector对象上定义操作符 " [ ] "，使用该操作符对顺序表中数据对象以下标方式进行引用。
    T &operator[](int index){
        return data[index];
    }

};
//定义Vector类的成员函数
/*
Vector() { }
~Vector() { }
size() { }
Capacity() { }

push_back(_Ty element) { }
erase() { }
insert() { }

operator[]() { }
*/
//---------------定义 Vector 模板类定义 结束---------------

int main() {
    //--------------在本行下方编程程序代码，不要修改main()函数中本行及以上的内容----------------------

    //定义一个int类型的Vector对象 iva
    //定义一个float类型的Vector对象 fvb    
    Vector<int> iva;
    Vector<float> fvb;
    
	for (int i = 0; i < 9; ++i){
        //使用push_back函数向iva对象输入9个数   
        //(每次从键盘输入一个数, 然后用push_back方法追加到顺序表中)
        int num;
        cin>>num;
        iva.push_back(num);
    }

    //输出iva中所有的数据对象，以index升序
    for(int i=0;i<9;i++){
        cout<<iva[i]<<" ";
    }
    cout<<endl;
    
    for (int i = 0; i < 9; ++i){
        //使用insert函数向fvb对象输入9个数    
        //(每次从键盘输入一个数, 然后用insert方法插入到顺序表中)
        float num;
        cin>>num;
        fvb.insert(i,num);
    }

    //输出fvb中所有的数据对象，以index升序
    for(int i=0;i<9;i++){
        cout<<fvb[i]<<" ";
    }
	cout<<endl;
    //使用insert()将0插入到iva中，在index为6的位置
    iva.insert(6, 0);

    //输出iva中所有的数据对象，以index升序
    for(int i=0;i<9;i++){
        cout<<iva[i]<<" ";
    }
    cout<<endl;
    //使用erase()将fvb中index为6的数据对象删除
    fvb.erase(6);
    //输出fvb中所有的数据对象，以index升序
    for(int i=0;i<9;i++){
        cout<<fvb[i]<<" ";
    }
    //使用opertor [] 将fvb中index为3的数据对象赋值为9.99
    fvb.operator[](3)=9.99;

    //输出fvb中所有的数据对象，以index升序
    for(int i=0;i<9;i++){
        cout<<fvb[i]<<" ";
    }

    //--------------代码编辑结束，不要修改本行及以下的内容----------------------
    return 0;
}










