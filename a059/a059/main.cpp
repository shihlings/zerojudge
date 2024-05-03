//
//  main.cpp
//  a059
//
//  Created by Shih-Ling Shen on 2021-03-24.
//

#include <iostream>
#include <cmath>

int main() {
    int number;
    std::cin >> number;
    int input[number][2];
    for (int loopcount = 0; loopcount < number; ++loopcount) {
        int tempinput, sqrttempinput;
        std::cin >> tempinput;
        sqrttempinput = sqrt(tempinput);
        if (tempinput > sqrttempinput * sqrttempinput) {
            input[loopcount][0] = sqrttempinput + 1;
        }
        else {
            input[loopcount][0] = sqrttempinput;
        }
        std::cin >> tempinput;
        sqrttempinput = sqrt(tempinput);
        if (tempinput < sqrttempinput * sqrttempinput) {
            input[loopcount][1] = sqrttempinput - 1;
        }
        else {
            input[loopcount][1] = sqrttempinput;
        }
    }
    for (int loopcount = 0; loopcount < number; ++loopcount) {
        int output = 0;
        for (int loopcount1 = 0; loopcount1 <= input[loopcount][1] - input[loopcount][0]; ++loopcount1) {
            output = output + (input[loopcount][0] + loopcount1) * (input[loopcount][0] + loopcount1);
        }
        std::cout << "Case " << loopcount + 1 << ": " << output << '\n';
    }
    return 0;
}
