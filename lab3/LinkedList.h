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

    void binSerialize(const std::string& filename){
        std::ofstream ofs(filename, std::ios::binary);
        if(!ofs){
            throw std::runtime_error("Не удалось открыть файл");
        }

        size_t size = this -> size();
        ofs.write(reinterpret_cast<const char*>(&size), sizeof(size));

        for(LNode* bfNode = Head; bfNode != nullptr; bfNode = bfNode->next){
            ofs.write(reinterpret_cast<const char*>(&bfNode->data), sizeof(gen_t));
        }
        ofs.close();
    }

    
    void binDeserialize(const std::string& filename){
        std::ifstream ifs(filename, std::ios::binary);
        if(!ifs){
            throw std::runtime_error("Не удалось открыть файл");
        }

        while(!IsEmpty()){
            pop_front();
        }

        size_t size;
        ifs.read(reinterpret_cast<char*>(&size), sizeof(size));

        for(size_t q = 0; q < size; ++q){
            gen_t value;
            ifs.read(reinterpret_cast<char*>(&value), sizeof(gen_t));
            push_back(value);
        }
        ifs.close();
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