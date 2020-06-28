#!/bin/sh

f=`echo $1 | sed -e 's/\(.*\).cpp/\1/'`
current_dir=$(eval pwd)
clang++ -std=c++14 -g -o ${current_dir}/build/${f}.out $1
eval ${current_dir}/build/${f}.out
