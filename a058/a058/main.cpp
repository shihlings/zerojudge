//
//  main.cpp
//  a058
//
//  Created by Shih-Ling Shen on 2021-03-24.
//

#include <iostream>
#include <map>

int main() {
    int number, input, results1 = 0, results2 = 0, results3 = 0;
    std::cin >> number;
    for (int loopcount = 0; loopcount < number; ++loopcount) {
        std::cin >> input;
        switch (input % 3) {
            case 0:
                ++results1;
                break;
                
            case 1:
                ++results2;
                break;
                
            case 2:
                ++results3;
                break;
                
            default:
                break;
        }
    }
    std::cout << results1 << ' ' << results2 << ' ' << results3 << '\n';
    return 0;
}
