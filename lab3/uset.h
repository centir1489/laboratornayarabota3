#pragma once
#ifndef U_SET
#define U_SET

#include<iostream>
#include<math.h>


const double GoldenRatio_ = 0.6180339887;

class uSet {
public:
    std::string* table;
    size_t size;
    size_t length;

    uSet(): size(16), length(0), table(new std::string[16]){}

    uSet(size_t size) : size(size), length(0){ 
        table = new std::string[size];
    }

private:
    bool CheckLengthTable(std::string Value){
        length = SETLength();
        if(size == length && SET_AT(Value) == true){
            return true;
        }
        return false;
    }

    size_t SummASCI(std::string Value){
            size_t Summ;
            for(size_t q = 0; q < Value.length(); q++){
                Summ += size_t(Value[q]);
            }
            return Summ;
        }  

    size_t HashFn(std::string Value){
        size_t summ = SummASCI(Value);
        double first = summ * GoldenRatio_;
        double second = first - int(first);
        size_t Pos = size_t(size * second);
        return Pos;
    }  

    bool CheckIndex(size_t Index, std::string Value){
        if(table[Index] == Value || table[Index] == ""){
            return true;
        }
        return false;
    }

    size_t FindIndex(std::string Value){
        size_t Index = HashFn(Value);
        size_t size = this -> size;
        bool isFreeIndex = CheckIndex(Index, Value);
        while(!isFreeIndex && size--){
            if(!CheckIndex(Index, Value)){
                Index++;
                Index %= this -> size;
                isFreeIndex = CheckIndex(Index, Value);
                continue;   
            }
        }
        return Index;
    }

public:
    size_t SETLength(){
        size_t Amount = 0;
        for(size_t q = 0; q < size; q++){
            if(table[q] != ""){
                Amount += 1;
            }
        }
        return Amount;
    } 

    void SETADD(std::string Value){
        if(CheckLengthTable(Value)){
            std::cout << "filled Set\n";
            return;
        }
        size_t Index = FindIndex(Value);
        table[Index] = Value;
    }

    void SETGET(){
        length = SETLength();
        if(length == 0){
            return;
        }
        for(size_t q = 0; q < size; q++){
            if(table[q] == ""){
                continue;
            }
            std::cout << q << '\t' << table[q] << '\n';
        }  
        std::cout << '\n';
    }

    void SETGETLINE(){
        length = SETLength();
        if(length == 0){
            return;
        }
        for(size_t q = 0; q < size; q++){
            if(table[q] == ""){
                continue;
            }
            std::cout << table[q] << ' ';
        }  
        std::cout << '\n';
    }

    void SETDEL(std::string Value){
        table[FindIndex(Value)] = "";
    }

    bool SET_AT(std::string Value){
        if(table[FindIndex(Value)] == Value){
            return true;
        }
        return false;
    }
    
};

#endif