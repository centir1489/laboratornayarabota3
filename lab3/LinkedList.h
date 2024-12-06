#pragma once
#ifndef LINKED_LIST
#define LINKED_LIST

#include<iostream>


template<typename gen_t>
class LinkedList{
private:
    struct LNode{
        gen_t data;
        LNode* next = nullptr;
        LNode* prev = nullptr;
    };

    LNode* Head;
    LNode* Tail;

public:
    LinkedList() : Head(nullptr), Tail(nullptr) {}

    bool IsEmpty(){
        return Head == nullptr;
    }

    size_t size(){
        if(IsEmpty()){ 
            return 0;
        }
        LNode* ptr = Head;
        size_t size = 0;
        while(ptr){
            size++;
            ptr = ptr -> next;
        }
        return size;
    }

    gen_t front(){
        return Head -> data;
    }

    gen_t back(){
        return Tail -> data;
    }
    
    void push_back(gen_t Value){
        LNode* ptr = new LNode({Value, nullptr});
        if(IsEmpty()){
            Head = ptr;
            Tail = ptr;
            return;
        }
        Tail -> next = ptr;
        Tail = ptr;
    }

    void push_front(gen_t Value){
        LNode* ptr = new LNode({Value, Head});
        if(IsEmpty()){
            Head = ptr;
            Tail = ptr;
            return;
        }
        Head = ptr;
    }

    void get(){
        if(IsEmpty()){ 
            return;
        }
        LNode* ptr = Head;
        while(ptr){
            std::cout << ptr -> data << ' ';
            ptr = ptr -> next;
        }
        std::cout << '\n';
    }


    gen_t find_value(gen_t Value){
        LNode* tmp = Find(Value);
        if(tmp == nullptr){
            return 0;
        }
        return tmp -> data;
    }

    void pop_front(){
        if(IsEmpty()){ 
            return;
        }
        LNode* ptr = Head;
        Head = ptr -> next;
        delete ptr;
    }

    void pop_back(){
        if(IsEmpty()){
            return;
        }
        if(Head == Tail){
            pop_front();
            return;
        }
        LNode* ptr = Head;
        while(ptr -> next != Tail){ 
            ptr = ptr -> next;
        }
        ptr -> next = nullptr;
        delete Tail;
        Tail = ptr;
    }

    void remove_value(gen_t Value){
        if(IsEmpty()){
            return;
        }
        if(Head -> data == Value){
            pop_front();
            return;
        }
        else if(Tail -> data == Value) {
            pop_back();
            return;
        }
        LNode* firstPtr = Head;
        LNode* secondPtr = Head -> next;
        while(secondPtr && secondPtr -> data != Value) {
            secondPtr = secondPtr -> next;
            firstPtr = firstPtr -> next;
        }
        if(!secondPtr){
            std::cout << "---" << '\n';
            return;
        }
        firstPtr -> next = secondPtr -> next;
        delete secondPtr;
    }

private:
    LNode* Find(gen_t Value){
        LNode* tmp = Head;
        while(tmp && tmp -> data != Value){ 
            tmp = tmp->next;
        }
        return (tmp && tmp -> data == Value) ? tmp : nullptr;
    }

};

#endif