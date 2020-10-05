#!/bin/bash
cp-gcc c.cpp -o a

for((i=1;;i++)); do
	echo $i
	python3 gen.py $i > in
  ./a < in > o1
  python3 sol.py < in > o2
	diff <(./a < in) <(python3 sol.py < in) || break
done

cat in
#sed -i 's/\r$//' filename  ----- remover \r do txt
