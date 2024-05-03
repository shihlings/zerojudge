//
//  main.cpp
//  a010
//
//  Created by Shih-Ling Shen on 2021-03-22.
//

#include <iostream>
#include <map>

int main() {
    int num, i = 2;
    std::map<int,int> map;
    std::cin >> num;
    while (i <= num) {
        if (num % i == 0) {
            num = num / i;
            ++map[i];
        }
        else {
            ++i;
        }
    }
    for (std::map<int,int>::iterator it=map.begin(); it!=map.end();) {
        if (it->second == 1) {
            std::cout << it->first;
        }
        else {
            std::cout << it->first << '^' << it->second;
        }
        if ((++it) != map.end()) {
            std::cout << " * ";
        }
    }
    std::cout << '\n';
    return 0;
}
