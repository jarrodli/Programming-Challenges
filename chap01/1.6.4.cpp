#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {

    string stdin;
    int max = 9;
    int buff[max];
    int n = 0;

    getline(cin, stdin);
    stringstream in(stdin);
    in >> n;

    while(n != 0) {
        int nn = 0;
        int tmp = 0;

        // skip space in stdin    
        buff[nn] = in.get();

        while((tmp = in.get()) != EOF) {
            buff[nn] = tmp - '0';
            nn++;
        }

        bool pt[10] = {1,0,1,1,0,1,1,1,1,1};
        bool pm[10] = {0,0,1,1,1,1,1,0,1,1};
        bool pb[10] = {1,0,1,1,0,1,1,0,1,1};

        int ps1[10] = {2,1,1,1,2,0,0,1,2,2};
        int ps2[10] = {2,1,0,1,1,1,2,1,2,1};

        int height = (2*n) + 3;
        for(int i = 0; i < height; i++) {
            for(int j = 0; j < nn; j++) {

                bool chk = i % (n+1) == 0;
                
                if(chk) {
                    // handle rows
                    if((pt[buff[j]] && i == 0) 
                       || (pm[buff[j]] && i == n+1)
                       || (pb[buff[j]] && i == 2*(n+1))) {
                        // print line
                        cout << " ";
                        for(int k = 0; k < n; k++) {
                            cout << "-";
                        }
                        cout << " ";
                    } else {
                        for(int k = 0; k < n + 2; k++) {
                            cout << " ";
                        }
                    }
                } else {
                    // handle columns
                    int col = height/2;
                    if((ps1[buff[j]] == 0 && i < col)
                      || (ps2[buff[j]] == 0 && i > col)) {
                        // print left side
                        for(int l = 0; l < n + 2; l++) {
                            if(l == 1) {
                                cout << "|";
                            } else {
                                cout << " ";
                            }
                        }
                    } else if((ps1[buff[j]] == 1 && i < col) 
                            || (ps2[buff[j]] == 1 && i > col)) {
                        // print right side
                        for(int l = 0; l < n + 2; l++) {
                            if(l == n+1) {
                                cout << "|";
                            } else {
                                cout << " ";
                            }
                        }
                    } else {
                        // print both sides
                        for(int l = 0; l < n + 2; l++) {
                            if(l == 0 || l == n+1) {
                                cout << "|";
                            } else {
                                cout << " ";
                            }
                        }
                    }
                }
                cout << " "; 
            }
            cout << endl;
        }
        getline(cin, stdin);
        in.clear();
        in.str(stdin);
        in >> n;
    }

    return 0;
}