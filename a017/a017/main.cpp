//
//  main.cpp
//  a017
//
//  Created by Shih-Ling Shen on 2021-03-24.
//

#include <iostream>

#define debugging

int main() {
    char input [256];
    while (std::cin.getline(input, 256)) {
        for (int loopcount = 0; loopcount < 256; ++loopcount) {
            if (input[loopcount] == ' ') {
                for (int loopcount1 = loopcount; loopcount1 < 256; ++loopcount1) {
                    input[loopcount1] = input[loopcount1 + 1];
                }
            }
        }
#ifdef debugging
        std::cerr << input << '\n';
#endif
    }
    return 0;
}
