// 测试rehash操作
    map2.rehash(10);
    std::cout << "\nTesting rehash operation: " << std::endl;
    std::cout << "New bucket count: " << map2.bucket_count() << ", Load factor: " << map2.load_factor() << std::endl;