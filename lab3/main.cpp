#include"WorkMainFile.h"

// ./main --file Zfirstjsonfile.json --query SPUSH myStack item
int main(int argc, char* argv[]){
    //перенос необходимых данных в массив
    Massiv<std::string> controlMass = argvToMass(argc, argv);

    // процесс распределения запрошенного
    std::string NameFile, Command, NameStructur, Value1, Value2;
    assignmentProcess(controlMass, NameFile, Command, NameStructur, Value1, Value2);
    //проверка команд
    CheckCommand(Command);
    // Работа с терминалом
    WorkTerminal(NameFile, Command, NameStructur, Value1, Value2);
    
    return 0;
}