#pragma once
#include <iostream>
#include <fstream>
#include"GeneralHeader.h"

using json = nlohmann::json;

std::string definieTypeStructu(size_t codeStructu){
    if(codeStructu == 1){
        return "Massiv";
    }
    else if(codeStructu == 2){
        return "LinkedList";
    }
    else if(codeStructu == 3){
        return "DoubleLinkedList";
    }
    else if(codeStructu == 4){
        return "Stack";
    }
    else if(codeStructu == 5){
        return "Queue";
    }
    else if(codeStructu == 6){
        return "HashTable";
    }
    else if(codeStructu == 7){
        return "AVL-Tree";
    }
    else if(codeStructu == 8){
        return "Set";
    }
    return "";
}

struct HData{
    std::string Name;
    std::string Structu;
    std::string* Key;
    std::string* Data; 
    size_t Size;       
    size_t Capacity;
};

HashTable convertHT(HData entry){
    HashTable convHashTable(entry.Capacity);
    for(size_t q = 0; q < entry.Size; q++){
        convHashTable.HPUSH(entry.Key[q], entry.Data[q]);
    }
    return convHashTable;
}


HData HTToEntry(HashTable ht){
    HData entry;
    entry.Structu = "HashTable";
    entry.Size = ht.HSize();
    entry.Capacity = ht.Capacity;

    entry.Data = new std::string[ht.HSize()];
    entry.Key = new std::string[ht.HSize()];

    Massiv<std::string> MassKey = ht.HTToMassKey();
    Massiv<std::string> MassData = ht.HTToMassData();
    for(size_t q = 0; q < MassKey.MLength(); q++){
        entry.Key[q] = MassKey[q];
        entry.Data[q] = MassData[q];
    }
    return entry;
}

struct strData{
    std::string Name;
    std::string Structu;
    std::string* Data; 
    size_t Size;       
    size_t Capacity;
};



Massiv<std::string> convertMassiv(strData entry){
    Massiv<std::string> convMasiv;
    convMasiv.Size = entry.Size;
    convMasiv.Capacity = entry.Capacity;
    convMasiv.Data = entry.Data;
    return convMasiv;
}

LinkedList<std::string> convertLinkedList(strData entry){
    LinkedList<std::string> convLinkedList;
    for(size_t q = 0; q < entry.Size; q++){
        convLinkedList.push_back(entry.Data[q]);
    }
    return convLinkedList;
}

DoubleLinkedList<std::string> converDoubletLinkedList(strData entry){
    DoubleLinkedList<std::string> convDoubleLinkedList;
    for(size_t q = 0; q < entry.Size; q++){
        convDoubleLinkedList.push_back(entry.Data[q]);
    }
    return convDoubleLinkedList;
}

StackPP<std::string> convertStack(strData entry){
    StackPP<std::string> convStack;
    for(size_t q = 0; q < entry.Size; q++){
        convStack.SPUSH(entry.Data[q]);
    }
    return convStack;
}

QueuePP<std::string> convertQueue(strData entry){
    QueuePP<std::string> convQueue;
    for(size_t q = 0; q < entry.Size; q++){
        convQueue.Push(entry.Data[q]);
    }
    return convQueue;
}

uSet convertSet(strData entry){
    uSet bfSet(entry.Capacity);
    for(size_t q = 0; q < entry.Size; q++){
        if(entry.Data[q] != ""){
            bfSet.SETADD(entry.Data[q]);
        }
    }
    return bfSet;
}



strData MassToEntry(Massiv<std::string> mass){
    strData entry;
    entry.Structu = "Massiv";
    entry.Size = mass.Size;
    entry.Capacity = mass.Capacity;
    entry.Data = new std::string[mass.Size];
    for(size_t q = 0; q < mass.Size; q++){
        entry.Data[q] = mass[q];
    }
    return entry;
}

