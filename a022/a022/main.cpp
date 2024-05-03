//
//  main.cpp
//  a022
//
//  Created by Shih-Ling Shen on 2021-03-22.
//

#include <iostream>

int main() {
    std::string input;
    std::cin >> input;
    for (int loopcount = 0; loopcount <= input.length(); ++loopcount) {
        if (input[loopcount] != input[input.length() - loopcount - 1]) {
            std::cout << "no";
            break;
        }
        if (input[loopcount] == input[input.length() - loopcount - 1] && (loopcount + 1) == input.length()) {
            std::cout << "yes";
            break;
        }
    }
    return 0;
}
