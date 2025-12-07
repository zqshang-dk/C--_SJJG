/*
题目：
顺序表中有n 个元素, 现从第 s 个元素开始从1报数，
报到 m 的元素被移出顺序表，然后继续从下一个元素开始从1报数，
报到第 m 个元素又将其移出顺序表，如到达顺序表的尾部，则调头从表头元素继续报数。
如此重复，直到所有的元素都被移出。请输出按出列次序得到的n个元素的顺序表

输入格式：
数据1 数据2 数据3 ...
输出格式
数据1 数据2 数据3...

*/


//在下方写出程序应该包含的头文件
#include<iostream>
using namespace std;
#include<iomanip>

//#include _________
//...

//完成Josephus(/*arg lists*/)函数，将参数数组中的顺序表转换成出列元素顺序表

void Josephus(int* a, int n, int s, int m)    // 注意: 这里要完成参数表
{
    //在本行下方编程程序代码，不要修改本函数中本行及以上的内容
    int* result = new int[n];  // 存储出列顺序
    bool* removed = new bool[n];  // 标记元素是否已被移除
    for (int i = 0; i < n; i++) {
        removed[i] = false;
    }
    
    int current = s;  // 当前报数起始位置
    int count = 0;    // 已移除的元素数量
    
    while (count < n) {
        int step = 1;  // 报数计数器
        
        // 找到第m个未被移除的元素
        while (step < m) {
            current = (current + 1) % n;  // 移动到下一个位置
            if (!removed[current]) {
                step++;
            }
        }
        
        // 将当前元素标记为已移除，并加入结果序列
        result[count] = a[current];
        removed[current] = true;
        count++;
        
        // 找到下一个报数起始位置
        if (count < n) {
            do {
                current = (current + 1) % n;
            } while (removed[current]);
        }
    }
    
    // 将结果复制回原数组
    for (int i = 0; i < n; i++) {
        a[i] = result[i];
    }
    
    delete[] result;
    delete[] removed;
    //代码编辑结束，不要修改本函数中本行及以下的内容
}

int main(){
    int* a, n;
    std::cin >> n;               //输入数组大小n
    a = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];           //输入n个数据     
    int s, m;                  
    cin >> s;                  //s表示从哪个元素开始计数，s是数组下标，从0开始计数
    cin >> m;                  //m表示报数到第几个数，对应的元素出列，从1开始报数

    //在本行下方编程程序代码，不要修改main()函数中本行及以上的内容
    
    //1. 调用Josephus()函数，对数组a进行处理
    Josephus(a, n, s, m);

    //2. 按格式要求输出数组a中的序列
    for (int i = 0; i < n; i++) {
        cout << a[i];
        if (i < n - 1) {
            cout << " ";
        }
    }
    cout << endl;
    
    delete[] a;
    //代码编辑结束，不要修改本行及以下的内容
    return 0;
}