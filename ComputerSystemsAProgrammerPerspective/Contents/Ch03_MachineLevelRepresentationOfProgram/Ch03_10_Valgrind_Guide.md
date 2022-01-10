# Valgrind Guide

## 1. Introduction

The Valgrind tool suite provides a number of debugging and profiling tools that help you make your programs faster and more correct. The most popular of these tools is called Memcheck. It can detect many memory-related errors that are common in C and C++ programs and that can lead to crashes and unpredictable behaviour.

The rest of this guide gives the minimum information you need to start detecting memory errors in your program with Memcheck. For full documentation of Memcheck and the other tools, please read the User Manual.

## 2. How to Install Valgrind?

You can install gdb on Debian-based linux distro (e.g. Ubuntu, Mint, etc) by following command.

```bash
sudo apt install valgrind
```



## 3. Preparing your program

Compile your program with `-g` to include debugging information so that Memcheck's error messages include exact line numbers. Using `-O0` is also a good idea, if you can tolerate the slowdown. With `-O1` line numbers in error messages can be inaccurate, although generally speaking running Memcheck on code compiled at `-O1` works fairly well, and the speed improvement compared to running `-O0` is quite significant. Use of `-O2` and above is not recommended as Memcheck occasionally reports uninitialised-value errors which don't really exist.

```bash
g++ -g ./main.cpp -o ./myprog
```



## 4. Running your program under Memcheck

If you normally run your program like this:

```bash
./myprog arg1 arg2
```

Use this command line:

```bash
valgrind --leak-check=yes ./myprog arg1 arg2
```

If you want to view detailed output information, use this command line:

```bash
valgrind --leak-check=full --show-leak-kinds=all ./myprog arg1 arg2
```

Memcheck is the default tool. The `--leak-check` option turns on the detailed memory leak detector.

Your program will run much slower (eg. 20 to 30 times) than normal, and use a lot more memory. Memcheck will issue messages about memory errors and leaks that it detects.

## References

- [The Valgrind Quick Start Guide](https://valgrind.org/docs/manual/quick-start.html)
- [Memory leak detection](https://valgrind.org/docs/manual/mc-manual.html#mc-manual.leaks)
- [Valgrind 使用入门 - 云+社区 - 腾讯云 (tencent.com)](https://cloud.tencent.com/developer/article/1006199)

