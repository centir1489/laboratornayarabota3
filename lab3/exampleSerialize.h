#ifndef EXAMPLE_SERIALIZE
#define EXAMPLE_SERIALIZE
#include"AuxiliaryFile.h"

void treeBinSerialize(){
    AVLTree tree;
    tree.tinsert(10);
    tree.tinsert(20);
    tree.tinsert(30);
    tree.tinsert(40);
    tree.tinsert(50);
    tree.tinsert(25);

    std::cout << "До сериализации: ";
    tree.tget();
    tree.binSerialize("tree.bin");


    tree.binDeserialize("tree.bin");
    std::cout << "\nПосле десериализации (удалили 25, проверяем и выводим):\n";
    tree.tdel(25);
    std::cout << "stat: " << tree.tfind(25) << '\n';
    std::cout << "stat: " << tree.tfind(50) << '\n';
    tree.tget();
}

void doublelistBinSerialize(){
    DoubleLinkedList<int> list;
    list.push_back(123);
    list.push_back(12);
    list.push_back(22);
    list.push_back(34);
    std::cout << "До сериализации: ";
    list.get();
    list.binSerialize("binDl.bin");

    
    std::cout << "\nПосле десериализации (добавили 324 и выводим):\n";
    DoubleLinkedList<int> newList;
    newList.binDeserialize("binDl.bin");
    newList.push_back(324);
    newList.get();
}

void linkedlistBinSerialize(){
    LinkedList<int> list;
    list.push_back(123);
    list.push_back(12);
    list.push_back(22);
    list.push_back(34);

    std::cout << "До сериализации: ";
    list.get();
    list.binSerialize("binDl.bin");

    std::cout << "\nПосле десериализации (добавили 324 и выводим):\n";
    LinkedList<int> newList;
    newList.binDeserialize("binDl.bin");
    newList.push_back(324);
    newList.get();
}

void stackBinSerialize(){
    StackPP<int> stack;
    stack.SPUSH(1);
    stack.SPUSH(2);
    stack.SPUSH(3);
    stack.SPUSH(4);
    std::cout << "До сериализации: ";
    stack.SGET();
    stack.binSerialize("binStack.bin");
    
    StackPP<int> newStack;
    newStack.binDeserialize("binStack.bin");
    std::cout << "\nПосле сериализации: ";
    newStack.SGET();
}

void queueBinSerialize(){
    QueuePP<int> queue;
    queue.Push(1);
    queue.Push(2);
    queue.Push(3);
    queue.Push(4);
    std::cout << "До сериализации: ";
    queue.Get();
    queue.binSerialize("binQueue.bin");
    
    QueuePP<int> newQueue;
    newQueue.binDeserialize("binQueue.bin");
    std::cout << "\nПосле сериализации: ";
    newQueue.Get();
}

void massivBinSerialize(){
    Massiv<int> mass = {1, 2, 3, 4, 5, 6, 7, 8};
    std::cout << "До сериализации: ";
    mass.MGET();
    mass.binSerialize("binMass.bin");
    
    std::cout << "\nПосле десериализации: ";
    Massiv<int> newMass;
    newMass.binDeserialize("binMass.bin");
    newMass.MGET();
}

void htBinSerialize(){
    HashTable ht;
    
    ht.HPUSH("ABC", "ABC");
    ht.HPUSH("324", "ABC");
    ht.HPUSH("Linux", "Debian");
    std::cout << "До сериализации: ";
    ht.HGET();
    ht.binSerialize("HashTable.bin");
    
    std::cout << "\nПосле сериализации сериализации: ";
    HashTable newHT;
    newHT.binDeserialize("HashTable.bin");
    std::cout << "\nЕсть ли ABC: " << newHT.HFIND("ABC") << '\n';
    newHT.HGET();
}


