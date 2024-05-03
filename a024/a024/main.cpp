//
//  main.cpp
//  a024
//
//  Created by Shih-Ling Shen on 2021-03-22.
//

#include <iostream>
#include <map>

int main() {
    int input1, input2, output = 1;
    std::map<int,int> map1;
    std::map<int,int> map2;
    std::map<int,int> map3;
    std::cin >> input1 >> input2;
    {
        int factor = 2;
        while (input1 >= factor) {
            if (input1 % factor == 0) {
                input1 = input1 / factor;
                ++map1[factor];
            }
            else {
                ++factor;
            }
        }
    }
    {
        int factor = 2;
        while (input2 >= factor) {
            if (input2 % factor == 0) {
                input2 = input2 / factor;
                ++map2[factor];
            }
            else {
                ++factor;
            }
        }
    }
    for (std::map<int,int>::iterator it1=map1.begin(); it1!=map1.end(); ++it1){
        if (map2.count(it1->first) > 0) {
            if (map1[it1->first] > map2[it1->first]) {
                map3[it1->first] = map2[it1->first];
            }
            else{
                map3[it1->first] = map1[it1->first];
            }
        }
    }
    for (std::map<int,int>::iterator it3=map3.begin(); it3!=map3.end(); ++it3) {
        for (int loopcount = 0; loopcount < it3->second; ++loopcount) {
            output = it3->first * output;
        }
    }
    std::cout << output << '\n';
    return 0;
}
