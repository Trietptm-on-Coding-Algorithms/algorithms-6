/*
ID: gamer371
PROG: milk
LANG: C++
*/

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int N, M;
    int accPrice = 0;
    int UNITS[1001] = {0};

    ifstream input;
    input.open("milk.in");
    input >> N >> M;

    for (int i = 0; i < M; i++) {
        int units, price;
        input >> price >> units;
        UNITS[price] += units;
    }
    input.close();

    int i = 0; // the lowest price iterator
    while (N > 0) {
        if (N - UNITS[i] >= 0) {
            accPrice += UNITS[i] * i;
            N -= UNITS[i];
        } else {
            accPrice += N * i;
            N = 0;
        }
        i++;
    }

    ofstream output;
    output.open("milk.out");
    output << accPrice << "\n";
    output.close();

    return 0;
}
