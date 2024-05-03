//
//  main.cpp
//  a065
//
//  Created by Shih-Ling Shen on 2021-03-24.
//

#include <iostream>

int main() {
    char input [7];
    while (std::cin >> input) {
        for (short loopcount = 0; loopcount < 6; loopcount++) {
            std::cout << abs(input[loopcount + 1] - input[loopcount]);
        }
        std::cout << '\n';
    }
    return 0;
}
