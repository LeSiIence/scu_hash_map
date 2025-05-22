//main.cpp
#include "hashmap_custom.h"
#include <iostream>
#include <string>

int main() {
    // 测试默认构造函数
    HashMap<int, std::string> map1;
    std::cout << "Testing default constructor: " << std::endl;
    std::cout << "Size: " << map1.size() << ", Empty: " << (map1.empty()? "true" : "false") << std::endl;

    // 测试带参数的构造函数
    HashMap<int, std::string> map2(5);
    std::cout << "\nTesting constructor with bucket count: " << std::endl;
    std::cout << "Size: " << map2.size() << ", Bucket count: " << map2.bucket_count() << ", Load factor: " << map2.load_factor() << std::endl;

    // 测试插入操作
    map2.insert({1, "Alice"});
    map2.insert({2, "Bob"});
    std::cout << "\nTesting insert operation: " << std::endl;
    std::cout << "Size: " << map2.size() << ", Contains key 1: " << (map2.contains(1)? "true" : "false") << ", Contains key 3: " << (map2.contains(3)? "true" : "false") << std::endl;

    // 测试at操作
    try {
        std::cout << "Value for key 1: " << map2.at(1) << std::endl;
        // 测试不存在的键
        std::cout << "Value for key 3: " << map2.at(3) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Caught out_of_range exception: " << e.what() << std::endl;
    }

    // 测试[]操作符
    map2[3] = "Charlie";
    std::cout << "\nTesting [] operator: " << std::endl;
    std::cout << "Value for key 3: " << map2[3] << std::endl;

    // 测试find操作
    auto iter = map2.find(2);
    if (iter != map2.end()) {
        std::cout << "Found key 2, value: " << iter->second << std::endl;
    } else {
        std::cout << "Key 2 not found" << std::endl;
    }

    // 测试erase操作
    bool erased = map2.erase(2);
    std::cout << "\nTesting erase operation: " << std::endl;
    std::cout << "Erased key 2: " << (erased? "true" : "false") << ", Size: " << map2.size() << std::endl;

    // 测试rehash操作
    map2.rehash(10);
    std::cout << "\nTesting rehash operation: " << std::endl;
    std::cout << "New bucket count: " << map2.bucket_count() << ", Load factor: " << map2.load_factor() << std::endl;

    // 测试clear操作
    map2.clear();
    std::cout << "\nTesting clear operation: " << std::endl;
    std::cout << "Size: " << map2.size() << ", Empty: " << (map2.empty()? "true" : "false") << std::endl;

    // 测试debug函数
    map2.insert({4, "David"});
    std::cout << "\nTesting debug function: " << std::endl;
    map2.debug();

    return 0;
}