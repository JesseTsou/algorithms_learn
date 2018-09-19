//
// Created by Administrator on 2018/9/17.
//

#ifndef SORT_SORTFUN_H
#define SORT_SORTFUN_H

/*
 * 选择排序
 * 时间复杂度：O(n^2)
 * 遍历数组，每次将取得之后最小值，并与该遍历点交换。
 */
template <typename T>
void selectionSort(T *arr, int n)
{
    for (int i = 0; i < n; i ++){
        //寻找[i,n)中的最小值
        int minIndex = i;
        for (int j = i + 1; j < n; j ++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i],arr[minIndex]);
    }
    return;
}

/*
 * 插入排序
 * 时间复杂度：O(n^2)
 * 遍历数组，每次将遍历点之前的子数组视为已经排序好的，将遍历点插入到之前排序好的子数组中。
 * 可以提前终止内层循环。
 * 若要排序的数组近乎有序，则效率非常高。
 * 若要排序的数组为有序，时间复杂度O(n)
 */
template <typename T>
void insertionSort(T *arr, int n)
{
    for (int i = 1; i < n; i ++){
        int minIndex = i;
        T tmp = arr[i];
        int j;
        for (j = i - 1; j >= 0 && arr[j] > tmp; j --){
            arr[j + 1] = arr[j];
        }
        arr[j] = tmp;
    }
    return;
}

/*
 * 冒泡排序
 * 时间复杂度：O(n^2)
 * 每轮遍历，将相邻两相元素进行比较，将较大（或较小）的放置在后面。
 * 遍历一遍，最后一个值即为最大值（或最小值）。
 */
template <typename T>
void bubbleSort(T *arr, int n)
{
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n - i; j ++){
            if (arr[j] > arr[j + 1])
                swap(arr[j],arr[j + 1]);
        }
    }
    return;
}

/*
 * 归并排序
 * 时间复杂度：O(nlogn)
 * 将要排序的数组，从中间分为两部分，分别进行排序，然后将这两部分进行归并
 * 使用递归方法
 * 使用辅助数组对两子数组进行合并操作。
 */
template <typename T>
void __merge(T *arr, int left, int mid, int right)
{
    T temp[right - left + 1];

    //辅助数组保存整个要合并的数组
    for (int i = left; i <= right; i ++){
        temp[i - left] = arr[i];
    }

    int i = left, j = mid + 1;//分别对应两部分的头元素
    for (int k = left; k <= right; k ++){
        if (i > mid){//i超过边界的情况，前一部分已经合并完成
            arr[k] = temp[j - left];
            j ++;
        }else if (j > right){//j超过边界的情况，后一部分已经合并完成
            arr[k] = temp[i - left];
            i ++;
        }else if (temp[i - left] < temp[j - left]){//较小值放入前方
            arr[k] = temp[i - left];
            i ++;
        }else{
            arr[k] = temp[j - left];
            j ++;
        }
    }
    return;
}
template <typename T>
void __mergeSort(T *arr, int left, int right)
{
    if (left >= right)
        return;
    int mid = (left + right) / 2;

    __mergeSort(arr, left, mid);
    __mergeSort(arr, mid + 1, right);
    if (arr[mid] > arr[mid + 1])
        __merge(arr,left, mid, right);

    return;
}

template <typename T>
void mergeSort(T *arr, int n)
{
    __mergeSort(arr, 0, n - 1);
    return;
}

/*
 * 快速排序
 * 时间复杂度O(nlogn)
 * 取一个基准值（一般为第一个），将小于该基准值的放于其之前，大于该基准值的放于之后
 * 然后对前面与后面两部分分别进行如上操作
 */

template <typename T>
int __patition(T *arr, int l, int r)
{
    int v = arr[l];//第一个为基准值
    int  j = l;//[l + 1,j]小于基准值，[j + 1,i]大于基准值

    //遍历数组，若大于基准值，则i直接后移，若小于基准值，则需要将该元素放置到小于基准值的区间中，与j + 1交换，然后j++即可
    for (int i = l + 1; i <= r; i ++){
        if (arr[i] < v)
        {
            swap(arr[i],arr[j + 1]);//与第一个大于基准值的交换值
            j ++;//第一个大于基准值的位置后移一位
        }
    }
    swap(arr[j], arr[l]);//将基准位置l与最后一个小于基准值j进行位置交换，即j以前的均小于基准值，以后的将大于基准值
    return j;
}

template <typename T>
void __quickSort(T *arr, int l, int r)
{
    if (l >= r)
        return;

    int p = __patition(arr, l , r);
    __quickSort(arr, l, p - 1);
    __quickSort(arr, p + 1, r);
    return;
}

template <typename T>
void quickSort(T *arr, int n)
{
    __quickSort(arr, 0, n - 1);
    return;
}
#endif //SORT_SORTFUN_H
