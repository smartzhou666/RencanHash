```stdgpht``` 是一个轻量级、极低开销的 ```__gnu_pbds::gp_hash_table``` 封装库，专为 **GCC/Clang** 平台上的高性能 **OI/ACM** 需求设计。
- - -
### 哈希仿函数 RencanHash (```hd```)
- 使用了 FNV-1a、MurmurHash3 等哈希算法进行高质量哈希，拥有强大的雪崩效应。
- 使用 ```[[gnu::pure]]``` 修饰符，确保编译器可优化不使用的函数。
### API 参考
使用
```cpp
template <typename Key_, typename Val_[, typename Hash_Fn = hd]>
gpht<Key_, Val_, Hash_Fn>
```
作为 ```gp_hash_table``` 的别名。

其中，```Key_``` 为键的类型，```Val_``` 为值的类型，```Hash_Fn```（可选，默认为内置 ```hd```）为哈希函数，需要保证 ```Hash_Fn``` 重载了 ```operator()```。 \
> ⚠️注意：当 ```Key_``` 为非内置类型时，需要给出第三个参数 ```Hash_Fn``` 并保证 ```Key_``` 重载了 ```operator==```，否则会编译失败。
### 前置库（已包含于库文件中）
- ```<bits/stdc++.h>```
- ```<ext/pb_ds/assoc_container.hpp>```
- ```<ext/pb_ds/hash_policy.hpp>```
### 环境需求
- GNU C++14 or later （建议 GNU C++17）
- 链接 ```libstdc++``` 并启用 ```pbds``` 扩展库
