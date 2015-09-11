#!/bin/sh
make clean
make
#insmod module.ko param1=12 int_array=1,2,3,4,5
#insmod module.ko int_array=1,2,3,4,5
insmod module.ko param1=150 int_array=1,2,3,4,5 for_world=111 test_string="hello"
