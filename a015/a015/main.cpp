//
//  main.cpp
//  a015
//
//  Created by Shih-Ling Shen on 2021-03-22.
//

#include <iostream>

int main() {
    int x, y;
    while (std::cin >> x >> y) {
        int input[x][y], output[y][x];
        for (int loopcount = 0; loopcount < x; ++loopcount) {
            for (int loopcount1 = 0, i; loopcount1 < y; ++loopcount1) {
                std::cin >> i;
                input[loopcount][loopcount1] = i;
            }
        }
        for (int loopcount2 = 0; loopcount2 < y; ++loopcount2) {
            for (int loopcount3 = 0; loopcount3 < x; ++loopcount3) {
                output[loopcount2][loopcount3] = input[loopcount3][loopcount2];
            }
        }
        for (int loopcount4 = 0; loopcount4 < y; ++loopcount4) {
            for (int loopcount5 = 0; loopcount5 < x; ++loopcount5) {
                std::cout << output[loopcount4][loopcount5] << ' ';
            }
            std::cout << '\n';
        }
    }
    return 0;
}
