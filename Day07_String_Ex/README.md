# Day07 — Log Parsing（字串解析、split、key=value 解析）
內容：

今天學習 C++ 字串處理與基礎資料解析，包含以下重點：

## 1. 使用 istringstream 解析字串

能將整行字串視為 stream

像讀檔案一樣用 >> 抽 token

常用於：log parser、設定檔解析、字串分割

## 2. 使用 find() + substr() 拆 key=value

解析下列格式：

CPU=37
TEMP=45
FAN=2100


重點：

pos = token.find('=')：找到等號位置

substr(0, pos)：取 key

substr(pos + 1)：取 value

pos == string::npos：找不到等號（需跳過）

## 3. 用 unordered_map 儲存一行的 key-value

例如：

TEMP=45 FAN=2000 STATUS=OK


會被解析成：

mp["TEMP"] = "45"
mp["FAN"] = "2000"
mp["STATUS"] = "OK"

## 4. 多行 log → 使用 vector<unordered_map> 儲存全部資料

範例 log：

TEMP=45 FAN=2000 STATUS=OK
CPU=37 GPU=41 FAN=2100 STATUS=OK
MODE=AUTO BRIGHTNESS=70


轉換後：

data[0]：第 1 行

data[1]：第 2 行

data[2]：第 3 行

每一行是一個 map。

## 5. Part 3：進階 log parser 功能
搜尋某欄位（例如 STATUS）
printLinesWithKey(data, "STATUS");

統計欄位值（例如 OK 出現幾次）
countStatus(data);

JSON-like 格式輸出
printAsJsonLike(data);


方便閱讀，之後能擴充成真正 JSON 或 CSV。

## 程式碼位置：

Day07_LogParsing/main.cpp

## 今日重點（Quick Review）

istringstream iss(line);：把字串變成 stream

find('=')：取得等號位置

substr()：拆 key/value

auto &p : mp：引用 map 元素（不複製）

vector<unordered_map<string,string>> data：存整份 log