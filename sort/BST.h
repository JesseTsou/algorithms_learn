//
// Created by Administrator on 2018/10/5.
//
#include <iostream>
#ifndef SORT_BST_H
#define SORT_BST_H

template <typename key, typename value>
class BST {
    struct Node{
        key k;
        value v;
        Node *left;
        Node *right;

        Node (key k, value v){
            this->k = k;
            this->v = v;
            this->left = this->right = NULL;
        }
    };

    Node *root;
    int count;
public:
    BST(){
        root = NULL;
        count = 0;
    }
    ~BST(){

    }

    int size(){
        return count;
    }

    bool isEmpty(){
        return count != 0;
    }

    int insert(key k, value v){
        root = insert(root, k, v);
    }

    bool contain(key k){
        contain(root, k);
    }

    value *search(key k){
        search(root, k);
    }
private:
    Node *insert(Node *node, key k, value v){
        if (node == NULL){
            count ++;
            return new Node(k, v);
        }

        if (node->k = k){
            node->v = v;
        }else if (node->k > k){
            node->right = insert(node->right, k, v);
        }else{
            node->left = insert(node->left, k, v);
        }
        return node;
    }

    bool contain(Node *node, key k){
        if (node == NULL)
            return false;

        if (node->k == k)
            return true;
        else if (node->k > k)
            return contain(node->right, k);
        else
            return contain(node->left, k);
    }

    value *search(Node *node, key k){
        if (node == NULL)
            return NULL;

        if (node->k == k)
            return &(node->v);
        else if (node->k > k)
            return search(node->right, k);
        else
            return search(node->left, k);
    }

};


#endif //SORT_BST_H
