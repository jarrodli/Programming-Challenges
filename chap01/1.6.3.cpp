#include <iostream>
#include <sstream>
#include <algorithm>
#include <math.h>

using namespace std;

int condition(int i, int j) { return i > j; }

int main(int argc, char *argv[]) {
    string stdin;
    int n = 0;

    getline(cin, stdin);
    stringstream in(stdin);
    in >> n;

    while(n != 0) {
        
        double *y = (double *)malloc(sizeof(double) * n);
        double sum = 0.0;

        for(int i = 0; i < n; i++) {
            getline(cin, stdin);
            stringstream in(stdin);
            in >> y[i];
            sum += y[i];
        }

        // round to the nearest .2f number
        double avg = roundf(sum / n * 100) / 100;

        // sort in ascending order
        sort(y, y + (sizeof(double) * n), condition);

        double equaliser = 0.0;

        for(int i = 0; i < (n/2); i++) {
            equaliser += y[i] - avg;
        }

        cout << equaliser << endl;

        free(y);

        getline(cin, stdin);
        stringstream in(stdin);
        in >> n;
    }
    return 0;
}