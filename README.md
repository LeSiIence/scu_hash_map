# 🧠 HashMap 模板类实现（SCU 大作业项目）
![scu_logo](./asset/logo.png)
[![MIT License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)
[![C++](https://img.shields.io/badge/language-C%2B%2B17-blue.svg)](https://en.cppreference.com/)
[![GitHub Repo](https://img.shields.io/badge/repo-private-lightgrey)](https://github.com/LeSiIence/scu_hash_map)

一个使用现代 C++ 编写的轻量泛型哈希表实现，支持 STL 风格接口与迭代器，适合作为学习数据结构、泛型编程、迭代器实现等方面的参考项目。

## 📌 特性亮点

- 支持任意键值类型（模板泛型实现）
- 提供 `iterator` 与 `const_iterator`，支持范围 for 循环
- 标准接口支持：
  - `insert`, `find`, `erase`, `clear`, `operator[]`
- 开箱即用的调试函数 `debug()` 输出桶状态
- 内部使用链表处理哈希冲突
- 支持负载因子与自动 rehash 机制（可优化）

## 🧪 快速上手

```cpp
#include "hashmap_custom.h"

int main() {
    HashMap<std::string, int> map;
    map.insert({"apple", 3});
    map["banana"] = 5;

    if (auto it = map.find("apple"); it != map.end()) {
        std::cout << "apple: " << it->second << "\n";
    }

    for (const auto& [key, value] : map) {
        std::cout << key << " -> " << value << "\n";
    }
}
```

### 编译方式

```sh
g++ -std=c++17 -O2 main.cpp -o hashmap_test
./hashmap_test
```

## 🗂️ 项目结构

```
.
├── hashmap_custom.h         # HashMap 主模板类实现
├── hashmap_iterator.h       # 迭代器模板类定义
├── main.cpp                 # 基本交互测试
├── benchmark.cpp            # 插入性能测试
├── /tmp                     # 中间/废弃文件存放
└── README.md
```

## 📈 实现细节简介

- 哈希桶结构：`std::vector<node*>`
- 每个 `node` 存储 `std::pair<Key, Value>`，使用链表处理冲突
- 迭代器符合 STL 标准，支持 `++`, `*`, `->`, `==`, `!=`
- 可根据负载因子触发自动 rehash，优化性能

## 🧪 性能说明（2025.5.22 测试）

- **小 bucket**：常数时间快，但 load factor 高时容易冲突，需频繁 rehash，复杂度可能退化为 O(n²)
- **大 bucket**：冲突少，但浪费空间，插入复杂度趋于 O(n)
- 插入 8 万个元素，二者性能大致相等
- 注意：负载因子计算初期错误，把空桶也计入，导致始终大于 1，已修复

## 🧱 近期开发进度（日志）

### ✅ 5.22（lxy）
- 拆分测试为 benchmark 和交互测试
- 修复 load factor 的逻辑 bug
- 优化小/大 bucket 选择逻辑

### ✅ 5.20（lxy）
- 优化 `main.cpp` 测试用例
- 完善 `debug()` 输出格式

### ✅ 5.19（lxy）
- 重构 `main.cpp`
- 清理历史测试入口

### ✅ 5.14（gnx）
- 文件更名为 `hashmap_custom.h`
- 放弃 `hashmap.cpp`，模板类逻辑全部移至头文件
- 上传至 GitHub 私有仓库

## 🧪 测试建议

可引入 [Catch2](https://github.com/catchorg/Catch2) 或 [Google Test](https://github.com/google/googletest) 编写单元测试，验证各接口稳定性与边界条件。

## 📄 License

本项目作为课程设计用途公开，使用 MIT 协议，欢迎自由学习与扩展。  
