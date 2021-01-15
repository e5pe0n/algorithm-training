#!/bin/sh

f=`echo $1 | sed -e 's/\(.*\).cpp/\1/'`
current_dir=$(eval pwd)

c=`which clang++`
if [ -x $c ] && [ ! -z $c ]
then
    clang++ -std=c++14 -g -o ${current_dir}/build/${f}.out $1
    eval ${current_dir}/build/${f}.out
    exit
fi

c=`which g++`
if [ -x $c ] && [ ! -z $c ]
then
    g++ -std=c++17 -g -o ${current_dir}/build/${f}.out $1
    eval ${current_dir}/build/${f}.out
fi
