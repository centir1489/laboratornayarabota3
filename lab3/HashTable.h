#pragma once
#ifndef HASHTABLE
#define HASHTABLE

#include<iostream>
#include<math.h>
#include"Massiv.h"

const double GoldenRatio = 0.6180339887;

class HashTable{
private:    
    struct HNode{
        std::string Key = "";
        std::string Data = "";
    };
    
public:
    HNode* Table;
    size_t Capacity;
    size_t Size = 0;

    HashTable(){
        Table = new HNode[16];      
        Capacity = 16;
    }
    HashTable(size_t Size){
        Table = new HNode[Size];      
        Capacity = Size;
    }

    HNode& operator[](std::string Key){
        Size = HSize();
        size_t FreeIndex = FindIndex(Key);
        return *(Table + FreeIndex);
    }

private:
    bool CheckSizeTable(std::string Key){
        Size = HSize();
        if(Size == Capacity && HFIND(Key) == ""){
            return true;
        }
        return false;
    }
 

    bool CheckIndex(size_t Index, std::string Key){
        if(Table[Index].Key == Key || Table[Index].Key == ""){
            return true;
        }
        return false;
    }

    size_t FindIndex(std::string Key){
        size_t Index = HashFn(Key);
        size_t Capacity = this -> Capacity;
        bool isFreeIndex = CheckIndex(Index, Key);
        while(!isFreeIndex && Capacity--){
            if(!CheckIndex(Index, Key)){
                Index++;
                Index %= this -> Capacity;
                isFreeIndex = CheckIndex(Index, Key);
                continue;   
            }
        }
        return Index;
    }

    size_t SummASCI(std::string Key){
        size_t Summ;
        for(size_t q = 0; q < Key.length(); q++){
            Summ += size_t(Key[q]);
        }
        return Summ;
    }    

    size_t HashFn(std::string Key){
        size_t Summ = SummASCI(Key);
        double first = Summ * GoldenRatio;
        double second = first - int(first);
        size_t Pos = size_t(Capacity * second);
        return Pos;
    }

public:
    size_t HSize(){
        size_t Amount = 0;
        for(size_t q = 0; q < Capacity; q++){
            if(Table[q].Key != ""){
                Amount += 1;
            }
        }
        return Amount;
    }  

    void HGET(){
        Size = HSize();
        if(Size == 0){
            return;
        }
        for(size_t q = 0; q < Capacity; q++){
            if(Table[q].Key == ""){
                continue;
            }
            std::cout << q << '\t' << Table[q].Key << '\t' << Table[q].Data << '\n';
        }  
    }

    void HPUSH(std::string Key, std::string Value){
        if(CheckSizeTable(Key)){
            std::cout << "filled table\n";
            return;
        }
        size_t Pos = FindIndex(Key);
        Table[Pos] = {Key, Value};
    }


    void HDEL(std::string Key){
        size_t Pos = FindIndex(Key);
        if(Table[Pos].Key == ""){
            return;
        }
        Table[Pos] = {"", ""};
    }

    std::string HFIND(std::string Key){
        size_t Pos = FindIndex(Key);
        if(Table[Pos].Key == Key){
            return Table[Pos].Data;
        }
        return "";
    }


    Massiv<std::string> HTToMassKey(){
        Massiv<std::string> bfmass;
        Size = HSize();
        if(Size == 0){
            return bfmass;
        }
        for(size_t q = 0; q < Capacity; q++){
            if(Table[q].Key == ""){
                continue;
            }
            bfmass.MPUSH(Table[q].Key);
        }
        return bfmass;
    } 

    Massiv<std::string> HTToMassData(){
        Massiv<std::string> bfmass;
        Size = HSize();
        if(Size == 0){
            return bfmass;
        }
        for(size_t q = 0; q < Capacity; q++){
            if(Table[q].Key == ""){
                continue;
            }
            bfmass.MPUSH(Table[q].Data);
        }
        return bfmass;
    }

    void binSerialize(const std::string& filename) {
        std::ofstream ofs(filename, std::ios::binary);
        if(!ofs){
            throw std::runtime_error("Не удалось открыть файл");
        }

        //капасити и сайз
        ofs.write(reinterpret_cast<const char*>(&Capacity), sizeof(Capacity));
        ofs.write(reinterpret_cast<const char*>(&Size), sizeof(Size));

        // Запись узлов
        for(size_t q = 0; q < Capacity; ++q){
            size_t keyLen = Table[q].Key.size();
            size_t dataLen = Table[q].Data.size();

            // длина + значени ключа
            ofs.write(reinterpret_cast<const char*>(&keyLen), sizeof(keyLen));
            ofs.write(Table[q].Key.c_str(), keyLen);

            // длина + значение датыыы
            ofs.write(reinterpret_cast<const char*>(&dataLen), sizeof(dataLen));
            ofs.write(Table[q].Data.c_str(), dataLen);
        }

        ofs.close();
    }


    void binDeserialize(const std::string& filename) {
        std::ifstream ifs(filename, std::ios::binary);
        if (!ifs) {
            throw std::runtime_error("Не удалось открыть файл");
        }
        //капасити и сайз
        ifs.read(reinterpret_cast<char*>(&Capacity), sizeof(Capacity));
        ifs.read(reinterpret_cast<char*>(&Size), sizeof(Size));

        
        delete[] Table;
        Table = new HNode[Capacity];

        for(size_t q = 0; q < Capacity; ++q){
            size_t keyLen;
            size_t dataLen;
            
            ifs.read(reinterpret_cast<char*>(&keyLen), sizeof(keyLen));
            Table[q].Key.resize(keyLen);
            ifs.read(&Table[q].Key[0], keyLen);

            ifs.read(reinterpret_cast<char*>(&dataLen), sizeof(dataLen));
            Table[q].Data.resize(dataLen);
            ifs.read(&Table[q].Data[0], dataLen);
        }

        ifs.close();
    }
};

#endif