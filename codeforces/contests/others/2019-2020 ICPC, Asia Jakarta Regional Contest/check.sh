#!/bin/bash
g++ -std=c++17 gen.cpp -o gen
cp-gcc h.cpp -o a
cp-gcc brute.cpp -o brute

for((i=1;;i++)); do
	echo $i
	./gen $i > in
  ./a < in > o1
  ./brute < in > o2
	diff <(./a < in) <(./brute < in) || break
done

cat in
#sed -i 's/\r$//' filename  ----- remover \r do txt
