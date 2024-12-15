#pragma once
#ifndef QUEUE_PLUS_PLUS   
#define QUEUE_PLUS_PLUS  
#include<iostream>

template<typename gen_t>
class QueuePP{
private:    
    struct QNodePP{
	    gen_t Data;
	    QNodePP* next;
    };
    QNodePP* Head = nullptr;
    QNodePP* Tail = nullptr;

public:
    QueuePP(){}

    bool IsEmpty(){
        return Head == nullptr;
    }

    void Push(gen_t Value){
        QNodePP* NewNode = new QNodePP({Value, nullptr});
        if(IsEmpty()){
            Head = NewNode;
            Tail = NewNode;
            return;
        }
        Tail -> next = NewNode;
        Tail = NewNode;
    }

    void Pop(){
        if(IsEmpty()){
            return;
        }
        QNodePP* NewNode = Head;
        Head = NewNode -> next;
        delete NewNode;
    }
    size_t Size(){
        if(IsEmpty()){
            return 0;
        }
        size_t Amount = 0;
        QNodePP* ptr = Head;
        while(ptr){
            Amount++;
            ptr = ptr -> next;
        }
        return Amount;
    }

    void Get(){
        if(IsEmpty()){
            return;
        }
        QNodePP* ptr = Head;
        while(ptr){
            std::cout << ptr -> Data << ' ';
            ptr = ptr -> next;
        }
        std::cout << '\n'; 
    }

    gen_t Front(){
        if(IsEmpty()){
            return gen_t();
        }
        return Head -> Data;
    }
    gen_t Back(){
        if(IsEmpty()){
            return gen_t();
        }
        return Tail -> Data;
    } 

     void binSerialize(const std::string& filename){
        std::ofstream ofs(filename, std::ios::binary);
        if(!ofs){
            throw std::runtime_error("Не удалось открыть файл");
        }
        size_t Size = this -> Size();
        ofs.write(reinterpret_cast<const char*>(&Size), sizeof(Size));

        QNodePP* ptr = Head;
        while(ptr){
            ofs.write(reinterpret_cast<const char*>(&ptr -> Data), sizeof(gen_t));
            ptr = ptr -> next;
        }

        ofs.close();
    }

    void binDeserialize(const std::string& filename) {
        std::ifstream ifs(filename, std::ios::binary);
        if(!ifs){
            throw std::runtime_error("Не удалось открыть файл");
        }
        size_t Size = this -> Size();
        ifs.read(reinterpret_cast<char*>(&Size), sizeof(Size));

        while(Head){
            Pop();
        }
        for(size_t q = 0; q < Size; ++q){
            gen_t value;
            ifs.read(reinterpret_cast<char*>(&value), sizeof(gen_t));
            Push(value);
        }
        ifs.close();
    }
};
    


#endif