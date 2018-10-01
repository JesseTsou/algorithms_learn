//
// Created by Administrator on 2018/10/1.
//
#include <iostream>
#include <string>
#include <cassert>
using namespace std;
#ifndef SORT_HEAP_H
#define SORT_HEAP_H
/*
 * 堆操作
 * 用数组存储二叉堆
 * 从索引1开始计数
 */
template <typename T>
class MaxHeap
{
private:
    T *data;
    int count;
    int capacity;
    /*
     * 要插入的数与其父节点比较，若大于父节点，则与父节点交换位置，再重复此过程，直到与根节点比较满足条件
     */
    void shiftUp(int k){
        while(k > 1 && data[k] > data[k/2]){
            swap(data[k],data[k/2]);
            k/=2;
        };
        return;
    }
    /*
     * 将树调整为最大堆：根节点与两个子节点比较，若子节点大于根节点，
     * 则与较大的子节点交换位置，然后对于新位置继续对如上比较与交换操作，直到到达最底层为止
     */
    void shiftDown(int k){
        while(2*k <= count){
            int j = 2*k;
            if (j + 1 <= count && data[j + 1] > data[j]){
                j += 1;
            }

            if (data[k] > data[j])
                break;
            swap(data[k], data[j]);
            k = j;
        }
        return;
    }
public:
    MaxHeap(int capacity){
        data = new T[capacity + 1];
        count = 0;
        this->capacity = capacity;
    }
    /*
     * heapify
     */
    MaxHeap(T *arr, int n){
        data = new T[n + 1];
        capacity = n;
        count = n;
        for (int i = 0; i < n; i ++){
            data[i + 1] = arr[i];
        }
        for (int i = n/2; i >= 0; i --){
            shiftDown(i);
        }
    }
    ~MaxHeap(){
        delete []data;
    }

    int size(){
        return count;
    }

    bool isempty()
    {
        return count == 0;
    }

    /*
     * 插入操作
     */
    void insert(T item){
        assert(count + 1 <= capacity    );
        data[count + 1] = item;
        count ++;
        shiftUp(count);
        return;
    }
    void print(){
        for (int i = 1; i <= count; i ++){
            cout << data[i] << " ";
        }
        cout << endl;
        return;
    }

    /*
     * 取出头节点
     * 取出根节点元素后，将最后一个元素填补根节点的位置，保持完全二叉树的形态，
     * 然后需要将该树调整为最大堆：根节点与两个子节点比较，若子节点大于根节点，
     * 则与较大的子节点交换位置，然后对于新位置继续对如上比较与交换操作，直到到达最底层为止
     */
    T extracMax()
    {
        assert(count >= 0);
        T ret = data[1];
        swap(data[1], data[count]);
        count --;
        shiftDown(1);
        return ret;
    }
};



#endif //SORT_HEAP_H
