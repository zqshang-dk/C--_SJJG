// #include <iostream>
// using namespace std;

// void quickSort(int arr[], int left, int right) {
//     if (left >= right) return;
    
//     int pivot = arr[(left + right) / 2];  // 选择中间元素作为基准
//     int i = left, j = right;
    
//     while (i <= j) {
//         while (arr[i] < pivot) i++;  // 从左找大于等于基准的元素
//         while (arr[j] > pivot) j--;  // 从右找小于等于基准的元素
        
//         if (i <= j) {
//             swap(arr[i], arr[j]);  // 交换元素
//             i++;
//             j--;
//         }
//     }
    
//     // 递归排序左右两部分
//     quickSort(arr, left, j);
//     quickSort(arr, i, right);
// }

// int main() {
//     int arr[] = {5, 2, 9, 1, 5, 6};
//     int n = sizeof(arr) / sizeof(arr[0]);
    
//     cout << "排序前: ";
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
    
//     quickSort(arr, 0, n - 1);
    
//     cout << "排序后: ";
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
    
//     return 0;
// }

#include <iostream>
using namespace std;

void quickSort(int arr[], int left, int right) {
    if (left >= right) return;
    
    int pivot = arr[left];  // 选择最左边元素作为基准
    int i = left + 1;       // i从基准的下一个位置开始
    int j = right;
    
    while (i <= j) {
        // 从左找大于基准的元素
        while (i <= right && arr[i] <= pivot) i++;
        // 从右找小于等于基准的元素  
        while (j > left && arr[j] > pivot) j--;
        
        if (i <= j) {
            swap(arr[i], arr[j]);
        }
    }
    
    // 将基准放到正确位置
    swap(arr[left], arr[j]);
    
    // 递归排序左右两部分
    quickSort(arr, left, j - 1);
    quickSort(arr, j + 1, right);
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "排序前: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    quickSort(arr, 0, n - 1);
    
    cout << "排序后: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}