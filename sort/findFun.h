//
// Created by Administrator on 2018/10/5.
//

#ifndef SORT_FINDFUN_H
#define SORT_FINDFUN_H


#include <iostream>
using namespace std;

/*
 * 二分查找法
 * 循环的实现
 */
template <typename T>
int binarySearch(T *arr, int n, T target)
{
    int l = 0,r = n - 1;
    while (l <= r){
        //int mid = (l + r)/2;
        int mid = l + (r - l)/2;
        if (arr[mid] == target){
            return mid;
        }else if(target < arr[mid]){
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    return -1;
}

/*
 * 二分查找法
 * 递归的实现
 */

template <typename T>
int __binarySearch(T *arr, int r, int l, T target)
{
    if (r < l)
        return -1;
    int mid = l + (r - l)/2;
    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return __binarySearch(arr, mid + 1, r, target);
    else
        return __binarySearch(arr, r, mid - 1, target);
}

template <typename T>
int binarySearch2(T *arr, int n, T target)
{
    return __binarySearch(arr, 0, n - 1, target);
}


#endif //SORT_FINDFUN_H