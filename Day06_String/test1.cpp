#include <bits/stdc++.h>
using namespace std;
int main(){
    string s = "[09:20:11] VOLT=12.5 CURR=3.2 STATUS=OK";
    string line = s;
    istringstream iss(line);
    string time, volt, curr, status;
    iss >> time >> volt >> curr >> status;
    float voltn = stof(volt.substr(5));
    float currn = stof(curr.substr(5));
    string statusn = status.substr(7);

    cout << "time is:" << time << endl;
    cout << "volt is:" << voltn << endl;
    cout << "curr is:" << currn << endl;
    cout << "status is:" << statusn << endl;
}