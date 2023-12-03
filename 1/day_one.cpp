#include <fstream>
#include <iostream>
#include <ctype.h>


int find_word(const std::string &s, const int &index){

    if(isdigit(s[index])){
        return (int)s[index] - '0';
    }

    int str_len = s.length();

    if(index + 2 > str_len){
        return 0;
    }
    if(s.substr(index, 3) == "one"){
        return 1;
    }
    if(s.substr(index, 3) == "two"){
        return 2;
    }
    if(s.substr(index, 3) == "six"){
        return 6;
    }
    if(index + 3 > str_len){
        return 0;
    }
    if(s.substr(index, 4) == "four"){
        return 4;
    }
    if(s.substr(index, 4) == "five"){
        return 5;
    }
    if(s.substr(index, 4) == "nine"){
        return 9;
    }
    if(index + 4 > str_len){
        return 0;
    }
    if(s.substr(index, 5) == "three"){
        return 3;
    }
    if(s.substr(index, 5) == "seven"){
        return 7;
    }
    if(s.substr(index, 5) == "eight"){
        return 8;
    }
    return 0;
}

int main(void){
    std::ifstream infile("input.txt");
    std::string line;
    long output = 0;
    int line_length;
    int val;

    while(std::getline(infile, line)){
        line_length = line.length();

        for(int i = 0; i < line_length; ++i){

            val = find_word(line, i);
            if(val){
                output += val * 10;
                break;
            }
        }

        for(int i = line_length - 1; i >= 0; --i){

            val = find_word(line, i);
            if(val){
                output += val;
                break;
            }
        }
    }
    std::cout << "Output Number: " << output << '\n';
}

