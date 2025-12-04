# Day08 – Simple Key-Value String Parser (C++)

這是一個簡單但實用的 **key=value 字串解析器**，  
可以解析以下格式：

- `"name=Even, age=23, city=Taipei"`
- `"id=12&mode=debug&retry=3"`

所有解析後的內容會被存進：

```cpp
std::unordered_map<std::string, std::string>
