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


### 5.22(lxy)

将测试文件拆分为benchmark和ui交互测试(`main.cpp`)两部分

自动rehash和大bucket之间要取舍

小bucket可以优化常数时间，但load factor过大，hash conflict，导致性能下降，搭配自动rehash之后，常数时间优化，时间复杂度为o(nlogn)

大bucket常数时间大，时间复杂度为o(n)

插入80k 个元素左右，两者性能大致相等

load factor函数要优化，计算有误,把nullptr也当作一个元素，结果始终大于1，导致每次插入是都在rehash，导致o(n^2)复杂度

load factor的问题可能源于hashmap无参构造函数，`_size`的初始值不是0



