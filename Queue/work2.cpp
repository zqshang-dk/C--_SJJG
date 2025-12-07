// task_3.3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

//有*有序*数组array，要求使用队列，删除有序数组中重复出现的数组元，使每个数组元最多出现两次，输出数组的新长度和数组成员。

//输入和输出格式示例：
//输入: 
//9 1 2 2 3 3 3 4 5 6
//输出: 
//8 1 2 2 3 3 4 5 6

#include <iostream>
using namespace std;

template<class Ty>
class queue {
public:
	Ty* q;
	int size;
	int _front, _rear;


	queue(int capacity) :size(capacity){
        _front=_rear=-1;
        q=new Ty[size];
	}
    ~queue() {
        delete[] q;
	}

	bool IsEmpty()
	{
        return _front==_rear;
	}

	bool  push(int elem)
	{
        if((_rear+1)%size!=_front){
            _rear++;
            q[_rear]=elem;
            return true;
        }
	}

	Ty front() {		
        if(_front!=_rear){
            return q[_front+1];
        }
        return Ty();
	}

	void  pop()
	{
        if(!IsEmpty()){
            _front++;
        }
	}
};

int main()
{
	int n;
	cin >> n;
	int* data = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> data[i];
	}

	int dataSize = 0;
    
    queue<int> q(n);    //此处创建队列对象q，下面请使用该队列对象q完成题目
    
    // 使用dataSize记录删除重复数据后，数组data中的数据个数。
    //请在下方编写代码
    if(n==0){
        dataSize=0;
    }
    else{
        q.push(data[0]);
        int count=1;
        for(int i=1;i<n;i++){
            if(data[i]==data[i-1]){
                count++;
                if(count<=2){
                    q.push(data[i]);
                }
            }
            else{
                count=1;
                q.push(data[i]);
            }
        }
    }
	
    //将队列中的元素放回数组
    dataSize=q._rear-q._front;
    for(int i=0;i<dataSize;i++){
        data[i]=q.front();
        q.pop();
    }

    //编写代码完毕

	cout << dataSize <<" ";
	for (int i = 0; i < dataSize; ++i) 
		cout << data[i] << " ";
}




