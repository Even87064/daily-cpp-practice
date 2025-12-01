#include <bits/stdc++.h>
using namespace std;

int main() {
    string line;
    getline(cin, line);

    istringstream iss(line);

    string token;
    while (iss >> token) {
        cout << "token: " << token << endl;
    }
    return 0;
}
