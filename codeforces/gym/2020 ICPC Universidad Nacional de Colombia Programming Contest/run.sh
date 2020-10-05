#!/bin/bash
g++ -std=c++17 gen.cpp -o gen
cp-gcc h.cpp -o a

for((i=1;;i++)); do
	echo $i
	./gen $i > in
  time	./a < in > o1
  if [[ $? -ne 0 ]]; then
    break
  fi
done

cat in
