/*题目：
在一维字符数组 A 中存储了一棵高度为 d 的二叉树，其结点的个数为 2^d-1 ，
存储方式是按中序逐个将结点顺序存入到数组A中。
请写出递归算法将该二叉树的前序遍历结果存储在数组 B 中。
输入格式：
字符1 字符2 字符3 ... 字符n
输出格式
字符1 字符2 字符3 ... 字符n
*/
#include<iostream>
using namespace std;

void convert(char *a,char *b,int n){
    if(n<=0)
        return;

    int tmp = n / 2;
    *b = a[tmp];
    convert(a, b + 1, tmp);
    convert(a + tmp + 1, b + tmp + 1, n - tmp - 1);
}



int main() {

	int n; 
	cin >> n;  //输入数据的长度
	char* data = new char[n];

	for (int i = 0; i < n; ++i) //输入n个数据
		cin >> data[i];

    //不要修改main()函数中以上部分的内容---------------------------
    //完美二叉树的中序遍历转前序遍历
    //这个题是要用递归算法来实现，但是怎么用递归呢？——所以必须要有一个其他的函数才能实现递归
    char* new_data = new char[n];

    convert(data, new_data, n);
    for (int i = 0; i < n;i++){
        cout << new_data[i] << " ";
    }
    cout << endl;

    delete[] new_data;
    // 不要修改main()函数中以下部分的内容---------------------------

    delete[] data; 
    return 0;  
}  


