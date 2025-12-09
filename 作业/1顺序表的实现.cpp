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

#include<iostream>

using namespace std;

template<typename T>
class Vector{
public:          //woc，原来这里是默认私有的，我刚开始没有写这一行，发现main函数里面iva一直无法定义成功！！！！
    T *data;  //顺序表对象的内存区指针——其实也就是数组的第一个元素所在的位置
    int length;    //顺序表对象的内存区数据的长度
    int cap;   //顺序表对象内存区容量

    //构造函数
    //无参数传入的版本
    Vector() : data(nullptr), cap(0), length(0){}
    //有参数传入的版本
    Vector(int initial_cap):length(0),cap(initial_cap){
        data = new T[cap];
    }

    //析构函数
    ~Vector(){
        delete[] data;
    }

    //返回数据长度
    int size(){
        return length;
    }

    //返回顺序表容器长度
    int capacity(){
        return cap;
    }

    //从顺序表尾部向表中追加一个数据对象
    bool push_back(T element){
        //容量小了要扩容！！！！！
        if(length>=cap){
            int new_cap = (cap == 0) ? 1 : 2 * cap;
            T *new_data = new T[new_cap];

            for (int i = 0; i < length;i++){
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
            cap = new_cap;
        }

        data[length] = element;
        length++;
        return true;
    }

    //将一个数据对象插入到顺序表中index为pos的位置
    bool insert(int pos, const T &value){
        //容量小了要先扩容
        if(length>=cap){
            int new_cap = (cap == 0) ? 1 : cap * 2;
            T *new_data = new T[new_cap];

            for (int i = 0; i < length;i++){
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
            cap = new_cap;
        }

        //插入时还有更特殊的需要检查——给的pos值是否合理？！
        if(pos<0||pos>length){
            return false;
        }

        for (int i = length-1; i >pos-1;i--){
            data[i + 1] = data[i];
        }
        data[pos] = value;
        length++;
        return true;
    }
    //将顺序表中index为pos的位置上的数据对象删除
    bool erase(int pos){
        if(pos<0 || pos>length){
            return false;
        }

        for (int i = pos; i < length-1;i++){
            data[i] = data[i + 1];
        }
        length--;
        return true;
    }

    //下标运算重载符号
    T& operator[](int index){
        return data[index];
    }
};

//---------------定义 Vector 模板类---------------
/*
template<...>
class Vector
{
};
*/

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
    Vector<int> iva;
    //定义一个float类型的Vector对象 fvb
    Vector<float> fvb;

    for (int i = 0; i < 9; ++i){
        //使用push_back函数向iva对象输入9个数   
        //(每次从键盘输入一个数, 然后用push_back方法追加到顺序表中)
        int x;
        cin >> x;
        iva.push_back(x);
    }


    //输出iva中所有的数据对象，以index升序
    for (int i = 0; i < iva.size();i++){
        cout << iva.operator[](i) << " ";
    }
    cout << endl;

    for (int i = 0; i < 9; ++i)
    {
        // 使用insert函数向fvb对象输入9个数
        //(每次从键盘输入一个数, 然后用insert方法插入到顺序表中)
        float x;
        cin >> x;
        fvb.insert(i,x);
    }

    //输出fvb中所有的数据对象，以index升序
    for (int i = 0; i < iva.size();i++){
        cout << iva.operator[](i) << " ";
    }
    cout << endl;
    //使用insert()将0插入到iva中，在index为6的位置
    //输出iva中所有的数据对象，以index升序
    iva.insert(6, 0);
    for (int i = 0; i < iva.size();i++){
        cout << iva.operator[](i) << " ";
    }
    //使用erase()将fvb中index为6的数据对象删除
    //输出fvb中所有的数据对象，以index升序
    fvb.erase(6);
    for (int i = 0; i < iva.size();i++){
        cout << fvb.operator[](i) << " ";
    }
    cout << endl;

    //使用opertor [] 将fvb中index为3的数据对象赋值为9.99
    //输出fvb中所有的数据对象，以index升序
    fvb.operator[](3) = 9.99;
    for (int i = 0; i < fvb.size();i++){
        cout << fvb.operator[](i) << " ";
    }
    cout << endl;

    //--------------代码编辑结束，不要修改本行及以下的内容----------------------
    return 0;
}










