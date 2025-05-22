<!-->
# 云端VSCODE使用说明

## 使用说明
- 如何预览本文档
    >方法一:点击左上角预览图标
    >
    >方法二:先按下ctrl+k 再按下v
- 如何编译
  >方法一:在cpp/h文件点击右上角运行图标
  >
  >方法二:使用系统自带编译器g++/gcc

- 调试
  >这台电脑上安装了gdb，可以学习用gdb调试
  
- 注意事项
    >由于本vscode版本较老，很多扩展无法安装，market里很多扩展搜不到
    >
    >请不要安装ms的c/c++扩展，这个扩展和当前系统不兼容
    >
    >由于懒，没有做权限限制，terminal里是root权限，请不要滥用

## 文件说明

- `\tmp`:没有用的文件，在项目结束前将会临时保存在文件夹中

- `5.xx.xx.xx.h`:牢邓实现的hashmap

- `hashmap_iterator.h`:AI实现的迭代器
  
- `hashmap.cpp`:目前是一个空头文件
  
- `hashmap.h`:最终实现将会拷贝到这里

## TODO
- 完成HashMap中还没有实现的函数
- debug改进
- 将.h的实现移动到cpp里

### 5.14更改（gnx）
- `5.xx.xx.xx.xx.h`:更名为`hashmap_custom.h`,随后更改相关文件包含
- 认为可以弃用hashmap.cpp 模板类实现应该在头文件里？ 暂时挪到`\tmp`
- 推到了github私有repo上，另外放弃了我本地的版本，跑不起来。仓库地址：https://github.com/LeSiIence/scu_hash_map

### 5.19更改（lxy）
- 将`hashmap.h`中对`hashmap.cpp`的include删除，防止编译找不到文件
- 将原本的`main.cpp`移动到了`\tmp`文件夹中
- 编写了新的`main.cpp`,使用了简易的交互UI进行测试

### 5.20更改(lxy)
- 完善了`main.cpp`里的测试
- 优化了`hashmap.h`中`debug()`的输出

-->

### 5.22(lxy)

将测试文件拆分为benchmark和ui交互测试(`main.cpp`)两部分

自动rehash和大bucket之间要取舍

小bucket可以优化常数时间，但load factor过大，hash conflict，导致性能下降，搭配自动rehash之后，常数时间优化，时间复杂度为o(nlogn)

大bucket常数时间大，时间复杂度为o(n)

插入80k 个元素左右，两者性能大致相等

load factor函数要优化，计算有误,把nullptr也当作一个元素，结果始终大于1，导致每次插入是都在rehash，导致o(n^2)复杂度

load factor的问题可能源于hashmap无参构造函数，`_size`的初始值不是0



---
以下是正式的readme
# HashMap 模板类实现

这是一个用 C++ 实现的泛型哈希表（HashMap）模板类，支持标准 STL 风格的接口和迭代器。

## 特性

- 支持任意键值类型（通过模板实现）
- 提供 iterator 与 const_iterator，支持范围 for 循环
- 支持常见操作：
  - insert
  - find
  - erase
  - clear
  - operator[]
- 内部采用链表处理哈希冲突 //（具体是什么？）

## 项目结构


    ├── hashmap_custom.h         # HashMap 主类实现  
    ├── hashmap_iterator.h       # HashMapIterator 迭代器模板类  
    ├── main.cpp                 # 测试入口  
    └── README.md

## 用法示例
```
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

## 编译说明

项目使用 C++17 编写:

`g++ -std=c++17 -O2 main.cpp -o hashmap_test
./hashmap_test`

## 单元测试（建议）

建议引入 Google Test 或 Catch2 进行接口功能测试。你也可以编写简单的测试文件如 main.cpp 来测试所有操作。

## 实现细节简介

- 哈希桶使用 std::vector<node*> 管理
- 每个 node 是一个链表节点，存储 std::pair<Key, Value> 类型的数据
- HashMapIterator 支持前向遍历，符合 STL 迭代器规范
- 迭代器支持 ++, *, ->, ==, != 等基本操作

## License

本项目作为学习用途开放使用，可自由修改和分发。under MIT License。


