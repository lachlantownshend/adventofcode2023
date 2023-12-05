#include <fstream>
#include <iostream>
#include <vector>
#include <ctype.h>
#include <cmath>
#include <unordered_map>
#include <tuple>

bool isvalid(const char val){
    return val == '*';
}

int main(void){
    std::ifstream infile("input.txt");
    std::string line;
    std::vector<std::vector<char>> v;
    int j = 0;
    std::vector<char> lil;
    std::unordered_map<std::string, std::vector<int>> gear_coords;
    std::string current_coords;

    while(std::getline(infile, line)){
        lil = {};
        for(int i = 0; i < line.length(); ++i){
            lil.push_back(line[i]);
        }
        v.push_back(lil);
    }

    std::vector<int> num = {};
    uint64_t total = 0;

    for(uint16_t i = 0; i < v.size(); ++i){
        for(uint16_t j = 0; j < v[i].size(); ++j){

            if(isdigit(v[i][j])){
                num.push_back((int)v[i][j] - '0');
                if(current_coords.length()){continue;}

                if(i < v.size() - 1){

                    if(isvalid(v[i+1][j])){current_coords = std::to_string(i+1) + '.' + std::to_string(j);continue;}
            
                    if(j < v[i].size() - 1){
                        if(isvalid(v[i+1][j+1])){current_coords = std::to_string(i+1) + '.' + std::to_string(j+1);continue;}
                    }

                    if(j > 0){
                        if(isvalid(v[i+1][j-1])){current_coords = std::to_string(i+1) + '.' + std::to_string(j-1);continue;}
                    }
                }
        
                if(j < v[i].size() - 1){
                    if(isvalid(v[i][j+1])){current_coords = std::to_string(i) + '.' + std::to_string(j+1);continue;}
                }

                if(j > 0){
                    if(isvalid(v[i][j-1])){current_coords = std::to_string(i) + '.' + std::to_string(j-1);continue;}
                }

                if(i > 0){

                    if(j < v[i].size() - 1){
                        if(isvalid(v[i-1][j+1])){current_coords = std::to_string(i-1) + '.' + std::to_string(j+1);continue;}
                    }

                    if(isvalid(v[i-1][j])){current_coords = std::to_string(i-1) + '.' + std::to_string(j);continue;}

                    if(j > 0){
                        if(isvalid(v[i-1][j-1])){current_coords = std::to_string(i-1) + '.' + std::to_string(j-1);continue;}
                    }
                }
            }
            else if(num.size() && current_coords.size()){
                total = 0;
                for(int i=0;i<num.size();++i){
                    total += pow(10, (num.size() - i - 1)) * num[i];
                }
                gear_coords[current_coords].push_back(total);
                num = {};
                current_coords = "";
            }
            else if(num.size()){
                num = {};

            }
        }
        if(num.size()){
            if(current_coords.length()){
                total = 0;
                for(int i=0;i<num.size();++i){
                    total += pow(10, (num.size() - i - 1)) * num[i];
                }
                gear_coords[current_coords].push_back(total);
            }
            current_coords = "";
            num = {};
        }
        
    }
    total = 0;
    for (auto const& [key, val] : gear_coords){
        if(val.size() == 2){
            total += val[0] * val[1];
        }

    }
    std::cout<< "Total gear ratio: " << total << '\n';
}