//
//  main.cpp
//  a053
//
//  Created by Shih-Ling Shen on 2021-03-24.
//

#include <iostream>

int main() {
    int input, output;
    while (std::cin >> input) {
        if (input >= 40) {
            output = 100;
        }
        else if (input >= 20) {
            output = 60 + input;
        }
        else if (input >= 10) {
            output = 40 + input * 2;
        }
        else {
            output = input * 6;
        }
        std::cout << output;
    }
    return 0;
}
