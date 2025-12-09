#include <bits/stdc++.h>
using namespace std;

pair<string, string> parseKeyValue(const string& s) {
    int pos = s.find('=');
    if (pos == string::npos) return {"", ""};
    string first = s.substr(0, pos);
    string second = s.substr(pos+1);
    return {first, second};
}


int main(){
    auto v = parseKeyValue("TEMP=85");
    //cout << v << endl;  not valid for printing pair 
    cout << v.first << " " << v.second << endl;

}