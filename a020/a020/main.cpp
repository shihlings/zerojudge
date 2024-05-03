//
//  main.cpp
//  a020
//
//  Created by Shih-Ling Shen on 2021-03-22.
//

#include <iostream>
#include <map>

int main() {
    std::string input;
    int letternum, first, second;
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
    letternum = letters[input.at(0)];
    first = (letternum % 10) * 9 + (letternum / 10);
    second = (input.at(1) - '0') * 8 + (input.at(2) - '0') * 7 + (input.at(3) - '0') * 6 + (input.at(4) - '0') * 5 + (input.at(5) - '0') * 4 + (input.at(6) - '0') * 3 + (input.at(7) - '0') * 2 + (input.at(8) - '0') * 1 + (input.at(9) - '0') * 1;
    if ((first + second) % 10 == 0) {
        std::cout << "real\n";
    }
    else {
        std::cout << "fake\n";
    }
    return 0;
}
