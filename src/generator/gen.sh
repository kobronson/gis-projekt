#!/bin/bash
IFS=" " 

rm g.txt

python random_connected_graph.py -p 40|sed 's/(//g;s/)//g;s/,//g;s/]//g;s/\[//g' >  graph.tmp
sed -i 's/^ *//'  graph.tmp

cat graph.tmp | while read v1 v2
do	
      echo $v1 $v2 $((RANDOM%256+1)) >> g.txt
done

rm graph.tmp