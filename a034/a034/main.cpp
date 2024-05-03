//
//  main.cpp
//  a034
//
//  Created by Shih-Ling Shen on 2021-03-22.
//

#include <iostream>

int main() {
    int input;
    while (std::cin >> input) {
        int a[16] = {0}, b = 0;
        while (input != 0) {
            a[b] = input % 2;
            input = input / 2;
            b++;
        }
        for (int loopcount = b - 1; loopcount >= 0; --loopcount) {
            std::cout << a[loopcount];
        }
        std::cout << '\n';
    }
    return 0;
}
