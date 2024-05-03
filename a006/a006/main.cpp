//
//  main.cpp
//  a006
//
//  Created by Shih-Ling Shen on 2021-03-22.
//

#include <iostream>
#include <cmath>

int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c;
    d = b * b - 4 * a * c;
    if (d == 0) {
        std::cout << "Two same roots x=" << (-1) * b / 2 / a;
    }
    else if (d > 0) {
        std::cout << "Two different roots x1=" << ((-1) * b + sqrt(d)) / 2 / a << " , x2=" << ((-1) * b - sqrt(d)) / 2 / a;
    }
    else {
        std::cout << "No real root";
    }
    return 0;
}
