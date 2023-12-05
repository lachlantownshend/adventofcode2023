#include <fstream>
#include <iostream>
#include <vector>
#include <ctype.h>
#include <cmath>

bool isvalid(const char val){
    if(isalpha(val) || isdigit(val)){
        return false;
    }
    if(val == '.'){
        return false;
    }
    return true;
}

int main(void){
    std::ifstream infile("input.txt");
    std::string line;
    std::vector<std::vector<char>> v;
    int j = 0;
    std::vector<char> lil;

    while(std::getline(infile, line)){
        lil = {};
        for(int i = 0; i < line.length(); ++i){
            lil.push_back(line[i]);
        }
        v.push_back(lil);
    }
    std::cout << v.size() << " " << v[0].size();
    std::vector<int> num = {};
    bool valid = false;
    uint64_t total = 0;
    for(uint16_t i = 0; i < v.size(); ++i){
        for(uint16_t j = 0; j < v[i].size(); ++j){

            if(isdigit(v[i][j])){
                num.push_back((int)v[i][j] - '0');
                if(valid){continue;}

                if(i < v.size() - 1){

                    if(isvalid(v[i+1][j])){valid=true;continue;}
            
                    if(j < v[i].size() - 1){
                        if(isvalid(v[i+1][j+1])){valid=true;continue;}
                    }

                    if(j > 0){
                        if(isvalid(v[i+1][j-1])){valid=true;continue;}
                    }
                }
        
                if(j < v[i].size() - 1){
                    if(isvalid(v[i][j+1])){valid=true;continue;}
                }

                if(j > 0){
                    if(isvalid(v[i][j-1])){valid=true;continue;}
                }

                if(i > 0){

                    if(j < v[i].size() - 1){
                        if(isvalid(v[i-1][j+1])){valid=true;continue;}
                    }

                    if(isvalid(v[i-1][j])){valid=true;continue;}

                    if(j > 0){
                        if(isvalid(v[i-1][j-1])){valid=true;continue;}
                    }
                }
            }
            else if(num.size() && valid){
                
                for(int i=0;i<num.size();++i){
                    total += pow(10, (num.size() - i - 1)) * num[i];
                }
                num = {};
                valid = false;
            }
            else if(num.size()){
                num = {};

            }
        }
        if(num.size()){
            if(valid){
                for(int i=0;i<num.size();++i){
                    total += pow(10, (num.size() - i - 1)) * num[i];
                }
            }
            valid = false;
            num = {};
        }
        
    }
    std::cout<<total << '\n';
}