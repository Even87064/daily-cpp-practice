#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum TokenType {
    IDENTIFIER, NUMBER, STRING_LITERAL,
    EQUAL, SEMICOLON
};

struct Token {
    TokenType type;
    string value;
};

vector<Token> tokenize(const string& s) {
    vector<Token> tokens;
    int n = s.size();
    int i = 0;

    while (i < n) {
        char c = s[i];

        // 跳過空白
        if (isspace(c)) {
            i++;
            continue;
        }

        // 字串 "xxx"
        if (c == '"') {
            int start = i;
            i++; // skip "
            string tmp = "\"";
            while (i < n && s[i] != '"') {
                tmp += s[i];
                i++;
            }
            if (i < n) tmp += "\"";
            i++;  // skip closing "
            tokens.push_back({STRING_LITERAL, tmp});
            continue;
        }

        // identifier：英文開頭
        if (isalpha(c)) {
            string id;
            while (i < n && (isalnum(s[i]) || s[i] == '_')) {
                id += s[i];
                i++;
            }
            tokens.push_back({IDENTIFIER, id});
            continue;
        }

        // 數字
        if (isdigit(c)) {
            string num;
            while (i < n && isdigit(s[i])) {
                num += s[i];
                i++;
            }
            tokens.push_back({NUMBER, num});
            continue;
        }

        // 單字元 token
        if (c == '=') {
            tokens.push_back({EQUAL, "="});
            i++;
            continue;
        }
        if (c == ';') {
            tokens.push_back({SEMICOLON, ";"});
            i++;
            continue;
        }

        // 未知字元（先略過）
        i++;
    }

    return tokens;
}

int main() {
    string input = R"(name="Even"; age=25; city="Taipei";)";
    
    auto tokens = tokenize(input);

    for (auto& t : tokens) {
        cout << "[" << t.value << "]\n";
    }

    return 0;
}
