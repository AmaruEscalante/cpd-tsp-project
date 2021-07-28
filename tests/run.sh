#!/bin/sh

echo "Init test of TSP Proyect at: " `date +\%Y-\%m-\%d--\%H-\%M`

LIST=$(ls tests/matrices/*.txt | cut -f 1 -d '.' | cut -d_ -f2-)

cd tests/matrices

# for loop 
for i in $LIST
do
    echo " "
    echo "######################################################### "
    echo "Test with a matrix with $i elements"
    FILE=$(ls *_$i.txt)
    echo "Execute " "./../build/tests/main-$i.out" " $FILE"
    ./../../build/tests/main-$i.out "$FILE" $1
    echo "Test: $i - OK"
    echo "######################################################### "
    echo " "
done