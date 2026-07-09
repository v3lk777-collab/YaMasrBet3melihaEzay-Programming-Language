#include "interpreter.hpp"
#include <fstream>
#include <iostream>

int main(int argc, char* argv[]) {
    srand(time(0));

    std::string line;
    std::string code;
    std::string filePath;

    if (argc < 2) {
        std::cout << "Enter file path: ";
        
        std::cin >> filePath;
    } else {
        filePath = argv[1];
    }

    std::ifstream YaMasrBet3melihaEzayCodeFile(filePath);
   
    if (!YaMasrBet3melihaEzayCodeFile.is_open())
        throw std::runtime_error("Error: Couldn't open YaMasrBet3melihaEzay file");
    
    while (std::getline(YaMasrBet3melihaEzayCodeFile, line))
        code += line + "\n";
    
    YaMasrBet3melihaEzayCodeFile.close();

    Interpreter YaMasrBet3melihaEzayInterpreter;
    YaMasrBet3melihaEzayInterpreter.interpret(code);

    return 0;
}