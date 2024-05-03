//
//  main.cpp
//  a005
//
//  Created by Shih-Ling Shen on 2021-03-22.
//

#include <iostream>

int main() {
    int a, b, c, d, loopcount;
    std::cin >> loopcount;
    while (loopcount--) {
        std::cin >> a >> b >> c >> d;
        if (b - a == d - c) {
            std::cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << d + b - a << '\n';
        }
        else {
            std::cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << d * b / a << '\n';
        }
    }
    return 0;
}
