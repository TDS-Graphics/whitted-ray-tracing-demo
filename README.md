# Whitted-Stlye Ray Tracing Renderer

这是一个简单的 Whitted-Stlye Ray Tracing Renderer 可以作为 TDSG 第三阶段的参考项目。    
如果你想跟着这个项目写可以从我们的 [框架开始](https://github.com/TDS-Graphics/whitted-ray-tracing-demo/tree/framework)    

> 建议如果没有 C++ 或者其他项目构建基础的话可以选择跟着我们实现，但如果你懂的如何构建一个项目我们强行建议你自己实现，当然可以使用你熟悉的语言
# Build
环境准备：

你至少需要准备能够编译基于 CMake 的 C++ 项目的环境  

然后在终端中运行以下命令：  
```bash
git clone https://github.com/TDS-Graphics/whitted-ray-tracing-demo.git

cd whitted-ray-tracing-demo

cmake -S . -B build

cmake --build build
```
可执行文件将生成在 build 目录下，当然这取决于你使用的编译器，如果你使用的是 MSVC，那么可执行文件可能生成在 build/Debug 目录下或其他你配置的位置  

# Usage
运行程序：  
```bash
./build/whitted_ray_tracing_app
```
将会在同级目录下生成一张名为 output1.ppm 的图片
![](screen_shots/output1.png)
> 你可能需要使用相关的图片查看器才能查看图片  


