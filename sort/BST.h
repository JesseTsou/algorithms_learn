//
// Created by Administrator on 2018/10/5.
//
#include <iostream>
#include <queue>
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

    /*
     * 插入
     */
    int insert(key k, value v){
        root = insert(root, k, v);
    }


    /*
     * 是否包含
     */
    bool contain(key k){
        contain(root, k);
    }

    /*
     * 搜索
     */
    value *search(key k){
        search(root, k);
    }

    /*
     * 前序遍历
     */
    void preOrder(){
        preOrder(root);
    }

    /*
     * 中序遍历
     */
    void inOrder() {
        inOrder(root);
    }

    /*
     * 后序遍历
     */
    void postOrder() {
        postOrder(root);
    }

    /*
     * 层序遍历
     */
    void levelOrder(){
        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()){
            Node *node = q.front();
            q.pop();

            cout << node->k << endl;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        return;
    }

    /*
     * 释放
     */
    void destroy(){
        destroy(root);
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

    void preOrder(Node *node){
        if (node != NULL){
            cout << node->k << endl;
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void inOrder(Node *node){
        if (node != NULL){
            inOrder(node->left);
            cout << node->k << endl;
            inOrder(node->right);
        }
    }

    void postOrder(Node *node){
        if (node != NULL){
            postOrder(node->left);
            postOrder(node->right);
            cout << node->k << endl;
        }
    }

    void destroy(Node *node){
        if (node != NULL){
            destroy(node->left);
            destroy(node->right);
            delete node;
            count --;
        }
    }

};


#endif //SORT_BST_H
