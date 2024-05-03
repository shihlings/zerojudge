//
//  main.cpp
//  a038
//
//  Created by Shih-Ling Shen on 2021-03-22.
//

#include <iostream>

int main() {
    int input;
    std::cin >> input;
    if (input == 0) {
        std::cout << '0';
    }
    else if (input % 10 == 0) {
        while (input % 10 == 0) {
            input = input / 10;
        }
        while (input > 0) {
            std::cout << input % 10;
            input = input / 10;
        }
    }
    else if (input > 0) {
        while (input > 0) {
            std::cout << input % 10;
            input = input / 10;
        }
    }
    return 0;
}
