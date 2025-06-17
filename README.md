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
├── /asset                   # 图片资源
├── report.tex               # 报告正文
├── report.pdf               # 报告正文
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

- 基于性能评估与功能验证的差异化需求，将测试体系进行结构化拆分，形成专注于性能基准测试的 benchmark 模块与侧重功能交互验证的交互测试模块，构建起层次分明的测试架构。

- 深入剖析 `load factor` 相关代码逻辑，精准定位并修复存在的计算与判断逻辑错误，确保负载因子的动态计算与调整机制符合设计预期。

-  针对小 / 大 bucket 的选择策略进行系统性优化，通过引入自适应算法与动态阈值调整机制，提升数据存储与检索时的 bucket 选择效率与合理性。

### ✅ 5.21（gnx）

-  在全面的功能测试与性能测试过程中，敏锐捕捉到`insert`方法在数据插入操作时存在执行效率低下的问题，为后续优化工作提供关键依据。

### ✅ 5.20（lxy）

-  对`main.cpp`中的测试用例进行深度优化，从测试场景覆盖度、测试数据生成策略、断言验证逻辑等多个维度进行重构，增强测试用例的全面性与有效性。

-  对`debug()`函数的输出格式进行系统性完善，通过统一输出规范、优化数据展示层级与格式、增加关键信息标注等方式，提升调试信息的可读性与可用性。

### ✅ 5.19（lxy）

-  对`main.cpp`文件进行整体性重构，重新规划代码结构，优化函数调用关系，剥离冗余代码，提升代码的可维护性与扩展性。

-  对历史遗留的测试入口进行全面清理，删除失效或重复的测试接口，统一测试入口规范，简化测试流程与代码逻辑。

### ✅ 5.14（gnx）

-  依据代码功能定位与模块划分原则，将相关文件正式更名为`hashmap_custom.h`，强化文件命名的规范性与表意性。

-  基于模板类的特性与编译原理，摒弃`hashmap.cpp`文件，将模板类的全部逻辑迁移整合至头文件中，解决模板实例化与跨编译单元的潜在问题。

-  完成代码版本管理升级，将项目代码上传至 GitHub 私有仓库，借助 Git 强大的版本控制功能实现代码的版本追踪、协作开发与安全存储。

-  正式引入 Git 作为项目的版本管理工具，构建起完整的版本控制流程，包括分支管理、提交日志规范、合并冲突处理等，为团队协作开发提供坚实保障。

### ✅ 5.13（lxy&dhy）

-  协同合作推进哈希表核心功能开发，成功实现`hashmap.h`中定义的大部分函数，涵盖数据插入、删除、查询、遍历等核心操作，初步搭建起哈希表的数据结构与功能体系。

### ✅ 5.10（dhy）

-  鉴于`hashmap.h`中诸多核心函数的实现依赖迭代器功能，优先聚焦于迭代器模块的开发，通过精心设计迭代器的接口与实现逻辑，为哈希表的全面功能实现奠定基础。

### ✅ 5.9（lxy）

-  针对无需迭代器支持的哈希表功能需求，成功实现`load_factor`、`size`等函数，完成哈希表基础属性查询功能的开发，为后续更复杂功能的实现提供支撑。

### ✅ 5.8

-  项目团队成员 共同对给定的头文件进行深入研读与分析，结合项目需求与技术特点，经过多轮研讨与论证，确定了哈希表开发的整体技术方案与实现思路。

-  依据团队成员的技术专长与能力特点，进行科学合理的任务分工，明确 lxy 和 dhy 主要负责`hashmap.h`文件开发与迭代器功能实现，gnx 承担辅助测试与代码报告撰写工作，为项目有序推进提供组织保障。

## 🧪 测试建议

可引入 [Catch2](https://github.com/catchorg/Catch2) 或 [Google Test](https://github.com/google/googletest) 编写单元测试，验证各接口稳定性与边界条件。

## 📄 License

本项目作为课程设计用途公开，使用 MIT 协议，欢迎自由学习与扩展。  
