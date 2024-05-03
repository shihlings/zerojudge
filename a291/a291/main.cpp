//
//  main.cpp
//  a291
//
//  Created by Shih-Ling Shen on 2021-08-23.
//

#include <iostream>
#include <stdio.h>

//#define debugging

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
#ifdef debugging
    std::cerr << ">>>DEBUGGING MODE ON<<<\n";
#endif
    char constcorrect[4];
    while (std::cin >> constcorrect[0] >> constcorrect[1] >> constcorrect[2] >> constcorrect[3]) {
        int numtrials;
#ifdef debugging
        for (int loopcount = 0; loopcount < 4; ++loopcount) {
            std::cerr << constcorrect[loopcount];
        }
        std::cerr << '\n';
#endif
        for (std::cin >> numtrials; numtrials > 0; --numtrials) {                   //executing each trial
            char trial[4], correct[4];
            for (int loopcount = 0; loopcount < 4; ++loopcount) {
                correct[loopcount] = constcorrect[loopcount];
                std::cin >> trial[loopcount];
            }
#ifdef debugging
            for (int loopcount = 0; loopcount < 4; ++loopcount) {
                std::cerr << trial[loopcount];
            }
            std::cerr << '\n';
#endif
            int a = 0, b = 0;
            for (int tests = 0; tests < 4; ++tests) {                               //individual number trial and matching
#ifdef debugging
                std::cerr << "trial[tests] correct[tests]" << trial[tests] << ' ' << correct[tests] << '\n';
#endif
                if (trial[tests] == correct[tests]) {
                    ++a;
                    correct[tests] = 'a';
                    trial[tests] = 'b';
#ifdef debugging
                    std::cerr << "++a" << ' ' << a << '\n';
#endif
                }
            }
            for (int testb = 0; testb < 4; ++testb) {
                for (int testbb = 0; testbb < 4; ++testbb) {
                    if (trial[testb] == 'b') {
                        break;
                    }
#ifdef debugging
                    std::cerr << "trial[testb] correct[testbb]" << trial[testb] << ' ' << correct[testbb] << '\n';
#endif
                    if (trial[testb] == correct[testbb]) {
                        ++b;
                        trial[testb] = 'b';
                        correct[testbb] = 'a';
#ifdef debugging
                        std::cerr << "++b" << ' ' << b << '\n';
#endif
                        break;
                    }
                }
            }
            std::cout << a << "A" << b << "B" << '\n';
        }
    }
    return 0;
}
