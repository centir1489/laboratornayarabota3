#pragma once
#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST
#include<iostream>

template<typename gen_t>
class DoubleLinkedList{
private:
    struct DNode{
        gen_t data;
        DNode* next = nullptr;
        DNode* prev = nullptr;
    };

    DNode* Head;
    DNode* Tail;
    DNode* Find(gen_t Value){
        DNode* tmp = Head;
        while(tmp && tmp -> data != Value){ 
            tmp = tmp->next;
        }
        return (tmp && tmp -> data == Value) ? tmp : nullptr;
    }
    
public:

    DoubleLinkedList() : Head(nullptr), Tail(nullptr) {}

    bool IsEmpty(){
        return Head == nullptr;
    }

    gen_t front(){
        return Head -> data;
    }

    gen_t back(){
        return Tail -> data;
    }
    size_t size(){
        if(IsEmpty()){ 
            return 0;
        }
        DNode* ptr = Head;
        size_t size = 0;
        while(ptr){
            size++;
            ptr = ptr -> next;
        }
        return size;
    }



    void push_back(gen_t Value){
        DNode* ptr = new DNode({Value, nullptr, Tail});
        if(IsEmpty()){
            Head = ptr;
            Tail = ptr;
            return;
        }
        Tail -> next = ptr;
        Tail = ptr;
    }

    void push_front(gen_t Value){
        DNode* ptr = new DNode({Value, Head, nullptr});
        if(IsEmpty()){
            Head = ptr;
            Tail = ptr;
            return;
        }
        Head = ptr;
    }


    void pop_front(){
        if(IsEmpty()){
            return;
        }
        DNode* ptr = Head;
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
        Tail = Tail -> prev;
        Tail -> next = nullptr;
    }

    gen_t find_value(gen_t Value){
        DNode* tmp = Find(Value);
        if(tmp == nullptr){
            return gen_t();
        }
        return tmp -> data;
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
        DNode* firstPtr = Head;
        DNode* secondPtr = Head -> next;
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

    void get(){
        if(IsEmpty()){
            return;
        }
        DNode* ptr = Head;
        while(ptr){
            std::cout << ptr -> data << ' ';
            ptr = ptr -> next;
        }
        std::cout << '\n';
    }
};
#endif