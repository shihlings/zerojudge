//
//  main.cpp
//  a003
//
//  Created by Shih-Ling Shen on 2021-03-22.
//

#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
    switch ((a * 2 + b) % 3) {
        case 0:
            std::cout << "普通";
            break;
            
        case 1:
            std::cout << "吉";
            break;
            
        case 2:
            std::cout << "大吉";
            break;
    }
 return 0;
}
