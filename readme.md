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