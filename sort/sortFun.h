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
 * 堆
 * 用数组存储二叉堆
 *
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
     * 取出根节点元素后，将最后一个元素填补根节点的位置，保持完全二叉树的形态，
     * 然后需要将该树高调整为最大堆：根节点与两个子节点比较，若子节点大于根节点，
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

#endif //SORT_SORTFUN_H
