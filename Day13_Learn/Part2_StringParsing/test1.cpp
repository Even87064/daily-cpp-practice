#include <bits/stdc++.h>
using namespace std;

vector<string> splitBySpace(const string& s) {
    vector<string> result;
    int start = 0;

    while(true){
        int pos = s.find(' ', start);

        if(pos == string::npos){
            result.push_back(s.substr(start));
            break;
        }
        result.push_back(s.substr(start, pos - start));
        start = pos + 1;
    }
    return result;
}

int main() {
    auto v = splitBySpace("I love BMC firmware");
    for (auto& w : v) cout << w << "\n";
}