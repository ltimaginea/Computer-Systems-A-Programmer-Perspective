# Data Alignment

We can use `#pragma pack(/*parameters*/)` to specifies the packing alignment for structure, union, and class members.

For  `#pragma pack(n)` , specifies the value, in bytes, to be used for packing. If the compiler option [`/Zp`](https://docs.microsoft.com/en-us/cpp/build/reference/zp-struct-member-alignment?view=msvc-170) isn't set for the module, the default value for `n` is 8. Valid values are 1, 2, 4, 8, and 16. The alignment of a member is on a boundary that's either a multiple of `n`, or a multiple of the size of the member, whichever is smaller.

## References

- [pack pragma | Microsoft Docs](https://docs.microsoft.com/en-us/cpp/preprocessor/pack?view=msvc-170)
- [C语言字节对齐问题详解 - clover_toeic - 博客园 (cnblogs.com)](https://www.cnblogs.com/clover-toeic/p/3853132.html)



