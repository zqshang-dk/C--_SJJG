/*
题目：
使用一个栈，在函数QuickSortNonRec(int * a , int n )中，实现快速排序算法的非递归形式。
main()函数中建立测试数据，调用该函数，输出排序结果。

输入格式：
整数n(数据长度) 数值1 数值2 ... 数值n

输出格式:
数值1 数值2 ... 数值n

*/


#include <iostream>
#include <stack>
using namespace std;

void QuickSortNonRec(int * a , int n ) {
    //本函数内，在本行下方编写程序代码，不要修改本行及以上的内容
    //怎么用栈实现快排？
    //等等什么是快排？——一次次把每一个数放在应该在的位置，也就是把比它小的数放在它后面，比它大的数放在它前面
    if(n<=1)
        return;
    stack<int> st;
    st.push(0);
    st.push(n - 1);

    while(!st.empty()){
        int right = st.top();
        st.pop();
        int left = st.top();
        st.pop();

        int l = left;
        int r = right;
        int tmp = a[l];

        while(l<r){
            while(l<r&& a[r]>=tmp){
                r--;
            }
            if(l<r){
                a[l++] = a[r];
            }

            while(l<r&&a[l]<=tmp){
                l++;
            }
            if(l<r){
                a[r--] = a[l];
            }
        }

        a[l] = tmp;
        
        //之后需要用stack存放还未经处理的区间
        //先压左区间
        if(l+1<right){
            st.push(l+1);
            st.push(right);
        }

        if(l-1>left){
            st.push(left);
            st.push(l - 1);
        }
        
    }

    //本函数内，代码编辑结束，不要修改本行及以下的内容

}




//不要修改main()函数中的内容
int main()
{  
	int n;
	cin>>n;

	int* data = new int[n];
	for (int i = 0; i < n; ++i)
		cin>> data[i];

	QuickSortNonRec(data, n);

    for (int i = 0; i < n; ++i)
		cout << data[i] << " ";

    delete [] data;    
    return 0;  
}  