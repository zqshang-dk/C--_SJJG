/*
题目：
有*有序*数组array，要求实现一个函数，
删除有序数组中数据对象的值重复出现的数组元，
使每个数组元最多出现两次，并返回数组的新长度。
要求只能使用 O(1)的额外内存空间
（即使用额外的内存的大小是个常量，不与数组array 的长度相关）
程序输出处理后的数组元素。

输入格式：
数据1 数据2 数据3 ...
输出格式
数据1 数据2 ...
*/

//在下方写出程序应该包含的头文件
#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(int *a,int n){
    //这里我考虑的是先排序再进行删除工作，因为如果不排序的话，需要对元素进行查找，是比较麻烦的，也不容易进行
    //wok,已经是有序数组了啊！wordfa
    // for (int i = 0; i < n-1;i++){
    //     for (int j = 0; j = i-1;j++){
    //         if(a[j]>a[j+1]){
    //             int tmp = a[j];
    //             a[j] = a[j + 1];
    //             a[j + 1] = tmp;
    //         }
    //     }
    // }

    // 排完序之后就要进行删除了
    // 其中需要一个tmp先保存当前的变量，然后再去看后面有几个数等于tmp
    // for (int i = 0; i < n;i++){
    //     int tmp = a[i];
    //     int count = 1;
    //     for (int j = i+1; j < n;j++){
    //         if(a[j]=tmp){
    //             count++;
    //         }
    //         if(count>2){
                
    //         }
    //     }
    // }
    if(n<=2)
        return n;
    //慢指针，指向下一个元素放置的位置
    int slow=2;
    for (int fast = 2; fast < n;fast++){
        if(a[fast]!=a[slow-2]){
            a[slow] = a[fast];
            slow++;
        }
    }
    return slow;

    //return 数组的新长度；
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;++i)
        cin>>arr[i];

//在本行下方编程程序代码，不要修改main()函数中本行及以上的内容
    int new_length = removeDuplicates(arr, n);
    for (int i = 0; i < new_length;i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    // 代码编辑结束，不要修改本行及以下的内容
    return 0;
}