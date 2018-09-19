//
// Created by Administrator on 2018/9/16.
//

#ifndef SELECTIONSORT_SORTTESTHELPER_H
#define SELECTIONSORT_SORTTESTHELPER_H

#include <iostream>
#include <ctime>
#include <cassert>
using namespace std;

namespace sortTestHelper{
    int * generaterandomArray(int n, int rangeL, int rangeR){
        assert(rangeL <= rangeR);
        int *arr = new int[n];

        srand(time(NULL));

        for (int i = 0; i < n; i ++){
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }

        return arr;
    }

    template <typename T>
    void printArray(T *arr, int n)
    {
        for (int i = 0; i < n; i ++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    template <typename T>
    bool isSorted(T arr[], int n)
    {
        for(int i = 0; i < n - 1; i ++){
            if (arr[i] > arr[i + 1])
                return false;
        }
        return true;
    }
    template <typename T>
    void testSort(string sortName, void (* sort)(T [], int), T arr[], int n)
    {
        clock_t startTime = clock();
        sort(arr,n);
        clock_t endTime = clock();
        //printArray(arr,n);
        assert(isSorted(arr, n));

        cout << sortName << ":"<< double(endTime - startTime)/CLOCKS_PER_SEC << "s"<<endl;
        return;
    }

    int *copyIntArrary(int a[], int n)
    {
        int *arr = new int[n];
        copy(a, a + n, arr);
        return arr;
    }

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
#endif //SELECTIONSORT_SORTTESTHELPER_H
