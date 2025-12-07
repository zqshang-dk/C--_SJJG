//这个代码我们来完成归并排序的算法实现

#include<iostream>
using namespace std;

//其实，归并排序的整个过程，仔细观察不难发现，这是一个递归的过程
//因为我们对每个部分的处理是一样的，都是先排序后合并
//因此，我们只需要先对数据进行递归调用完成排序，再来写程序对最后一个过程进行合并就可以了！

void MergeSort(int *a,int n){
    if(n<=1)                //md我真服了，怎么又能忘了递归条件，何意味？？？？？
        return;
    int mid = n / 2;
    MergeSort(a, mid);
    MergeSort(a + mid , n - mid );    //这里不能把mid值隔过去，这样的话，就没有地方能够处理mid了！

    //合并的时候要注意一个原则：
    //每次都选取两个数组中最小的元素进行比较，其实也就是比较各自剩下数据中的第一项
    //当其中一个数组放完之后，直接再把剩下一个数组放到最后
    int i = 0;
    int j = mid ;
    int k = 0;
    int *tmp = new int[n];

    while(i<mid && j<n){
        if(a[i]<a[j]){
            tmp[k] = a[i];
            i++;
            k++;
        }
        else{
            tmp[k] = a[j];
            j++;   //记好了，这里一定是j++而不能是j--，因为你这里也是从小往大遍历的！
            k++;
        }
    }
    while(i<mid){
        tmp[k] = a[i];
        k++;
        i++;
    }
    while(j<n){
        tmp[k] = a[j];
        k++;
        j++;
    }

    for (int l = 0; l < n;l++){
        a[l] = tmp[l];
    }
    delete[] tmp;
}

int main(){
    int n;
    cin >> n;

    int *a = new int[n];
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    MergeSort(a, n);
    for (int i = 0; i < n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
    delete[] a;
    return 0;
}