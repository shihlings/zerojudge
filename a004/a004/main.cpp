//
//  main.cpp
//  a004
//
//  Created by Shih-Ling Shen on 2021-03-22.
//

#include <iostream>

int main() {
    int y;
    while (std::cin >> y) {
        if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
            std::cout << "閏年\n";
        }
        else {
            std::cout << "平年\n";
        }
    }
    return 0;
}
