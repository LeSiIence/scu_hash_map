#include "hashmap_custom.h"
#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <cmath>

// 生成随机键值对
template <typename K, typename M>
std::vector<std::pair<K, M>> generate_random_pairs(size_t count, K min_key, K max_key, M min_value, M max_value) {
    std::vector<std::pair<K, M>> pairs;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<K> key_dist(min_key, max_key);
    std::uniform_int_distribution<M> value_dist(min_value, max_value);

    for (size_t i = 0; i < count; ++i) {
        pairs.emplace_back(key_dist(gen), value_dist(gen));
    }
    return pairs;
}

// 测试插入速度
template <typename K, typename M>
void test_insert_speed(HashMap<K, M>& map, const std::vector<std::pair<K, M>>& pairs, size_t count) {
    for (size_t i = 0; i < count; ++i) {
        map.insert(pairs[i]);
    }
}

// 测试删除速度
template <typename K, typename M>
void test_erase_speed(HashMap<K, M>& map, const std::vector<std::pair<K, M>>& pairs, size_t count) {
    for (size_t i = 0; i < count; ++i) {
        map.erase(pairs[i].first);
    }
}

// 测试更新速度
template <typename K, typename M>
void test_update_speed(HashMap<K, M>& map, const std::vector<std::pair<K, M>>& pairs, size_t count) {
    for (size_t i = 0; i < count; ++i) {
        if (map.contains(pairs[i].first)) {
            map[pairs[i].first] = pairs[i].second;
        }
    }
}

// 测试查找速度
template <typename K, typename M>
void test_find_speed(HashMap<K, M>& map, const std::vector<std::pair<K, M>>& pairs, size_t count) {
    for (size_t i = 0; i < count; ++i) {
        map.find(pairs[i].first);
    }
}

// 执行基准测试
template <typename K, typename M>
void run_benchmark(int choice, size_t max_count) {
    const size_t initial_buckets = 10;
    const int test_points = 20;
    
    // 生成足够的随机数据
    auto data = generate_random_pairs<int, int>(max_count, 0, 1000000, 0, 1000000);

    for (int i = 0; i <= test_points; ++i) {
        size_t count = std::min(max_count, static_cast<size_t>(std::pow(10, 1 + i * 0.3)));

        int times = 30;
        if (count > 100) times = 15;
        if (count > 1000) times = 10;
        if (count > 10000) times = 1;

        long long sum = 0;
        double _factor_sum = 0.0;

        for (int j = 0; j < times; ++j) {
            HashMap<K, M> map(initial_buckets);

            auto start = std::chrono::high_resolution_clock::now();

            switch (choice) {
                case 1:
                    test_insert_speed(map, data, count);
                    break;
                case 2:
                    test_erase_speed(map, data, count);
                    break;
                case 3:
                    test_update_speed(map, data, count);
                    break;
                case 4:
                    test_find_speed(map, data, count);
                    break;
                default:
                    break;
            }

            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
            sum += duration;
            _factor_sum += map.load_factor();
        }

        double avg_time = static_cast<double>(sum) / times;
        double load_factor = _factor_sum / times;

        switch (choice) {
            case 1:
                std::cout << "Insert - Elements: " << count 
                          << "  Avg Time: " << avg_time << " ms" 
                          << " Avg load factor: " << load_factor 
                          << std::endl;
                break;
            case 2:
                std::cout << "Erase - Elements: " << count 
                          << "  Avg Time: " << avg_time << " ms" 
                          << " Avg load factor: " << load_factor 
                          << std::endl;
                break;
            case 3:
                std::cout << "Update - Elements: " << count 
                          << "  Avg Time: " << avg_time << " ms" 
                          << " Avg load factor: " << load_factor 
                          << std::endl;
                break;
            case 4:
                std::cout << "Find - Elements: " << count 
                          << "  Avg Time: " << avg_time << " ms" 
                          << " Avg load factor: " << load_factor 
                          << std::endl;
                break;
        }
    }
}

int main() {
    int choice;
    do {
        std::cout << "\nBENCHMARK:\n";
        std::cout << "1. Test Insert Speed\n";
        std::cout << "2. Test Erase Speed\n";
        std::cout << "3. Test Update Speed\n";
        std::cout << "4. Test Find Speed\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice >= 1 && choice <= 4) {
            size_t max_count;
            std::cout << "Max elements to test? ";
            std::cin >> max_count;
            run_benchmark<int, int>(choice, max_count);
        } else if (choice == 5) {
            std::cout << "Exiting program.\n";
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}