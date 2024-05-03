//
//  main.cpp
//  a042
//
//  Created by Shih-Ling Shen on 2021-03-24.
//

#include <iostream>

int main() {
    int number;
    while (std::cin >> number) {
        std::cout << number * number - number + 2 << '\n';
    }
    return 0;
}
