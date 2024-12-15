#ifndef STACK_PLUS_PLUS
#define STACK_PLUS_PLUS

#include<iostream>
#include<cstdint>
#include<initializer_list>
#include"Massiv.h"

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

    void binSerialize(const std::string& filename) {
        std::ofstream ofs(filename, std::ios::binary);
        if(!ofs){
            throw std::runtime_error("Не удалось открыть файл");
        }

        size_t size = this -> SSize();
        ofs.write(reinterpret_cast<const char*>(&size), sizeof(size));

        
        SNodePP* ptr = Top;
        while(ptr){
            ofs.write(reinterpret_cast<const char*>(&ptr -> data), sizeof(gen_t));
            ptr = ptr -> next;
        }

        ofs.close();
    }

    void binDeserialize(const std::string& filename) {
        std::ifstream ifs(filename, std::ios::binary);
        if(!ifs){
            throw std::runtime_error("Не удалось открыть файл");
        }
        size_t size = this -> SSize();
        ifs.read(reinterpret_cast<char*>(&size), sizeof(size));

        while(Top){
            SPOP();
        }
        Massiv<gen_t> bfMass;
        for(size_t q = 0; q < size; ++q){
            gen_t value;
            ifs.read(reinterpret_cast<char*>(&value), sizeof(gen_t));
            bfMass.MPUSH(value);
        }
        for(size_t q = 0; q < size; ++q){
            SPUSH(bfMass[size - 1 - q]);
        }
        

        ifs.close();
    }
};





#endif