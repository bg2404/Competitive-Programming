!/bin/bash

# clear
g++ test.cpp -o test
./test < input/a.txt > test/a.txt
./test < input/b.txt > test/b.txt
./test < input/c.txt > test/c.txt
./test < input/d.txt > test/d.txt
./test < input/e.txt > test/e.txt
./test < input/f.txt > test/f.txt