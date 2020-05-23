#include <stdio.h>
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {

    string stdin;

    int lowerBound = -1;
    int upperBound = -1;
    int maxCycle = -1;
    int n = 0;

    cin >> stdin;
    stringstream(stdin) >> lowerBound;

    cin >> stdin;
    stringstream(stdin) >> upperBound;

    for(int i = lowerBound; i <= upperBound; i++) {
        int tmp = 1;
        n = i;
        while(n != 1) {
            n = (n % 2 == 0) ? n / 2 : (n * 3) + 1;
            tmp++;
        }
        maxCycle = (tmp > maxCycle) ? tmp : maxCycle;
    }
    printf("%d %d %d\n", lowerBound, upperBound, maxCycle);
    return maxCycle;
}