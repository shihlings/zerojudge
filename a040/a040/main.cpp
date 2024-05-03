//
//  main.cpp
//  a040
//
//  Created by Shih-Ling Shen on 2021-03-23.
//

#include <iostream>
#include <map>
#include <cmath>
#include <sstream>

int main() {
    static int inputa, inputb;
    {
        std::string tempinput;
        for (int loopcount = 0; loopcount < 2; ++loopcount) {
            std::cin >> tempinput;
            std::stringstream ss;
            ss << tempinput;
            switch (loopcount) {
                case 0:
                    ss >> inputa;
                    break;
                    
                case 1:
                    ss >> inputb;
                    break;
                    
                default:
                    break;
            }
        }
    }
    std::map<int,int> outputmap;
    {
        for (int loopcount = inputa; loopcount <= inputb; ++loopcount) {
            std::string calculation = std::to_string(loopcount);
            int output = 0;
            switch (calculation.size()) {
                case 1:
                    output = (calculation.at(0) - '0');
                    break;
                    
                case 2:
                    output = pow((calculation.at(0) - '0'), 2) + pow((calculation.at(1) - '0'), 2);
                    break;
                    
                case 3:
                    output = pow((calculation.at(0) - '0'), 3) + pow((calculation.at(1) - '0'), 3) + pow((calculation.at(2) - '0'), 3);
                    break;
                    
                case 4:
                    output = pow((calculation.at(0) - '0'), 4) + pow((calculation.at(1) - '0'), 4) + pow((calculation.at(2) - '0'), 4) + pow((calculation.at(3) - '0'), 4);
                    break;
                    
                case 5:
                    output = pow((calculation.at(0) - '0'), 5) + pow((calculation.at(1) - '0'), 5) + pow((calculation.at(2) - '0'), 5) + pow((calculation.at(3) - '0'), 5) + pow((calculation.at(4) - '0'), 5);
                    break;
                    
                case 6:
                    output = pow((calculation.at(0) - '0'), 6) + pow((calculation.at(1) - '0'), 6) + pow((calculation.at(2) - '0'), 6) + pow((calculation.at(3) - '0'), 6) + pow((calculation.at(4) - '0'), 6) + pow((calculation.at(5) - '0'), 6);
                    break;
                    
                case 7:
                    output = pow((calculation.at(0) - '0'), 7) + pow((calculation.at(1) - '0'), 7) + pow((calculation.at(2) - '0'), 7) + pow((calculation.at(3) - '0'), 7) + pow((calculation.at(4) - '0'), 7) + pow((calculation.at(5) - '0'), 7) + pow((calculation.at(6) - '0'), 7);
                    break;
                    
                default:
                    break;
            }
            if (output == loopcount) {
                ++outputmap[loopcount];
            }
        }
    }
    bool none = false;
    for (std::map<int,int>::iterator it=outputmap.begin(); it!=outputmap.end(); ++it) {
        if (it->second == 1) {
            std::cout << it->first << ' ';
            none = true;
        }
    }
    if (none == false) {
        std::cout << "none\n";
    }
    return 0;
}
