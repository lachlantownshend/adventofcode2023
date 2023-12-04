#include <fstream>
#include <iostream>
#include <map>

int main(void){

    std::ifstream infile("input.txt");
    std::string line;

    int id, blue, red, green;

    int MAX_RED = 12;
    int MAX_GREEN = 13;
    int MAX_BLUE = 14;
    
    std::map<char, uint16_t> max_val = {
        {'r', 12},
        {'g', 13},
        {'b', 14}
    };

    uint16_t num, left, right;
    uint16_t total = 0;
    char colour;
    bool valid;

    while(std::getline(infile, line)){

        left = line.find(":") + 2;

        valid = true;

        while(valid && left < line.length()){

            right = left + 1;

            while(isdigit(line[right])){right++;};
            if(right > line.length()){break;}

            num = stoi(line.substr(left, right - left));

            colour = (char)line[right+1];

            if(num > max_val[colour]){
                valid = false;
            }

            left = right;

            while(left != line.length() && !isdigit(line[left])){left++;};
        }
        if(valid){
            id = stoi(line.substr(5, line.find(':') - 5));
            total += id;
        }
    }
    std::cout << "Output: " << total << '\n';
}