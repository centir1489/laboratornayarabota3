#pragma once
#ifndef AVLTREE
#define AVLTREE
#include<iostream>
#include"QueuePlusPlus.h"


class AVLTree{
private:
    struct ANode{
        int data;
        ANode* Left;
        ANode* Right;
        size_t height;

        ANode(int value) : data(value), Left(nullptr), Right(nullptr), height(1) {}
    };

    ANode* root;

    size_t height(ANode* node){
        return node ? node -> height : 0;
    }

    size_t getBalance(ANode* node){
        return node ? height(node -> Left) - height(node -> Right) : 0;
    }

    ANode* rightRotate(ANode* y){
        ANode* x = y -> Left;
        ANode* T2 = x -> Right;

        x -> Right = y;
        y -> Left = T2;

        y -> height = std::max(height(y -> Left), height(y -> Right)) + 1;
        x -> height = std::max(height(x -> Left), height(x -> Right)) + 1;

        return x;
    }

    ANode* leftRotate(ANode* x){
        ANode* y = x -> Right;
        ANode* T2 = y -> Left;

        y -> Left = x;
        x -> Right = T2;

        x -> height = std::max(height(x -> Left), height(x -> Right)) + 1;
        y -> height = std::max(height(y -> Left), height(y -> Right)) + 1;

        return y;
    }

    ANode* ins(ANode* node, int data){
        if(!node){ 
            return new ANode(data);
        }

        if(data < node->data){
            node->Left = ins(node -> Left, data);
        }
        else if(data > node->data){
            node -> Right = ins(node -> Right, data);
        }
        else{
            return node;
        }
        node->height = 1 + std::max(height(node -> Left), height(node -> Right));

        int balance = getBalance(node);

        // Левый левый случай
        if(balance > 1 && data < node -> Left -> data){
            return rightRotate(node);
        }
        // Правый правый случай
        if(balance < -1 && data > node -> Right -> data){
            return leftRotate(node);
        }

        // kлевый большой
        if(balance > 1 && data > node -> Left -> data){
            node->Left = leftRotate(node -> Left);
            return rightRotate(node);
        }
        //gравый большой
        if(balance < -1 && data < node->Right->data){
            node->Right = rightRotate(node->Right);
            return leftRotate(node);
        }

        return node;
    }

    ANode* minValueNode(ANode* node){
        ANode* bfNode = node;
        while(bfNode && bfNode->Left != nullptr){
            bfNode = bfNode->Left;
        }
        return bfNode;
    }

    ANode* deleteNode(ANode* root, int data){
        if(!root){
            return root;
        }

        if(data < root->data){
            root -> Left = deleteNode(root -> Left, data);
        }
        else if(data > root->data){
            root -> Right = deleteNode(root->Right, data);
        }
        else{
            if(!root -> Left || !root -> Right){
                ANode* tmp = root -> Left ? root -> Left : root -> Right;

                if(!tmp){
                    tmp = root;
                    root = nullptr;
                } 
                else{
                    *root = *tmp;
                }

                delete tmp;
            } 
            else{ 
                ANode* temp = minValueNode(root -> Right);
                root -> data = temp->data;
                root -> Right = deleteNode(root -> Right, temp -> data);
            }
        }

        if(!root){
            return root;
        }

        root -> height = 1 + std::max(height(root -> Left), height(root -> Right));

        int balance = getBalance(root);
        // Левый левый случай
        if(balance > 1 && getBalance(root -> Left) >= 0){
            return rightRotate(root);
        }
        // Левый правый случай
        if(balance > 1 && getBalance(root -> Left) < 0){
            root -> Left = leftRotate(root -> Left);
            return rightRotate(root);
        }
        // Правый правый случай
        if(balance < -1 && getBalance(root -> Right) <= 0){
            return leftRotate(root);
        }
        if(balance < -1 && getBalance(root -> Right) > 0){
            root -> Right = rightRotate(root -> Right);
            return leftRotate(root);
        }
        return root;
    }

    bool search(ANode* node, int data) {
        if (!node) return false;
        if (data < node->data)
            return search(node->Left, data);
        else if (data > node->data){
            return search(node->Right, data);
        }
        else{
            return true;
        }
    }
    void get_(ANode* NTree) {
        if(NTree == nullptr){
		    return;
        }
        QueuePP<ANode*> queue;
        queue.Push(NTree);
        while(!queue.IsEmpty()){
            ANode* NextNode = queue.Front();
            queue.Pop();

            std::cout << NextNode -> data << " ";

            if(NextNode -> Left != nullptr){
                queue.Push(NextNode -> Left);
            }
            if(NextNode -> Right != nullptr){
                queue.Push(NextNode -> Right);
            }
        }
        std::cout << '\n';
    }

    QueuePP<int> ToQueue(ANode* NTree){
        QueuePP<int> retqueue;
        if(NTree == nullptr){
            return retqueue;
        }
        QueuePP<ANode*> queue;
        queue.Push(NTree);
        while(!queue.IsEmpty()){
            ANode* NextNode = queue.Front();
            queue.Pop();

            retqueue.Push(NextNode -> data);

            if(NextNode -> Left != nullptr){
                queue.Push(NextNode -> Left);
            }
            if(NextNode -> Right != nullptr){
                queue.Push(NextNode -> Right);
            }
        }
        return retqueue;
    }

public:
    AVLTree() : root(nullptr){}

    ANode* getRoot(){
        return root;
    }

    void tinsert(int data) {
        root = ins(root, data);
    }

    void tdel(int data){
        root = deleteNode(root, data);
    }

    void tget(){
        get_(root);
    }

    bool tfind(int data){
        return search(root, data);
    }

    QueuePP<int> AVLTreeToQueue(){
        QueuePP<int> retQueue = ToQueue(root);
        return retQueue;
    }
};



#endif