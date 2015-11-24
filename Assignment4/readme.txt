Using the code provided by Micheal Barr. Implementing two CRC algorithms to
test the result of following sentence: 

“Java is a general-purpose computer programming language that is concurrent, class-based, object-oriented,and specifically designed to have as few implementation dependencies as possible.”

Measure the implementation’s performance
CPU : Intel Core i5－5200u 2.6GHz
RAM : 8GB 1600MHz DDR3
Compile : Apple LLVM version 7.0.0 (clang-700.1.76)

**********************************************************
CRC_CCITT
optimization lever  |    slow time  |  fast time
-o3                 |    0.000016   |  0.000012
-o2                 |    0.000019   |  0.000012
-o1                 |    0.000018   |  0.000013
-os                 |    0.000016   |  0.000010

size main.o
__TEXT  __DATA  __OBJC  others  dec  hex
1564    0       0       63      1600 67c

size crc.o
__TEXT  __DATA  __OBJC  others  dec  hex
660     512     0       96      1268 4f4

**********************************************************
CRC_16
optimization lever  |    slow time  |  fast time
-o3                 |    0.000025   |  0.000021
-o2                 |    0.000030   |  0.000024
-o1                 |    0.000025   |  0.000022
-os                 |    0.000026   |  0.000023

size main.o
__TEXT	__DATA	__OBJC	others	dec	hex
1564	0	0	96	1660	67c

size crc.o
__TEXT	__DATA	__OBJC	others	dec	hex
940	512	0	128	1580	62c

**********************************************************
CRC_32
optimization lever  |    slow time  |  fast time
-o3                 |    0.000027   |  0.000023
-o2                 |    0.000027   |  0.000023
-o1                 |    0.000026   |  0.000023
-os                 |    0.000026   |  0.000023

size main.o
__TEXT	__DATA	__OBJC	others	dec	hex
1560	0	0	96	1656	678
size crc.o
__TEXT	__DATA	__OBJC	others	dec	hex
875	1024	0	128	2027	7eb

**********************************************************
I can legally include this code as a part of my project.
Because: 
“ Copyright (c) 2000 by Michael Barr.  This software is placed into
  the public domain and may be used for any purpose.  However, this
  notice must not be changed or removed and no warranty is either
  expressed or implied by its publication or distribution.”