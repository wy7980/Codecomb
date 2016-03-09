#!/usr/bin/env python
#-*- coding: utf-8 -*-
 
# File Name: pyclient.py
# Author: wy7980
# mail: wy7980@gmail.com
# Created Time: 2016-03-09
import os
import time

def main():
	start = time.time()
	os.system('../bin/net_progrun 0 pc ptr_over 10 -dfs')
	end = time.time()
	print('------------time %f s-----------'%(end-start))

if __name__ == '__main__':
	main()
