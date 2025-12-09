# Day09 — String Tokenizer（字串斷詞器）

## 今日目標
- 理解 Token（語意最小單位）
- 使用 linear scan 掃描字串
- 使用 enum + struct 建立 Token 型別
- 解析 identifier、number、string literal、=、;
- 為後續 Parser 做準備

---

## 1. Tokenizer 是什麼？

Tokenizer 會把一整段字串拆成最小語意單位 Token。

範例輸入：

    name="Even"; age=25; city="Taipei";

切成 Token Stream：

    [name]
    [=]
    ["Even"]
    [;]
    [age]
    [=]
    [25]
    [;]
    [city]
    [=]
    ["Taipei"]
    [;]

---

## 2. 本日 Tokenizer 支援語法
- Identifier（字母開頭，可接數字與底線）
- Number（整數）
- String Literal（以 " 包住）
- 符號：=、;
- 自動略過空白

---

## 3. 程式碼（Day09_StringTokenizer/main.cpp）

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

            if (isspace(c)) { i++; continue; }

            if (c == '"') {
                string tmp = "\"";
                i++;
                while (i < n && s[i] != '"') {
                    tmp += s[i];
                    i++;
                }
                if (i < n) tmp += "\"";
                i++;
                tokens.push_back({STRING_LITERAL, tmp});
                continue;
            }

            if (isalpha(c)) {
                string id;
                while (i < n && (isalnum(s[i]) || s[i] == '_')) {
                    id += s[i];
                    i++;
                }
                tokens.push_back({IDENTIFIER, id});
                continue;
            }

            if (isdigit(c)) {
                string num;
                while (i < n && isdigit(s[i])) {
                    num += s[i];
                    i++;
                }
                tokens.push_back({NUMBER, num});
                continue;
            }

            if (c == '=') { tokens.push_back({EQUAL, "="}); i++; continue; }
            if (c == ';') { tokens.push_back({SEMICOLON, ";"}); i++; continue; }

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

---

## 4. 測試輸入

    name="Even"; age=25; city="Taipei";

## 5. 執行結果

    [name]
    [=]
    ["Even"]
    [;]
    [age]
    [=]
    [25]
    [;]
    [city]
    [=]
    ["Taipei"]
    [;]

---

## 6. 小結
你完成了 Tokenizer 的核心：

- 能切 identifier / number / string / symbol
- 用線性掃描法處理字串
- enum + struct 建立 Token 型別

Day10 將把 Token Stream 組成 key-value map。

---

## 程式碼位置
    Day09_StringTokenizer/main.cpp
