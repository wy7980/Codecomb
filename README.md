# Codecomb
Codecomb is a software testing tool which can generate a high branch coverage  and detect defect with symbolic execution .

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

cd llvmserver/bin
./run_net_server

## client
**run the following commands on terminal 2.**
cd llvmclient/bugtest
../bin/llvm arry3.c
cp branch ../../llvmserver/userdata/pc/arry3/
../bin/net_program 0 pc arry3 10 -dfs

If there are any problems, inform me please.
											wy7980@gmail.com

