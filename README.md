# Codecomb
Codecomb is a software testing tool which can get a high branch coverage  and detect defect with symbolic execution .

# Platform
ubuntu 14.04_x86-64

clang v3.4

# Defect types
* buffer overflow
* memory leak
* memory double free

# Usage
You should run server first then run the client.
##  server
**run the following commands on terminal 1.**
```shell
cd llvmserver/bin
./run_net_server
```

## client
**run the following commands on terminal 2.**
```shell
cd llvmclient/bugtest
../bin/llvmc array.c
cp branch ../../llvmserver/userdata/pc/array/
../bin/net_program 0 pc array 10 -dfs
```
If there are any problems, please inform me.

wy7980@gmail.com

----
# Codecomb

Codecomb 是一个基于动态符号执行生成高分支覆盖度的缺陷检测工具，它具备动态测试案例生成和全面缺陷检测功能，分为服务器端和客户端两个部分，两部分分别在不同的终端上运行。