strData LinkedListToEntry(LinkedList<std::string> list){
    strData entry;
    entry.Structu = "LinkedList";
    entry.Size = list.size();
    entry.Data = new std::string[entry.Size];
    entry.Capacity = entry.Size;
    size_t pos = 0;
    while(!list.IsEmpty()){
        entry.Data[pos++] = list.front();
        list.pop_front();
    }
    return entry;
}

strData DoubleLinkedListToEntry(DoubleLinkedList<std::string> list){
    strData entry;
    entry.Structu = "DoubleLinkedList";
    entry.Size = list.size();
    entry.Data = new std::string[entry.Size];
    entry.Capacity = entry.Size;
    size_t pos = 0;
    while(!list.IsEmpty()){
        entry.Data[pos++] = list.front();
        list.pop_back();
    }
    return entry;
}

strData StackToEntry(StackPP<std::string> nStack){
    strData entry;
    entry.Structu = "Stack";
    entry.Size = nStack.SSize();
    entry.Data = new std::string[entry.Size];
    entry.Capacity = entry.Size;
    size_t pos = 0;
    while(!nStack.IsEmpty()){
        entry.Data[pos++] = nStack.top();
        nStack.SPOP();
    }
    return entry;
}

strData QueueToEntry(QueuePP<std::string> queue){
    strData entry;
    entry.Structu = "Queue";
    entry.Size = queue.Size();
    entry.Capacity = entry.Size;
    entry.Data = new std::string[entry.Size];
    size_t pos = 0;
    while(!queue.IsEmpty()){
        entry.Data[pos++] = queue.Front();
        queue.Pop();
    }
    return entry;
}

strData SetToEntry(uSet set){
    strData entry;
    entry.Structu = "Set";
    entry.Size = set.SETLength();
    entry.Capacity = set.size;
    entry.Data = new std::string[entry.Size];
    size_t pos = 0;
    for(size_t q = 0; q < set.size; q++){
        if(set.table[q] != ""){
            entry.Data[pos++] = set.table[q];
        }
    }
    return entry;
}


struct IntegData{
    std::string Name;
    std::string Structu;
    int* Data; 
    size_t Size;
};

AVLTree convertAVLTree(IntegData entry){
    AVLTree avl;
    for(size_t q = 0; q < entry.Size; q++){
        avl.tinsert(entry.Data[q]);
    }
    return avl;
}

IntegData AVLTreeToEntry(AVLTree avl){
    IntegData entry;
    entry.Structu = "AVL-Tree";
    QueuePP<int> avlQueue = avl.AVLTreeToQueue();
    entry.Size = avlQueue.Size();
    size_t pos = 0;
    while(!avlQueue.IsEmpty()){
        entry.Data[pos++] = avlQueue.Front();
        avlQueue.Pop();
    }
    return entry;
}


void PushJSON(const std::string& filename, const strData& structEntry){
    json jsFile;
    std::ifstream inputFile(filename);
    if(inputFile.is_open()){
        inputFile >> jsFile;
        inputFile.close();
    }
    json bfMas = json::array();
    for(size_t q = 0; q < structEntry.Size; q++){
        bfMas.push_back(structEntry.Data[q]);
    }

    jsFile[structEntry.Name] = {
        {"Data", bfMas},
        {"Size", structEntry.Size},
        {"Structu", structEntry.Structu},
        {"Capacity", structEntry.Capacity}
    };

    std::ofstream outputFile(filename);
    outputFile << jsFile.dump(4);
    outputFile.close();
}

void PushJSON(const std::string& filename, const HData& structEntry){
    json jsFile;
    std::ifstream inputFile(filename);
    if(inputFile.is_open()){
        inputFile >> jsFile;
        inputFile.close();
    }
    json bfMas = json::array();
    for(size_t q = 0; q < structEntry.Size; q++){
        bfMas.push_back({{"Key", structEntry.Key[q]}, {"Value", structEntry.Data[q]}});
    }

    jsFile[structEntry.Name] = {
        {"Data", bfMas},
        {"Size", structEntry.Size},
        {"Structu", structEntry.Structu},
        {"Capacity", structEntry.Capacity}
    };

    std::ofstream outputFile(filename);
    outputFile << jsFile.dump(4);
    outputFile.close();
}


