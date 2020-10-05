#!/bin/bash
#g++ -std=c++17 gen.cpp -o gen
g++ -std=c++17 ansc.cpp -o a
g++ -std=c++17 ans.cpp -o brute

for((i=1;;i++)); do
	echo $i
	python3 gen.py $i > in
  ./a < in > o1
  ./brute < in > o2
	diff <(./a < in) <(./brute < in) || break
done

cat in
#sed -i 's/\r$//' filename  ----- remover \r do txt
