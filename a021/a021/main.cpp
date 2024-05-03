//
//  main.cpp
//  a021
//
//  Created by Shih-Ling Shen on 2021-03-26.
//

#include <iostream>
#include <stdio.h>
#include <math.h>

#define debugging

std::string add (char input1[501], char input2[501], unsigned long length1, unsigned long length2) {
    std::string outputtemp, output;
    int tempstorage;
    char outputchar, carry = '0';
    bool larger = length2 > length1;
    if (larger) {
        std::swap(length1, length2);
        std::swap(input1, input2);
    }
    for (int loopcount = 0; loopcount < length1; ++loopcount) {
        if (loopcount >= length2 && length1 != length2) {
            tempstorage = input1[length1 - loopcount - 1] - '0' + carry - '0';
        }
        else {
            tempstorage = input1[length1 - loopcount - 1] - '0' + input2[length2 - loopcount - 1] - '0' + carry - '0';
        }
        if (tempstorage > 9) {
            tempstorage -= 10;
            carry = '1';
        }
        else {
            carry = '0';
        }
        outputchar = tempstorage + '0';
        outputtemp.push_back(outputchar);
    }
    if (carry != '0') {
        outputtemp.push_back(carry);
    }
    for (unsigned long loopcount = outputtemp.size(); loopcount > 0; --loopcount) {
        output.push_back(outputtemp.at(loopcount - 1));
    }
    return output;
}

std::string subtract (char input1[501], char input2[501], unsigned long length1, unsigned long length2) {
    std::string output;
    int tempstorage = 0, outputtemp = 0;
    char borrow[501];
    bool swap = false;
    if (length2 > length1) {
        swap = true;
    }
    else if (length1 == length2) {
        for (int loopcount = 0; loopcount < length1; ++loopcount) {
            if (input1[loopcount] < input2[loopcount]) {
                swap = true;
                break;
            }
            else if (input1[loopcount] > input2[loopcount]) {
                swap = false;
                break;
            }
            else if (input1[loopcount] == input2[loopcount] && loopcount + 1 == length1) {
                output = "0";
                return output;
            }
        }
    }
    if (swap) {
        std::swap(length1, length2);
        std::swap(input1, input2);
    }
    for (int loopcount = 0; loopcount < length1; ++loopcount) {
        if (loopcount > 0 && loopcount + 1 == length1) {
            borrow[loopcount] = input1[loopcount] + 10;
        }
        else if (loopcount > 0) {
            borrow[loopcount] = input1[loopcount] + 9;
        }
        else if (loopcount == 0){
            borrow[loopcount] = input1[loopcount] - 1;
        }
        if (loopcount < length1 - length2) {
            tempstorage = borrow[loopcount] - '0';
        }
        else {
            tempstorage = borrow[loopcount] - input2[loopcount - length1 + length2];
        }
        if (tempstorage > 9) {
            ++outputtemp;
            tempstorage -= 10;
        }
        if (loopcount != 0) {
            output.push_back(outputtemp + '0');
        }
        outputtemp = tempstorage;
    }
    output.push_back(tempstorage + '0');
    output.erase(0, fmin(output.find_first_not_of('0'), output.size() - 1));
    if (swap) {
        output = '-' + output;
    }
    return output;
}

std::string multiply (char input1[501], char input2[501], unsigned long length1, unsigned long length2) {
    char outputchar, carry = '0';
    bool larger = length2 > length1;
    std::string output, tempstorage;
    if (larger) {
        std::swap(length1, length2);
        std::swap(input1, input2);
    }
//    for (int loopcount = 0; loopcount < length2; ++loopcount) {
//        input2[length1 - 1 - loopcount] = input2 [length2 - 1 - loopcount];
//    }
//    for (int loopcount = 0; loopcount < length1 - length2; ++loopcount) {
//        input2[loopcount] = '0';
//    }
//    length2 = length1;
#ifdef debugging
    std::cerr << "input1 swapped " << input1 << '\n' << "input2 swapped " << input2 << '\n';
    std::cerr << "length 1 " << length1 << '\n';
    std::cerr << "length 2 " << length2 << '\n';
#endif
    for (int loopcount = 0; loopcount < length2; ++loopcount) {
        for (int loopcount1 = 0; loopcount1 < length1; ++loopcount1) {
            tempstorage[loopcount + loopcount1] = tempstorage[loopcount + loopcount1] + (input1[length1 - loopcount1 - 1] - '0') * (input2[length2 - loopcount - 1] - '0');
#ifdef debugging
            std::cerr << tempstorage[loopcount + loopcount1] + (input1[loopcount1] - '0') * (input2[loopcount] - '0') << '\n';
#endif
        }
    }
    for (int loopcount = 0; loopcount < tempstorage.size(); ++loopcount) {
        output[loopcount] = tempstorage[tempstorage.size() - loopcount - 1];
    }
    return output;
}

std::string divide (char input1[501], char input2[501], unsigned long length1, unsigned long length2) {
    std::string output;
    bool swap;
    if (length2 > length1) {
        std::swap(length1, length2);
        std::swap(input1, input2);
    }
    else if (length1 == length2) {
        for (int loopcount = 0; loopcount < length1; ++loopcount) {
            if (input1[loopcount] < input2[loopcount]) {
                swap = true;
                break;
            }
            else if (input1[loopcount] > input2[loopcount]) {
                swap = false;
                break;
            }
            else if (input1[loopcount] == input2[loopcount] && loopcount + 1 == length1) {
                output = '1';
                return output;
            }
        }
    }
    return 0;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
#ifdef debugging
    std::cerr << ">>>DEBUGGING MODE ON<<<\n";
#endif
    char input1[501];
    char input2[501];
    char operation;
    while (std::cin >> input1 >> operation >> input2) {
#ifdef debugging
        std::cerr << input1 << ' ' << operation << ' ' << input2 << '\n';
#endif
        unsigned long length1 = strlen(input1);
        unsigned long length2 = strlen(input2);
        switch (operation) {
            case '+':
                std::cout << add(input1, input2, length1, length2) << '\n';
                break;
                
            case '-':
                std::cout << subtract(input1, input2, length1, length2) << '\n';
                break;
                
            case '*':
                std::cout << multiply(input1, input2, length1, length2) << '\n';
                break;
                
            case '/':
                std::cout << divide(input1, input2, length1, length2) << '\n';
                break;
                
            default:
                break;
        }
    }
    return 0;
}
