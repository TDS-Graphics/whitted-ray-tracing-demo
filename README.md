# Framework 
这是一个简单的项目框架，其中包含了我们需要经常使用的 Vec3.h 以及 main.cpp 中的使用样例

以及一个 CMakeLists.txt 会自动递归扫描 src/ 目录下的所有 .cpp 文件并编译成可执行文件，所以你添加新的 .cpp 文件时，请放在 src/ 目录下

如果你还使用 clang 那么根目录我们还放了 .clang-format 和 .clangd 当然你可以替换成你熟悉的 clang 配置文件