#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("log.txt");
    if (!fin.is_open()) {
        cout << "log.txt 無法開啟\n";
        return 1;
    }

    string line;
    while (getline(fin, line)) {
        istringstream iss(line);

        string time, volt, curr, status;
        iss >> time >> volt >> curr >> status;

        float voltn = stof(volt.substr(5));
        float currn = stof(curr.substr(5));
        string statusn = status.substr(7);

        // TODO: 判斷 STATUS != OK
        if (statusn != "OK") {
            cout << "[異常] "
                 << "Time: " << time
                 << " Volt: " << voltn
                 << " Curr: " << currn
                 << " Status: " << statusn
                 << endl;
        }
    }

    return 0;
}
