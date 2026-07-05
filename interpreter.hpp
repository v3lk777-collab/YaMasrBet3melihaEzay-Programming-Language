#pragma once
#include <ctime>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <iostream>

class Interpreter {
private:
    unsigned char tape[30000];
    int data_pointer;

public:
    Interpreter() {
        for (int i = 0; i < 30000; i++) {
            tape[i] = 0;
        }

        data_pointer = 0;
    }

public:
    void interpret(const std::string& code) {
        std::vector<std::string> tokens;
        std::stringstream ss(code);
        std::string word;

        while (ss >> word)
            tokens.push_back(word);

        for (int ip = 0; ip < tokens.size(); ip++) {
            if (tokens[ip] == "اديها") {
                tape[data_pointer]++;
            } else if (tokens[ip] == "اهبد" || tokens[ip] == "هو_انت_عارف_حاجه_في_الامتحان_اصلا_فاهبد") {
                tape[data_pointer] = rand() % 256; 
            } else if (tokens[ip] == "كفاية") {
                tape[data_pointer]--;
            } else if (tokens[ip] == "اللي_بعده" || tokens[ip] == "اللي_بعده_يسطا") {
                data_pointer++;
            } else if (tokens[ip] == "اللي_قبله" || tokens[ip] == "اللي_قبله_يسطا") {
                data_pointer--;
            } else if (tokens[ip] == "انطق") {
                std::cout << tape[data_pointer];
            } else if (tokens[ip] == "خد" || tokens[ip] == "خد_هنا_ياض") {
                std::cin >> tape[data_pointer];
            } else if (tokens[ip] == "طالما") {
                if (tape[data_pointer] == 0) {
                    int depth = 1;
                    while (depth > 0 && ++ip < tokens.size()) {
                        if (tokens[ip] == "طالما") {
                            depth++;
                        } else if (tokens[ip] == "بس_خلاص") {
                            depth--;
                        }
                    }
                }
            } else if (tokens[ip] == "بس_خلاص") {
                if (tape[data_pointer] != 0) {
                    int depth = 1;
                    while (depth > 0 && --ip >= 0) {
                        if (tokens[ip] == "طالما") {
                            depth--;
                        } else if (tokens[ip] == "بس_خلاص") {
                            depth++;
                        }
                    }
                }
            }
        }
    }
};