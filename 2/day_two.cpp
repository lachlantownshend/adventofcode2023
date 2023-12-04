#include <fstream>
#include <iostream>
#include <unordered_map>

int main(void){

    std::ifstream infile("input.txt");
    std::string line;

    // Store the minimum values for each colour in a map
    std::unordered_map<char, uint16_t> min_val = {
        {'r', 0},
        {'g', 0},
        {'b', 0}
    };

    uint16_t num, left, right, id;
    uint64_t total = 0;
    char colour;

    // For each line in the file
    while(std::getline(infile, line)){

        // Start at the first number
        left = line.find(":") + 2;

        min_val = {
            {'r', 0},
            {'g', 0},
            {'b', 0}
        };

        // Go until the end of the line
        while(left < line.length()){

            // Look for the final digit of the number
            right = left + 1;
            while(isdigit(line[right])){right++;};
            if(right > line.length()){break;}

            // Take the slice containing the number
            num = stoi(line.substr(left, right - left));

            // The colour is two chars after the number. Update the minimum value
            colour = (char)line[right+1];
            if(num > min_val[colour]){
                min_val[colour] = num;
            }

            // We can start looking from the end of the next number
            left = right;

            // Move until we have found the next digit
            while(left != line.length() && !isdigit(line[left])){left++;};
        }

        // Sum the powers
        total += min_val['r'] * min_val['g'] * min_val['b'];
    }

    std::cout << "Output: " << total << '\n';
}