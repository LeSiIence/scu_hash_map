// hashmap_iterator.h
#ifndef HASHMAP_ITERATOR_H
#define HASHMAP_ITERATOR_H

template <typename HashMap, bool IsConst>
class HashMapIterator {
private:
    using NodeType = typename HashMap::node;
    using BucketArrayType = typename HashMap::bucket_array_type;

    NodeType* current;
    BucketArrayType* buckets;
    size_t bucketIndex;

public:
    using difference_type = std::ptrdiff_t;
    using value_type = std::conditional_t<IsConst, 
                                          const typename HashMap::value_type, 
                                          typename HashMap::value_type>;
    using pointer = value_type*;
    using reference = value_type&;
    using iterator_category = std::forward_iterator_tag;

    // 默认构造函数
    HashMapIterator() : current(nullptr), buckets(nullptr), bucketIndex(0) {}

    // 构造函数，用于初始化迭代器到哈希表的末尾
    HashMapIterator(HashMap* map, std::nullptr_t) 
        : current(nullptr), buckets(&(map->_buckets_array)), bucketIndex(map->_buckets_array.size()) {}

    // 构造函数，用于初始化迭代器到指定节点
    HashMapIterator(HashMap* map, NodeType* node) 
        : current(node), buckets(&(map->_buckets_array)), bucketIndex(find_bucket_index(map, node)) {}

private:
    // 辅助函数，用于找到节点所在的桶索引
    size_t find_bucket_index(HashMap* map, NodeType* node) {
        for (size_t i = 0; i < map->_buckets_array.size(); ++i) {
            NodeType* current = map->_buckets_array[i];
            while (current != nullptr) {
                if (current == node) {
                    return i;
                }
                current = current->next;
            }
        }
        return map->_buckets_array.size(); // 如果未找到，返回桶数组大小（表示末尾）
    }

public:
    // 解引用操作符
    reference operator*() const {
        return current->value;
    }

    // 箭头操作符
    pointer operator->() const {
        return &(current->value);
    }

    // 前缀递增操作符
    HashMapIterator& operator++() {
        if (current->next != nullptr) {
            current = current->next;
        } else {
            ++bucketIndex;
            while (bucketIndex < buckets->size() && (*buckets)[bucketIndex] == nullptr) {
                ++bucketIndex;
            }
            if (bucketIndex < buckets->size()) {
                current = (*buckets)[bucketIndex];
            }
        }
        return *this;
    }

    // 后缀递增操作符
    HashMapIterator operator++(int) {
        HashMapIterator temp = *this;
        ++(*this);
        return temp;
    }

    // 比较操作符
    bool operator==(const HashMapIterator& other) const {
        return current == other.current && buckets == other.buckets && bucketIndex == other.bucketIndex;
    }

    bool operator!=(const HashMapIterator& other) const {
        return !(this->operator==(other));
    }
};

#endif // HASHMAP_ITERATOR_H