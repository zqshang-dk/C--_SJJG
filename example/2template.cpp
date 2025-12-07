#include<iostream>
using namespace std;

template<typename T>
class Array{
    T* data;
    int length;
public:
    Array(int n=1){
        data=new T[n];
        length=0;
    }
    ~Array(){
        delete [] data;
    }
    void add(T x){
        data[length]=x;
        length++;
    }
    void display(){
        for(int i=0;i<length;i++){
            cout<<data[i]<<"  ";
        }
        cout<<endl;
    }
};

int main(){
    Array<char>ac(3);
    ac.add('x');
    ac.add('y');
    ac.add('z');
    cout<<"ac:";
    ac.display();
    return 0;
}