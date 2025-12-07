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


//#include _________
//...
#include<iostream>
using namespace std;

int glo_n;
int *glo_arr;

int removeDuplicates() {
    if (glo_n < 2) {
        return glo_n;
    }
    int new_length = 1;
    int count = 1;
    for (int i = 1; i < glo_n; i++) {
        if (glo_arr[i] == glo_arr[new_length - 1]) {
            count++;
            if (count <= 2) {
                glo_arr[new_length] = glo_arr[i];
                new_length++;
            }
        }
        else {
            count = 1;
            glo_arr[new_length] = glo_arr[i];
            new_length++;
        }

     }
    return new_length;
    //return 数组的新长度；
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    //在本行下方编程程序代码，不要修改main()函数中本行及以上的内容

    glo_n = n;
    glo_arr = arr;
    int nl = removeDuplicates();
    for (int i = 0; i < nl; i++) {
        if (i == 0) {
            cout << arr[i];
        } 
        else {
            cout << " " << arr[i];
        }
    }
    cout << endl;
 
    delete[] arr;

    //代码编辑结束，不要修改本行及以下的内容
    return 0;
}