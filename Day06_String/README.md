# Day06 — Text Parsing（字串解析）

## 今日目標
- 理解 `getline()` 的使用方式  
- 學會 `istringstream` 將字串拆成欄位  
- 使用 `substr()`、`stoi()`、`stof()` 擷取數值  
- 會使用 `ifstream` 從檔案讀取資料  
- 實作一個 Mini Log Parser（解析 STATUS 是否正常）

---

## 1. getline() — 讀整行字串
- `getline(cin, line)`：從鍵盤讀入一行  
- `getline(fin, line)`：從檔案讀入一行  
- 第一個參數必須是 *輸入串流*（cin, ifstream, istringstream）

---

## 2. istringstream — 把字串當作輸入
用途：將字串拆成多個欄位，像用 `cin >>` 一樣。

```cpp
string line = "[09:20:11] VOLT=12.5 CURR=3.2 STATUS=OK";
istringstream iss(line);

string time, volt, curr, status;
iss >> time >> volt >> curr >> status;
```

---

## 3. substr() — 字串切割
```cpp
string v = "VOLT=12.5";
v.substr(5);   // "12.5"
```

---

## 4. stoi(), stof() — 字串轉成數字

```cpp
int a = stoi("123");     // 123
float b = stof("12.5");  // 12.5
```

---

## 5. ifstream — 從檔案讀資料

- `cin` 從鍵盤讀  
- `ifstream` 從檔案讀  
- 用法幾乎一樣  

基本用法：

```cpp
ifstream fin("log.txt");
if (!fin.is_open()) {
    cout << "log.txt 無法開啟\n";
    return 1;
}
```

---

## 作業 1 — 字串拆解練習

解析：

```
[09:20:11] VOLT=12.5 CURR=3.2 STATUS=OK
```

你需要取得：

- time = `[09:20:11]`
- volt = `12.5`
- curr = `3.2`
- status = `OK`

練習用到：

- `istringstream`
- `substr`
- `stof`

（此作業已完成）

---

## 作業 2 — Mini Log Parser

使用 log.txt：

```
[09:20:11] VOLT=12.5 CURR=3.2 STATUS=OK
[09:21:33] VOLT=11.2 CURR=4.0 STATUS=WARN
[09:22:10] VOLT=10.8 CURR=3.8 STATUS=FAIL
```

程式功能：

- 從檔案逐行讀取
- 使用 `istringstream` 拆欄位
- 使用 `substr()` 萃取數值
- 使用 `stof()`、`substr()` 做轉換
- 若 `STATUS != OK` → 印出異常資訊

### 完成版程式碼

```cpp
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
```

---

## 程式碼位置
`Day06_TextParsing/`

---

## 今日成果
- 能解析格式化字串  
- 能使用 `getline()`、`istringstream`、`substr()`  
- 能從檔案讀出並分析資料  
- 成功完成 Mini Log Parser，可作為日後 Side Project 基礎  

