## 十进制转为二进制C++与JS性能对比

### 测试条件&测试用例

代码在一台 Macbook Pro 上面运行。g++ 版本信息如下：

```
Configured with: --prefix=/Library/Developer/CommandLineTools/usr --with-gxx-include-dir=/usr/include/c++/4.2.1
Apple LLVM version 8.1.0 (clang-802.0.38)
Target: x86_64-apple-darwin16.0.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin
```

执行100万次对同一个数字的10进制到二进制的转换。这个数字 9007199254740991 （2^53 - 1）是 JavaScript 所能表示的最大数值。

```
for (var i = 0; i < 1000000; ++i) {
  var s = baseConvert(9007199254740991, 2);
}
```

对于C++的代码来说，拿到 char s[] 数组即可。

### 代码说明

```
.
├── LICENSE
├── README.md
├── cpp
│   ├── app-tunning.cpp  # C++ 经过优化
│   └── app.cpp          # C++ 未经优化
└── js
    └── app.js
```

### 结果对比

JS 代码使用 Node.js v6.9.5 来运行。

二者的时间分析使用系统的 `time` 命令。

|          code            |   user   |  system   |  total  |
|  -------------------     |  ------  | --------  |  -----  |
|  /js/app.js              |  1.58s   |   0.02s   |  1.601  |
|  /cpp/app-tunning.cpp    |  12.70s  |  0.01s    |  12.720 |
|  /cpp/app.cpp            |  1.73s   |  0.01s    |  1.742  |

### 分析

`app.cpp` 里面使用了标准库 `<stack>`，在优化的代码 `app-tunning.cpp` 中，自己实现了一个非常简单粗暴的（求勿喷）。

有两个疑问：

+ V8 引擎真的优化的那么好了？
+ `app-tunning.cpp` 是否还可以继续优化？
