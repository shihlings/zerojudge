//
//  main.cpp
//  a054
//
//  Created by Shih-Ling Shen on 2021-03-24.
//

#include <iostream>
#include <map>

int main() {
    std::string input;
    int calculation;
    std::cin >> input;
    std::map<char,int> letters = {
        {'A',10},
        {'B',11},
        {'C',12},
        {'D',13},
        {'E',14},
        {'F',15},
        {'G',16},
        {'H',17},
        {'I',34},
        {'J',18},
        {'K',19},
        {'L',20},
        {'M',21},
        {'N',22},
        {'O',35},
        {'P',23},
        {'Q',24},
        {'R',25},
        {'S',26},
        {'T',27},
        {'U',28},
        {'V',29},
        {'W',32},
        {'X',30},
        {'Y',31},
        {'Z',33},
    };
    calculation = (input.at(0) - '0') * 8 + (input.at(1) - '0') * 7 + (input.at(2) - '0') * 6 + (input.at(3) - '0') * 5 + (input.at(4) - '0') * 4 + (input.at(5) - '0') * 3 + (input.at(6) - '0') * 2 + (input.at(7) - '0') * 1 + (input.at(8) - '0') * 1;
    for (char letter = 'A'; letter <= 'Z'; letter++) {
        if ((20 - (letters[letter] % 10 * 9 + letters[letter] / 10) % 10 - calculation % 10) % 10 == 0) {
            std::cout << letter;
        }
    }
    return 0;
}
