#include<iostream>
using namespace std;

template<class _Ty>//写为template<typename _Ty>是一样的作用
class Vector{
private:
    _Ty *p_list;
    int length;
    int capacity;

public:
    Vector();
    ~Vector();
    int size();
    int Cap();
    bool push_back(_Ty element);
    _Ty &operator[](const int _Pos);
    Vector<_Ty> &operator=(const Vector<_Ty> &other);
    bool insert(int pos, const _Ty &value);
    bool erase(int pos);
};

template<class _Ty>
Vector<_Ty>::Vector(){
    length = 0;
    capacity = 0;
    p_list = nullptr;
}

template<typename _Ty>
Vector<_Ty>::~Vector(){
    if(p_list!=nullptr){
        delete[] p_list;
    }
}

template<typename _Ty>
bool Vector<_Ty>::push_back(_Ty element){
    if(length==capacity){
        _Ty *tmp = p_list;
        
        if(capacity==0){
            p_list = new _Ty[1];
            if(p_list==nullptr){
                return false;
            }
            p_list[0] = element;
            length++;
            capacity = 1;
            return true;
        }
    }
    p_list[length] == element;
    length++;
    return true;
}

template<class _Ty>
bool Vector<_Ty>::erase(int pos){
    if (pos < 0 || pos > length){
        return false;
    }
    for (int i = pos; i < length-1;i++){
        p_list[i] = p_list[i + 1];
    }
    length--;
    return true;
}



