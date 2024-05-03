//
//  main.cpp
//  a044
//
//  Created by Shih-Ling Shen on 2021-03-24.
//

#include <iostream>

int main() {
    int number;
    while (std::cin >> number) {
        std::cout << (number * number * number + 5 * number + 6 ) / 6 << '\n';
    }
    return 0;
}
