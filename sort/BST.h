//
// Created by Administrator on 2018/10/5.
//
#include <iostream>
#include <queue>
#ifndef SORT_BST_H
#define SORT_BST_H
/*
 * 二叉树
 */
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
        Node (Node *node){
            this->k = node->k;
            this->v = node->v;
            this->left = node->left;
            this->right = node->right;
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
     * 采用队列的方法
     * 从根节点开始存入队列，出队时，将其左右孩子入队
     * 重复以上操作
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

    /*
     * 查找最小节点
     */
    key mininum(){
        Node* node = mininum(root);
        return node->k;
    }

    /*
     * 删除最小节点
     */
    void removeMin(){
        if (root)
            root = removeMin(root);
        return;
    }


    /*
     * 查找最大节点
     */
    key maxnum(){
        Node* node = maxnum(root);
        return node->k;
    }

    /*
     * 删除最大节点
     */
    void removeMax(){
        if (root)
            root = removeMax(root);
        return;
    }

    void remove(key k){
        if (root)
            root = remove(root, k);
        return;
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

    Node *mininum(Node *node){
        if (node->left == NULL)
            return node;

        return mininum(node->left);
    }

    /*
     * 删除最小值节点时，需要判断其是否有右孩子，若存在则需要将其右孩子替换到该节点位置
     */
    Node *removeMin(Node *node){
        if (node->left == NULL){
            //若不存在右孩子，则rightnode 为NULL
            Node *rightnode = node->right;
            delete node;
            count --;
            return rightnode;
        }
        node->left = removeMin(node->left);
        return node;
    }

    Node *maxnum(Node *node){
        if (node->right == NULL)
            return node;

        return maxnum(node->right);
    }

    /*
     * 删除最大值节点时，需要判断其是否有左孩子，若存在则需要将其左孩子替换到该节点位置
     */
    Node *removeMax(Node *node){
        if (node->right == NULL){
            //若不存在左孩子，leftnode 为NULL
            Node *leftnode = node->left;
            delete node;
            count --;
            return leftnode;
        }
        node->right = removeMax(node->right);
        return node;
    }

    Node *remove(Node *node, key k){
        if (node == NULL)
            return NULL;
        if (k < node-> k){
            node->left = remove(node->left, k);
            return node;
        }else if (k > node->k){
            node->right = remove(node->right, k);
            return node;
        }else{
            //将右子树移到要删除的节点位置
            if (node->left == NULL){
                Node *rightnode = node->right;
                delete node;
                count --;
                return rightnode;
            }
            //将左子树移到要删除的节点位置
            if (node->right == NULL){
                Node *leftnode = node->left;
                delete node;
                count --;
                return leftnode;
            }
            //找到右子树中的最小节点，替换掉要删除的节点
            if (node->left && node->right){
                //创建一个新节点，来保存右子树的最小节点，需要new一下，因为下面要将原该节点删除，实现位置的替换
                Node *minirightnode = new Node(mininum(node->right));
                count ++;

                minirightnode->right = removeMin(node->right);
                minirightnode->left = node->left;

                delete node;
                count --;

                return minirightnode;
            }
        }
    }

};


#endif //SORT_BST_H
