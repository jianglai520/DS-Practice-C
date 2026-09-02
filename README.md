# DS-Practice-C

C 语言版数据结构学习记录项目。用一个个独立的练习小程序来巩固数据结构与算法知识，每个小程序都是可单独编译、运行的最小示例。

## 目录结构

```
DS-Practice-C/
├── CMakeLists.txt                 # 构建配置：自动发现所有 .c 文件，各自生成可执行文件
├── main.c                         # 模板示例（Hello World），可删除
├── Loop_vs_Recursion/             # 练习：循环与递归
│   └── loop_vs_recursion.c
└── ...                            # 后续新增的练习目录，按主题划分
```

约定：**每个练习放在一个以主题命名的子目录里，每个 `.c` 文件自带一个 `main` 函数**。构建系统会自动把每个 `.c` 文件编译成独立的可执行文件。

## 环境要求

- CMake ≥ 3.20
- 一个可用的 C 编译器（MinGW-w64 / GCC / Clang / MSVC 均可）
- 推荐使用 CLion，直接打开项目即可

## 构建与运行

### 方式一：CLion（推荐）

1. `File → Open` 打开本项目根目录。
2. 在 `Settings → Build, Execution, Deployment → Toolchains` 中确认 C 编译器可用。
3. 点击右上角的目标（如 `loop_vs_recursion` 或 `main`）运行，或直接 `Build`。
4. 生成的 `*.exe` 在 `cmake-build-debug/bin/<目录名>/` 下。

### 方式二：命令行

```bash
cmake -S . -B cmake-build-debug -G Ninja
cmake --build cmake-build-debug
# 运行某个练习
./cmake-build-debug/bin/Loop_vs_Recursion/loop_vs_recursion.exe
```

> Windows 下如果编译报 `subcommand failed` 却没有具体错误，通常是编译器没找到运行库，见下方「常见问题」。

## 如何新增一个练习

1. 新建一个主题目录，例如 `LinkedList/`。
2. 在里面写一个 `.c` 文件，带上 `main`，例如 `LinkedList/singly_linked_list.c`。
3. 重新让 CMake 生成一次（CLion 会自动；命令行可重新执行 `cmake -S . -B cmake-build-debug`）。

由于 `CMakeLists.txt` 里用了 `file(GLOB_RECURSE ... CONFIGURE_DEPENDS ...)`，**新增或删除 `.c` 文件后会自动重新生成构建系统**，无需手动改配置。

注意：**每个 `.c` 文件的「文件名（不含扩展名）」需要唯一**，否则会因可执行目标重名而报错（例如不要同时存在 `main.c` 和 `List/main.c`）。

## 常见问题

### 1. 构建时报 `ninja: build stopped: subcommand failed`，且看不到具体编译错误

这是 CLion 自带 MinGW（GCC 13.x）的运行库没被找到导致的：编译器前端 `cc1.exe` 需要 `libwinpthread-1.dll`、`libssp-0.dll`，它们位于 `<CLion 安装目录>\bin\mingw\bin`，而构建时该目录不在 `PATH` 中。

**解决方法（任选其一）：**

- **推荐**：在 CLion 里把 Toolchain 从「Bundled MinGW」换成系统里已安装好的 MinGW-w64（例如 `D:\MinGW-w64\mingw64`）。
- 或把 `<CLion 安装目录>\bin\mingw\bin` 加入系统环境变量 `Path`，然后重启 CLion。
- 或命令行构建前先设置 PATH：
  ```bash
  export PATH="/d/Software/CLion/CLion 2025.2.4/bin/mingw/bin:$PATH"
  ```

### 2. 构建产物里出现了多余的 `CMakeCCompilerId` 目标/可执行文件

这是旧版 `CMakeLists.txt` 用 `file(GLOB_RECURSE SOURCES "*.c")` 时，把构建目录里 CMake 自动生成的 `CMakeCCompilerId.c` 也扫进去了导致的。当前 `CMakeLists.txt` 已经通过 `list(FILTER ... EXCLUDE REGEX "/cmake-build-")` 排除了构建目录，不会再有这个问题。

## 说明

- 根目录的 `main.c` 是 CLion 新建项目时生成的模板，仅用于占位，可删除。
- 构建产物目录 `cmake-build-debug/` 和 IDE 配置 `.idea/` 建议加入 `.gitignore`，不要提交到仓库。