void treeJsonSerialize(){
    AVLTree tree;
    tree.tinsert(10);
    tree.tinsert(20);
    tree.tinsert(30);
    tree.tinsert(40);
    tree.tinsert(50);
    tree.tinsert(25);

    std::cout << "До сериализации: ";
    tree.tget();
    IntegData entry_tree = AVLTreeToEntry(tree);
    entry_tree.Name = "AVL";
    PushJSON("binSer.json", entry_tree);

    std::cout << "\nПосле десериализации: ";
    entry_tree = readintegJSON("binSer.json", "AVL", 7);
    AVLTree newtree = convertAVLTree(entry_tree);
    newtree.tget();
}

void htJsonSerialize(){
    HashTable ht;

    ht.HPUSH("324", "ABC");
    ht.HPUSH("Linux", "Debian");
    ht.HPUSH("ABC", "ABC");
    std::cout << "До сериализации:\n";
    ht.HGET();

    HData entry_ht = HTToEntry(ht);
    entry_ht.Name = "HT";
    PushJSON("binSer.json", entry_ht);

    std::cout << "\nПосле десериализации:\n";
    entry_ht = readHTJSON("binSer.json", "HT", 6);
    HashTable newHT = convertHT(entry_ht);
    newHT.HGET();
}

void massivJsonSerialize(){
    Massiv<std::string> mass = {"1", "2", "3", "4", "5", "6", "7", "8"};
    std::cout << "До сериализации: ";
    mass.MGET();
    strData entry = MassToEntry(mass);
    entry.Name = "someMassiv";
    PushJSON("binSer.json", entry);

    entry = readstrJSON("binSer.json", "someMassiv", 1);
    
    std::cout << "\nПосле десериализации: ";
    Massiv<std::string> newMass;
    newMass = convertMassiv(entry);;
    newMass.MGET();
}

void stackJsonSerialize(){
    StackPP<std::string> stack = {"1", "2", "3", "4", "5", "6", "7", "8"};
    std::cout << "До сериализации: ";
    stack.SGET();
    strData entry = StackToEntry(stack);
    entry.Name = "someStack";
    PushJSON("binSer.json", entry);

    entry = readstrJSON("binSer.json", "someStack", 4);
    
    std::cout << "\nПосле десериализации: ";
    StackPP<std::string> newStack;
    newStack = convertStack(entry);;
    newStack.SGET();
}

void queueJsonSerialize(){
    QueuePP<std::string> queue;
    queue.Push("1");
    queue.Push("2");
    queue.Push("3");
    queue.Push("4");
    std::cout << "До сериализации: ";
    queue.Get();
    strData entry = QueueToEntry(queue);
    entry.Name = "someQueue";
    PushJSON("binSer.json", entry);

    entry = readstrJSON("binSer.json", "someQueue", 5);
    
    std::cout << "\nПосле десериализации: ";
    QueuePP<std::string> newQueue;
    newQueue = convertQueue(entry);;
    newQueue.Get();
}

void doublelistJsonSerialize(){
    DoubleLinkedList<std::string> list;
    list.push_back("1");
    list.push_back("2");
    list.push_back("3");
    list.push_back("4");
    std::cout << "До сериализации: ";
    list.get();

    strData entry = DoubleLinkedListToEntry(list);
    entry.Name = "someDoubleLinkedList";
    PushJSON("binSer.json", entry);

    
    std::cout << "\nПосле десериализации: ";
    entry = readstrJSON("binSer.json", "someDoubleLinkedList", 3);
    DoubleLinkedList<std::string> newList = converDoubletLinkedList(entry);    
    newList.get();
}

void linkedlistJsonSerialize(){
    LinkedList<std::string> list;
    list.push_back("1");
    list.push_back("2");
    list.push_back("3");
    list.push_back("4");
    
    std::cout << "До сериализации: ";
    list.get();
    strData entry = LinkedListToEntry(list);
    entry.Name = "someLinkedList";
    PushJSON("binSer.json", entry);

    
    std::cout << "\nПосле десериализации: ";
    entry = readstrJSON("binSer.json", "someLinkedList", 2);
    LinkedList<std::string> newList = convertLinkedList(entry);    
    newList.get();
}   





#endif