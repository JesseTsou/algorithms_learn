#include <iostream>
#include <string>
#include "sortTestHelper.h"
#include "student.h"
#include "sortFun.h"

int main() {
    int n = 500000;
    int *arr = sortTestHelper::generaterandomArray(n, 0, n);
    int *arr2 = sortTestHelper::copyIntArrary(arr,n);
    int *arr3 = sortTestHelper::copyIntArrary(arr,n);
    int *arr4 = sortTestHelper::copyIntArrary(arr,n);
    int *arr5 = sortTestHelper::copyIntArrary(arr,n);
    //selectionSort(arr,n);
    //sortTestHelper::printArray(arr, n);

    //sortTestHelper::testSort("selection sort", selectionSort,arr,n);
    //sortTestHelper::testSort("insertion sort", insertionSort,arr2,n);
    //sortTestHelper::testSort("bubble    sort", bubbleSort,arr3,n);
    sortTestHelper::testSort("merge     sort", mergeSort,arr4,n);
    sortTestHelper::testSort("quick     sort", quickSort,arr5,n);
/*
 * 不同类型测试
    float b[5] = {4.1,4.2,0.0,3,0.1};
    selectionSort(b,5);
    sortTestHelper::printArray(b, 5);

    string c[5] = {"e","a","d","c","b"};
    selectionSort(c,5);
    sortTestHelper::printArray(c, 5);

    student d[5] = {{"D",90},{"A",70},{"E",80},{"B",70},{"D",60}};
    selectionSort(d,5);
    sortTestHelper::printArray(d, 5);
*/
    delete[] arr;
    return 0;
}