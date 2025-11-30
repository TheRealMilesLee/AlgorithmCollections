# AlgorithmCollections

项目简介
- 本仓库收集了多种经典算法的 C++ 实现（排序、搜索、图算法、动态规划等），适合作为学习、复习和面试准备的参考代码。

目录结构（示例）
- `*.cpp`：算法实现文件，例如 `MergeSort-Algorithm.cpp`, `BellmanFord-Algorithm.cpp`。
- `Makefile`：编译规则（如果存在）。
- `Executables/`：预编译/示例二进制（如有）。

快速开始
1. 打开终端到本目录。
2. 如果有 `Makefile`：
```
make
```
3. 直接编译单个文件（示例）：
```
g++ -std=c++17 -O2 MergeSort-Algorithm.cpp -o mergesort
./mergesort
```

如何使用/参考
- 每个 `.cpp` 文件通常包含单一算法的实现与一个简单的示例 `main` 函数，便于直接编译运行。
- 在阅读算法时，可把文件作为练习题来修改和测试不同输入。

贡献
- 欢迎通过 PR 提交更规范、带注释或更优实现的算法。

许可证
- 仓库中可能包含 `LICENSE` 文件，请参考相应许可。
