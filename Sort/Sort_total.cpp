#include<iostream>
using namespace std;

void InsertSort(int *a,int n){
    
    //遍历数组，使每个元素都参与
    for (int i = 1; i < n; i++){
        int tmp = a[i]; 
        // for (int j = i - 1; j >= 0;j--){
        //     if(tmp<a[j]){
        //         a[j + 1] = a[j];

        //     }a[j] = tmp;
        // }
        int j;
        for (j = i - 1; j >= 0 && tmp < a[j];j--){  
            a[j + 1] = a[j];
        }
        a[j + 1] = tmp;
    }

    for (int i = 0; i < n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void BubbleSort(int *a,int n){
    for (int i = 0; i < n-1;i++){
        //for (int j = i; j < n-1;j++)
        for (int j = 0; j < n - i - 1;j++){
            if(a[j]>a[j+1]){
                int tmp=a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }

    for (int i = 0; i < n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

//记住，希尔排序是对直接插入排序的优化
void ShellSort(int *a,int n){
    int gap=n;
    while(gap>1){
        gap /= 1.3;
        if(gap<1)
            gap = 1;         //这一步很重要，确保gap最小也是为1；

        // for (int i = 0; i < n - gap;i++){
        //     int tmp = a[i];
        //     int j;

        //     for (j = 0; j <= n / gap && tmp < a[j]; j += gap)
        //     {
        //         a[j + gap] = a[j];
        //     }
        //     a[j] = tmp;
        // }
        
        //从gap开始，因为每个分组前gap个元素可以看作是各自分组内已排序的部分
        for (int i = gap; i < n;i++){
            int tmp=a[i];
            int j;
            for (j = i; j >= gap && tmp<a[j-gap]; j -= gap){

                a[j] = a[j - gap];
            }
            a[j] = tmp;
        }
    }

    for (int i = 0; i < n;i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

//选择排序
void SelectSort(int *a,int n){
    // int min=a[0];
    // for (int i = 1; i < n;i++){
    //     if(a[i]<min){
    //         min = a[i];
    //     }
    // }
    
    // for(int i=0;i<n;i++){
    //     int min = a[i];
    //     for (int j = i + 1; j < n;j++){
    //         if(a[j]<min){
    //             a[j + 1] = a[j];
    //             min = a[j];
    //         }
    //     }
    // }

    for (int i = 0; i < n - 1;i++){
        int min_i = i;      //记录最小元素的索引而不是值！！！
        for (int j = i + 1; j < n;j++){
            if(a[j]<a[min_i]){
                min_i = j;
            }
        }

        if(min_i!=i){
            int tmp = a[i];
            a[i] = a[min_i];
            a[min_i] = tmp;
        }
    }

    for (int i = 0; i < n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

//快速排序
void QuickSort(int *a,int n){
    if (n<=1)
        return;
    
    int tmp = a[0];
    int left = 0;
    int right = n - 1;

    while(left<right){
        while(left<right && a[right]>tmp){
            right--;
        }
        if(left<right){
            a[left] = a[right];
            left++;
        }
        // if(a[right]<=tmp){
        //     a[left] = a[right];
        // }
        // right--;

        // if(a[left]>tmp){
        //     a[right] = a[left];
        // }
        // left++;
        while(left<right && a[left]<=tmp){
            left++;
        }
        if(left<right){
            a[right] = a[left];
            right--;
        }
    }
    a[left] = tmp;

    QuickSort(a, left);
    QuickSort(a + left + 1, n - left - 1);

    for (int i = 0; i < n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

//归并排序
void MergeSort(int *a,int n){
    if(n<=1)
        return;     //递归终止条件

    int mid = n / 2;

    //分别递归排序左右两个部分
    MergeSort(a, mid);
    MergeSort(a + mid, n - mid);

    //合并两个有序数组
    int *tmp = new int[n];

    int i = 0;      //i指向左半部分数组的起始位置
    int j = mid;    //j指向右半部分数组的起始位置    
    int k = 0;      //k指向临时数组tmp的当前位置

    //同时遍历左半部分和右半部分数组
    while (i < mid && j < n){
        if(a[i]<a[j]){     //如果左半部分的当前元素小于右半部分的当前元素
            tmp[k] = a[i];  //将左半部分的元素放入tmp
            k++;
            i++;
        }

        else{
            tmp[k] = a[j];
            k++;
            j++;
        }
    }

    //处理左半部分剩余的元素：如果右半部分已经处理完了左半部分还未处理完
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

    //此时tmp数组中已经存储了完整排序好的结果
    //将排序结果从临时数组tmp复制回原数组a
    for (int i = 0; i < n; i++){
        a[i] = tmp[i];
    }
    delete[] tmp;

    for (int i = 0; i < n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void HeapSort(int *a,int n){
    for (int i = n / 2 - 1; i >= 0; i--){
        int tmp = a[i];
        int p = i;


        while((2*p+1)<n){
            int child = 2 * p + 1;
            if((2*p+2)<n && a[2*p+2]>a[2*p+1]){
                child++;
            }

            if(tmp>a[child]){
                break;
            }
            else{
                a[p] = a[child];
                p = child;
            }
        }
        a[p] = tmp;
    }

    for (int i = 0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl;

    for (int i = n - 1; i > 0; i--){
        int tmp1 = a[0];
        a[0] = a[i];
        a[i] = tmp1;

        int p = 0;
        int tmp = a[0];

        while((2*p+1)<i){
            int child = 2 * p + 1;
            if((2*p+2)<i && a[2*p+1]<a[2*p+2]){
                child++;
            }

            if(tmp>a[child]){
                break;
            }
            
            else{
                a[p]=a[child];
                p = child;
            }
        }
        a[p] = tmp;

        for (int j = 0; j < n;j++){
            cout << a[j] << " ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }

    cout << "堆排序结果：";
    HeapSort(arr, n);

    // cout << "快速排序结果：";
    // QuickSort(arr, n);

    // cout << "直接排序结果：";
    // SelectSort(arr, n);

    // cout << "希尔排序结果：";
    // ShellSort(arr, n);

    // cout << "冒泡排序结果：";
    // BubbleSort(arr, n);


    // cout << "插入排序结果：";
    // InsertSort(arr, n);


    return 0;
}