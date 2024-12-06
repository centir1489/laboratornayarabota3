#ifndef STACK_PLUS_PLUS
#define STACK_PLUS_PLUS

#include<iostream>
#include<cstdint>
#include<initializer_list>


template<typename gen_t>
struct StackPP{
private:
    struct SNodePP{
        gen_t data;
        SNodePP* next = nullptr;
    };
    SNodePP* Top = nullptr;

public:
    StackPP() : Top(nullptr){}
    
    StackPP(std::initializer_list<gen_t> list){
        for(gen_t item : list){
            SNodePP* ptr = new SNodePP{item, Top};
            Top = ptr;
        }
    }

    bool IsEmpty(){
        return Top == nullptr;
    }

    size_t SSize(){
        if(IsEmpty()){
            return 0;
        }
        SNodePP* ptr = Top;
        size_t size = 0;
        while(ptr){
            size++;
            ptr = ptr -> next;
        }
        return size;
    }

    gen_t top(){
        if(IsEmpty()){
            return gen_t();
        }
        return Top -> data;
    }

    void SPUSH(gen_t Value){
        SNodePP* ptr = new SNodePP{Value, Top};
        Top = ptr;
    }

    void SPOP(){
        if(IsEmpty()){
            return;
        }
        SNodePP* ptr = Top;
        Top = ptr -> next;
        delete ptr; 
    }

    void SGET(){
        if(IsEmpty()){
            return;
        }
        SNodePP* ptr = Top;
        while(ptr){
            std::cout << ptr -> data << ' ';
            ptr = ptr -> next;
        }
        std::cout << '\n';
    }
};





#endif