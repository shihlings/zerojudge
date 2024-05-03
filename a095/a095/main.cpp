//
//  main.cpp
//  a095
//
//  Created by Shih-Ling Shen on 2021-03-26.
//

#include <iostream>

int main() {
    int total, red;
    while (std::cin >> total >> red) {
        if (total == red) {
            std::cout << red << '\n';
        }
        else {
            std::cout << red + 1 << '\n';
        }
    }
    return 0;
}