void PushJSON(const std::string& filename, const IntegData& structEntry){
    json jsFile;
    std::ifstream inputFile(filename);
    if(inputFile.is_open()){
        inputFile >> jsFile;
        inputFile.close();
    }
    json bfMas = json::array();
    for(size_t q = 0; q < structEntry.Size; q++){
        bfMas.push_back(structEntry.Data[q]);
    }

    jsFile[structEntry.Name] = {
        {"Data", bfMas},
        {"Size", structEntry.Size},
        {"Structu", structEntry.Structu},
    };

    std::ofstream outputFile(filename);
    outputFile << jsFile.dump(4); 
    outputFile.close();
}



strData readstrJSON(const std::string& filename, const std::string& name, const size_t codeStructu){
    json jsFile;
    std::ifstream inputFile(filename);
    if(inputFile.is_open()){
        inputFile >> jsFile;
        inputFile.close();
    }

    std::string entrstruct = definieTypeStructu(codeStructu);
    if(jsFile.contains(name) && entrstruct == jsFile[name]["Structu"].get<std::string>()){
        strData structEntry;
        structEntry.Name = name;
        structEntry.Structu = jsFile[name]["Structu"].get<std::string>();
        structEntry.Size = jsFile[name]["Size"].get<size_t>();
        structEntry.Capacity = jsFile[name]["Capacity"].get<size_t>();
        
        structEntry.Data = new std::string[structEntry.Capacity];
        for(size_t q = 0; q < structEntry.Size; q++){
            structEntry.Data[q] = jsFile[name]["Data"][q].get<std::string>();
        }
        return structEntry;
    } 
    else{
        throw std::runtime_error("не нашли то что хотели");
    }
}

IntegData readintegJSON(const std::string& filename, const std::string& name, const size_t codeStructu){
    json jsFile;
    std::ifstream inputFile(filename);
    if(inputFile.is_open()){
        inputFile >> jsFile;
        inputFile.close();
    }
    std::string entrstruct = definieTypeStructu(codeStructu);
    if(jsFile.contains(name) && entrstruct == jsFile[name]["Structu"].get<std::string>()){
        IntegData structEntry;
        structEntry.Name = name;
        structEntry.Structu = jsFile[name]["Structu"].get<std::string>();
        structEntry.Size = jsFile[name]["Size"].get<size_t>();
        
        structEntry.Data = new int[structEntry.Size];
        for(size_t q = 0; q < structEntry.Size; q++){
            structEntry.Data[q] = jsFile[name]["Data"][q].get<int>();
        }
        return structEntry;
    }
    else{
        throw std::runtime_error("не нашли то что хотели");
    }
}

HData readHTJSON(const std::string& filename, const std::string& name, const size_t codeStructu) {
    json jsFile;
    std::ifstream inputFile(filename);
    if(inputFile.is_open()){
        inputFile >> jsFile;
        inputFile.close();
    } 
    else{
        throw std::runtime_error("Не удалось открыть файл");
    }
    std::string entrstruct = definieTypeStructu(codeStructu);
    if(jsFile.contains(name) && entrstruct  == jsFile[name]["Structu"].get<std::string>()){
        HData structEntry;
        structEntry.Name = name;
        structEntry.Structu = jsFile[name]["Structu"].get<std::string>();
        structEntry.Size = jsFile[name]["Size"].get<size_t>();
        structEntry.Capacity = jsFile[name]["Capacity"].get<size_t>();

        structEntry.Key = new std::string[structEntry.Size];
        structEntry.Data = new std::string[structEntry.Size];

        for(size_t q = 0; q < structEntry.Size; q++){
            structEntry.Key[q] = jsFile[name]["Data"][q]["Key"].get<std::string>();
            structEntry.Data[q] = jsFile[name]["Data"][q]["Value"].get<std::string>();
        }
        return structEntry;
    } 
    else{
        throw std::runtime_error("Не нашли то что хотели");
    }
}
