//
// Created by Administrator on 2018/9/17.
//
#include "heap.h"

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
    swap(arr[l],arr[rand()%(r - l + 1) + l]);
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
    srand(time(NULL));
    __quickSort(arr, 0, n - 1);
    return;
}

/*
 * 快速排序
 * 时间复杂度O(nlogn)
 * 取一个基准值（一般为第一个），将小于该基准值的放于其之前，大于该基准值的放于之后
 * 将等于基准点的元素，平均分配到两侧
 */
template <typename T>
int __patition2(T *arr, int l, int r)
{
    swap(arr[l],arr[rand()%(r - l + 1) + l]);
    int v = arr[l];//第一个为基准值
    int i = l + 1, j = r;

    //[l + 1, i) 小于等于v，(j,r]大于等于v
    while(1){
        while(i <= r && arr[i] < v) i ++;
        while(j >= l + 1 && arr[j] > v) j --;
        if (i > j)
            break;
        swap(arr[i], arr[j]);//此时arr[i] 大于等于v，arr[j]小于等于v，将两者交换
        i ++;
        j --;
    }
    swap(arr[l],arr[j]);
    return j;
}

template <typename T>
void __quickSort2(T *arr, int l, int r)
{
    if (l >= r)
        return;

    int p = __patition2(arr, l , r);
    __quickSort2(arr, l, p - 1);
    __quickSort2(arr, p + 1, r);
    return;
}

template <typename T>
void quickSort2(T *arr, int n)
{
    srand(time(NULL));
    __quickSort2(arr, 0, n - 1);
    return;
}

/*
 * 快速排序
 * 时间复杂度O(nlogn)
 * 三路快排
 * 取一个基准值（一般为第一个），将小于该基准值的放于其之前，中间放置等于基准点，大于该基准值的放于之后
 * 然后对大于与小于两部分，进行如上操作
 */
template <typename T>
void __quickSort3way(T *arr, int l, int r)
{
    if (l >= r)
        return;

    swap(arr[l],arr[rand()%(r - l + 1) + l]);
    int v = arr[l];//第一个为基准值

    int i = l + 1;//[lt +1, i)等于v
    int lt = l;//[l + 1,lt]小于v
    int gt = r + 1;//[gt,r]大于v

    while(i < gt){
        if (arr[i] > v){
            swap(arr[i],arr[gt - 1]);
            gt --;
        }else if(arr[i] < v){
            swap(arr[i],arr[lt + 1]);
            lt ++;
            i ++;
        }else{
            i ++;
        }
    }

    swap(arr[l], arr[lt]);

    __quickSort3way(arr, l, lt - 1);
    __quickSort3way(arr, gt, r);
    return;
}

template <typename T>
void quickSort3way(T *arr, int n)
{
    srand(time(NULL));
    __quickSort3way(arr, 0, n - 1);
    return;
}

/*
 * 堆排序
 * 时间复杂度：O(nlogn)
 * 将数组元素插入堆，然后再取出堆元素，即可实现排序
 */
template <typename T>
void heapsort(T *arr, int n)
{
    MaxHeap<T> maxheap = MaxHeap<T> (n);
    for (int i = 0; i < n; i ++){
        maxheap.insert(arr[i]);
    }
    for (int i = n - 1; i >= 0; i --){
        arr[i] = maxheap.extracMax();
    }
}

/*
 * 堆排序
 * 时间复杂度：O(nlogn)
 * heapify：在原数组的基础上构建堆：从最后一个非叶子节点（count/2）开始从后往前（直接根节点），
 * 进行shftdown操作。然后再取出堆元素，即可实现排序。
 */
template <typename T>
void heapsort2(T *arr, int n)
{
    MaxHeap<T> maxheap = MaxHeap<T> (arr,n);

    for (int i = n - 1; i >= 0; i --){
        arr[i] = maxheap.extracMax();
    }
}


/*
 * 堆排序
 * 原地堆排序
 * 时间复杂度：O(nlogn)
 * 在原数组[0,n-1]上使用heapify构建堆
 * 将第一个元素0与最后一个元素n-1进行交换，即最后一个即最大元素
 * 但前面n-1个元素的数组就不是个堆了，使用shiftdown进行建堆
 * 建堆完成后，第一个元素即最大元素，与最后一个元素n-2交换，即n-2即第二大元素
 * 重复以上过程，即完成排序
 */
template <typename T>
void __shiftDown(T *arr, int n, int k)
{
    while(2*k+1 < n){
        int j = 2*k+1;
        if (j + 1 < n && arr[j + 1] > arr[j]){
            j += 1;
        }
        if (arr[k] > arr[j])
            break;
        swap(arr[j], arr[k]);
        k = j;
    }
    return;
}

template <typename T>
void heapsort3(T *arr, int n)
{
    for(int i = (n-1)/2; i >= 0; i --){
        __shiftDown(arr, n, i);
    }

    for (int i = n - 1; i > 0; i --){
        swap(arr[0], arr[i]);
        __shiftDown(arr, i, 0);
    }
}
#endif //SORT_SORTFUN_H
