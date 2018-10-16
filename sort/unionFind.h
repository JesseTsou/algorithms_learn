//
// Created by Administrator on 2018/10/15.
//

#ifndef SORT_UNIONFIND_H
#define SORT_UNIONFIND_H
#include <cassert>

class unionFind {
private:
    int *id;
    int count;
public:
    unionFind(int n){
        count = n;
        id = new int[n];
        for (int i = 0; i < n; i ++){
            int[i] = i;
        }
    }
    ~unionFind(){
        delete[] id;
    }

    /*
     * 查找
     */
    int find(int p){
        assert(p >= 0 && p <= count);
        return id[p];
    }

    /*
     * 是否连接
     */
    bool isConnected(int p, int q){
        return find(p) == find(q);
    }

    /*
     * 并集，将与p相等的所有节点赋值
     */
    void unionElements(int p, int q){
        int pId = find(p);
        int qId = find(q);

        if (pId == qId)
            return;

        for (int i = 0; i < count; i ++){
            if(id[i] == pId)
                id[i] = qId;
        }
        return;
    }
};


#endif //SORT_UNIONFIND_H
