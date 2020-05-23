#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
    
    string stdin;
    int x = 0;
    int y = 0;

    getline(cin, stdin);
    stringstream s(stdin);
    s >> x;
    s >> y;
    char field[x][y];
    int ret[x][y];

    for(int i = 0; i < x; i++) {
        getline(cin, stdin);
        stringstream s(stdin);
        for(int j = 0; j < y; j++) {
            ret[i][j] = 0;
            s >> field[i][j];
        }
    }

    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            if(field[i][j] == '*') {
                ret[i][j] = -1;
                int u = i-1;
                int d = i+1;
                int l = j-1;
                int r = j+1;

                bool uc = u >= 0;
                bool dc = d < x;
                bool lc = l >= 0;
                bool rc = r < y;

                ret[u][l] += (uc && lc && ret[u][l] >= 0) ? 1 : 0;
                ret[u][j] += (uc && ret[u][j] >= 0) ? 1 : 0;
                ret[u][r] += (uc && rc && ret[u][r] >= 0) ? 1 : 0;
                ret[i][l] += (lc && ret[i][l] >= 0) ? 1 : 0;
                ret[i][r] += (rc && ret[i][r] >= 0) ? 1 : 0;
                ret[d][l] += (dc && lc && ret[d][l] >= 0) ? 1 : 0;
                ret[d][j] += (dc && ret[d][j] >= 0) ? 1 : 0;
                ret[d][r] += (dc && rc && ret[d][r] >= 0) ? 1 : 0;
            }
        }
    }

    for(int k = 0; k < x; k++) {
        for(int l = 0; l < y; l++) {
            int curr = ret[k][l];
            if(curr == -1){
                cout << "*";
            } else {
                cout << ret[k][l];
            }
        }
        cout << endl;
    }

    return 0;
}