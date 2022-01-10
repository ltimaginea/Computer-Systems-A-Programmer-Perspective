# AddressSanitizer Guide

## Introduction

[AddressSanitizer](https://github.com/google/sanitizers/wiki/AddressSanitizer) (aka ASan) is a memory error detector for C/C++. It finds:

- [Use after free](https://github.com/google/sanitizers/wiki/AddressSanitizerExampleUseAfterFree) (dangling pointer dereference)
- [Heap buffer overflow](https://github.com/google/sanitizers/wiki/AddressSanitizerExampleHeapOutOfBounds)
- [Stack buffer overflow](https://github.com/google/sanitizers/wiki/AddressSanitizerExampleStackOutOfBounds)
- [Global buffer overflow](https://github.com/google/sanitizers/wiki/AddressSanitizerExampleGlobalOutOfBounds)
- [Use after return](https://github.com/google/sanitizers/wiki/AddressSanitizerExampleUseAfterReturn)
- [Use after scope](https://github.com/google/sanitizers/wiki/AddressSanitizerExampleUseAfterScope)
- [Initialization order bugs](https://github.com/google/sanitizers/wiki/AddressSanitizerInitializationOrderFiasco)
- [Memory leaks](https://github.com/google/sanitizers/wiki/AddressSanitizerLeakSanitizer)

This tool is very fast. The average slowdown of the instrumented program is ~2x (see [AddressSanitizerPerformanceNumbers](https://github.com/google/sanitizers/wiki/AddressSanitizerPerformanceNumbers)).

## Usage

In order to use [AddressSanitizer](https://github.com/google/sanitizers/wiki/AddressSanitizer) you will need to compile and link your program using `g++` with the `-fsanitize=address` switch. To get a reasonable performance add `-O1` or higher. To get nicer stack traces in error messages add `-fno-omit-frame-pointer`. 

Now, run the executable. [AddressSanitizerCallStack](https://github.com/google/sanitizers/wiki/AddressSanitizerCallStack) page describes how to obtain symbolized stack traces.

```shell
g++ -fsanitize=address -O1 -fno-omit-frame-pointer -g ./main.cpp
./a.out
```

If you want to run an ASan-instrumented program without leak detection, you can pass `detect_leaks=0` in the `ASAN_OPTIONS` environment variable.

If you just need leak detection, and don't want to bear the ASan slowdown, you can build with `-fsanitize=leak` instead of `-fsanitize=address`. This will link your program against a runtime library containing just the bare necessities required for LeakSanitizer to work. No compile-time instrumentation will be applied. Be aware that the stand-alone mode is less well tested compared to running LSan on top of ASan. 

Note: LeakSanitizer does not work with gdb, See [LeakSanitizer does not work with gdb - fatal error of asan when executable has no issues · Issue #857 · google/sanitizers · GitHub](https://github.com/google/sanitizers/issues/857) . 

## References

- [Home · google/sanitizers Wiki · GitHub](https://github.com/google/sanitizers/wiki)
- [-fsanitize=address   -fsanitize=leak   (GCC Instrumentation Options)](https://gcc.gnu.org/onlinedocs/gcc/Instrumentation-Options.html)
- [-O1 -fno-omit-frame-pointer (GCC Optimize Options)](https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html#Optimize-Options)
- [AddressSanitizer (ASan) for the Linux Workload in Visual Studio 2019 - C++ Team Blog (microsoft.com)](https://devblogs.microsoft.com/cppblog/addresssanitizer-asan-for-the-linux-workload-in-visual-studio-2019/)
- [C/C++ Sanitizers | Microsoft Docs](https://docs.microsoft.com/en-us/cpp/sanitizers/?view=msvc-170)
- [linux - LeakSanitizer not working under gdb in Ubuntu 18.04? - Stack Overflow](https://stackoverflow.com/questions/54022889/leaksanitizer-not-working-under-gdb-in-ubuntu-18-04)
- [LeakSanitizer does not work with gdb - fatal error of asan when executable has no issues · Issue #857 · google/sanitizers · GitHub](https://github.com/google/sanitizers/issues/857)
- [Why hasn't AddressSanitizer detected a memory leak in my program? · Issue #1485 · google/sanitizers · GitHub](https://github.com/google/sanitizers/issues/1485)

