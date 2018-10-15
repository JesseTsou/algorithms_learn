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

    int find(int p){
        assert(p >= 0 && p <= count);
        return id[p];
    }
};


#endif //SORT_UNIONFIND_H
