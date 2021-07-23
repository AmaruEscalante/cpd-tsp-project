#!/bin/sh

echo "Init test of TSP Proyect at: " `date +\%Y-\%m-\%d--\%H-\%M`

LIST=$(ls tests/*.txt | cut -f 1 -d '.' | cut -d_ -f2-)
# FILES=$(ls tests/*.txt | cut -d/ -f2-)

cd tests

# for loop 
for i in $LIST
do
    echo " "
    echo "Test: $i"
    FILE=$(ls *_$i.txt)
    echo "Execute " "./../build/main-$i.out" " $FILE"
    ./../build/main-$i.out "$FILE"
    echo "Test: $i - OK"
done