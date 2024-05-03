//
//  main.cpp
//  a009
//
//  Created by Shih-Ling Shen on 2021-03-22.
//

#include <iostream>

int main() {
    std::string str;
    std::cin >> str;
    for (int i = 0; i < str.length(); ++i) {
        char letter = str[i] - 7;
        std::cout << letter;
    }
    std::cout << '\n';
    return 0;
}
