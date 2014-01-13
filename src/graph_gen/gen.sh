#!/bin/bash
IFS=" " 

rm g.txt
python generator.py

cat out.txt | while read v1 v2
do	
      echo $v1 $v2 $((RANDOM%253+1)) >> g.txt
done

