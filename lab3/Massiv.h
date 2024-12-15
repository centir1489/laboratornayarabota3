#pragma once
#ifndef MASSIV
#define MASSIV
#include<iostream>
#include<cstdint>
#include <initializer_list>

template<typename gen_t>
class Massiv{
public:
    gen_t* Data;
    size_t Size; 
    size_t Capacity;

    Massiv() : Capacity(1), Size(0), Data(new gen_t[1]){}
    
    Massiv(size_t initCapacity) : Capacity(initCapacity), Size(0), Data(new gen_t[initCapacity]) {}

    Massiv(std::initializer_list<gen_t> mass){
        Data = new gen_t[mass.size()];
        Size = mass.size();
        Capacity = mass.size();
        size_t q = 0;
        for(gen_t item : mass){
            Data[q++] = item;
        }
    }

    gen_t& operator[](size_t index) {
        if(index < 0 || index >= Size){
            throw std::out_of_range("INDEX_OUT");
        }
        return Data[index];
    }

    void MGET(){
        if(Size == 0){
            return;
        }
        for(size_t q = 0; q < Size; q++){
            std::cout << Data[q] << ' ';
        }
        std::cout << '\n';
    }

    size_t MLength(){
        return Size;
    }

    void Resize(size_t Capacity) {
        gen_t* Data = new gen_t[Capacity];
        for(size_t q = 0; q < Size; q++) {
            Data[q] = this -> Data[q];
        }
        delete[] this -> Data;
        this -> Data = Data;
        this -> Capacity = Capacity;
    }

    void MPUSH(gen_t Value){
        if(Size == Capacity){
            Resize(2 * Capacity);
        }
        Data[Size++] = Value;
    }

    void MPushIndex(size_t index, gen_t Value){
        if(index >= Size || index < 0){
            return;
        }
        if(Size == Capacity){
            Resize(2 * Capacity);
        }
        gen_t bf1 = Data[index];
        Data[index] = Value;
        gen_t bf2;
        for(size_t q = index + 1; q < Size + 1; q++){
            bf2 = Data[q];
            Data[q] = bf1;
            bf1 = bf2;
            
        }
        Size++;
    }

    void MPOP(size_t index){
        if(index >= Size || index < 0){
            return;
        }
        for(size_t q = index; q < Size - 1; q++) {
            Data[q] = Data[q + 1];
        }
        Size--;
    }

    void binSerialize(const std::string& filename) {
        std::ofstream ofs(filename, std::ios::binary);
        if(!ofs){
            throw std::runtime_error("Не удалось открыть файл");
        }
        ofs.write(reinterpret_cast<const char*>(&Size), sizeof(Size));
        ofs.write(reinterpret_cast<const char*>(&Capacity), sizeof(Capacity));

        ofs.write(reinterpret_cast<const char*>(Data), Size * sizeof(gen_t));

        ofs.close();
    }

    
    void binDeserialize(const std::string& filename) {
        std::ifstream ifs(filename, std::ios::binary);
        if(!ifs){
            throw std::runtime_error("Не удалось открыть файл");
        }
        ifs.read(reinterpret_cast<char*>(&Size), sizeof(Size));
        ifs.read(reinterpret_cast<char*>(&Capacity), sizeof(Capacity));

        delete[] Data;
        Data = new gen_t[Capacity];

        ifs.read(reinterpret_cast<char*>(Data), Size * sizeof(gen_t));
        ifs.close();
    }
};

#endif