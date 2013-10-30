#!/usr/bin/env bash
g++ -fPIC -I/usr/include/python2.7 -c base.cpp -o base.o
if [[ $? -ne "0" ]]; then echo "failure 1"; exit; fi
g++ -shared -Wl,-soname,base_ext.so -o base_ext.so base.o -lpython2.7 -lboost_python
if [[ $? -ne "0" ]]; then echo "failure 2"; exit; fi
python base.py
