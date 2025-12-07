// #include <iostream>

// using namespace std;

// template<typename T>
// struct list {
//     T* data;
//     int length;
// };

// template<typename T>
// void move1(list<T>*& L) {
//     int i = 0, j = L->length - 1;
//     T pivot = L->data[0];      //以data[0]为基准
//     T tmp;
//     while (i < j) {
//         // 以data[0]为基准
//         // 从区间两端交替向中间扫描,直至i==j为止
//         while (i < j && L->data[j] > pivot)
//             j--;
//         // 从右向左扫描,找第1个小于pivot的元素
//         while (i < j && L->data[i] <= pivot)
//             i++;
//         if (i < j) {
//             // 从左向右扫描,找第1个大于pivot的元素
//             // L->data[i]和L->data[j]进行交换
//             tmp = L->data[i];
//             L->data[i] = L->data[j];
//             L->data[j] = tmp;
//         }
//     }
//     // 交换 L->data[0] 和 L->data[i] 的值
//     tmp = L->data[0];
//     L->data[0] = L->data[i];
//     L->data[i] = tmp;
// }

// template<typename T>
// void printList(list<T>* L) {
//     for (int i = 0; i < L->length; i++) {
//         cout << L->data[i] << " ";
//     }
//     cout << endl;
// }

// int main() {
//     // 测试int类型
//     cout << "=== 测试int类型 ===" << endl;
//     list<int>* intList = new list<int>;
//     intList->length = 10;
//     intList->data = new int[10]{5, 8, 2, 9, 1, 7, 3, 6, 4, 0};
    
//     cout << "原始数组: ";
//     printList(intList);
    
//     move1(intList);
    
//     cout << "处理后数组: ";
//     printList(intList);
    
//     // 测试double类型
//     cout << "\n=== 测试double类型 ===" << endl;
//     list<double>* doubleList = new list<double>;
//     doubleList->length = 6;
//     doubleList->data = new double[6]{5.5, 2.2, 9.9, 1.1, 7.7, 3.3};
    
//     cout << "原始数组: ";
//     printList(doubleList);
    
//     move1(doubleList);
    
//     cout << "处理后数组: ";
//     printList(doubleList);
    
//     // 释放内存
//     delete[] intList->data;
//     delete intList;
//     delete[] doubleList->data;
//     delete doubleList;
    
//     return 0;
// }




#include<iostream>
using namespace std;

template<typename T>
struct list{
    T *data;
    int length;
};

template<typename T>
void move1(list<T> *&L){

}



