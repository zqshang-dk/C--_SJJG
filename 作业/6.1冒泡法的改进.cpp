/*题目：
冒泡法排序过程中，数组元素每次只能与相邻元素交换，要移动到其最终位置上，可能需要多次移动，
每次移动只能前进"一步之遥"，这样就导致算法效率低下，现采取如下措施来进行改进。

为加快冒泡的速度，现规定相邻距离gap长的元素进行比较，如果前者比后者大，则交换它们的位置。
原始的冒泡法中，这个gap的值恒为1。现在将gap值初始化为数组的长度，然后按gap=gap/1.3迭代。
按冒泡法的逻辑，`a[j]与a[j+gap]`进行比较，当j+gap的值超过了数组的边界，则更新gap值，
然后从起始数组元素重新开始比较。经过这样改进后，发生数组元交换时，数组元会一次移动gap长。

现编写程序对main函数中的数组进行排序。***要求每次更新gap后输出gap的值。***

输入格式：
整数n(数据长度) 数值1 数值2 ... 数值n

输出格式:
gap1 gap2 ... 数值1 数值2 ... 数值n

//前面是gap值序列，后面是排好序的数组元

*/

#include <iostream>
using namespace std;

void combsort(int *a, int n) {
    //在本行下方编写程序代码，不要修改本行及以上的内容
    //这个我试一下看能不能自己写出来吧，反正我又忘了怎么写来着了！
    int gap=n;
    while(gap>1){
        gap /= 1.3;
        cout << gap << " ";
        for (int i = 0; i < gap;i++){
            int j = i;
            while((j+gap)<n){
                if(a[j]>a[j+gap]){
                    int tmp = a[j];
                    a[j] = a[j + gap];
                    a[j + gap] = tmp;
                }
                j += gap;
            }
        }
    }





    //代码编辑结束，不要修改本行及以下的内容
}  

//不要修改main()函数中的内容
int main()
{  


	int n;
	cin>>n;

	int* data = new int[n];
	for (int i = 0; i < n; ++i)
		cin>> data[i];

	combsort(data, n);

	for (int i = 0; i < n; ++i)
		cout<<data[i]<<" ";
    delete [] data;    
    return 0;  
}  