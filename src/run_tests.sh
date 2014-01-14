#!/bin/bash
FILES=graph_gen/er*.txt


if [ "$1" == "" ]; then

	for f in $FILES
	do
	./mst $f p 
	./mst $f k 

	done

fi



if [ "$1" == "mem" ]; then

	for f in $FILES
	do
	valgrind --tool=massif --massif-out-file=massif.out ./mst $f p 
	V1=$(tail -7 massif.out| grep mem_heap_B |sed 's/[^0-9]*//g')
	V2=$(tail -7 massif.out| grep mem_heap_extra_B |sed 's/[^0-9]*//g')
	echo Memory used=$(($V1/1024 + $V2/1024))kb
	valgrind --tool=massif --massif-out-file=massif.out ./mst $f k 
	V1=$(tail -7 massif.out| grep mem_heap_B |sed 's/[^0-9]*//g')
	V2=$(tail -7 massif.out| grep mem_heap_extra_B |sed 's/[^0-9]*//g')
	echo Memory used=$(($V1/1024 + $V2/1024))kb
	done

fi