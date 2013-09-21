#!/bin/bash

A[0]='This is first value'
A[1]='This is second value'
echo "A. Array A has values ${A[0]} and ${A[1]}"
echo
echo


#Array values need not be contiguos
B[3]='March'
B[11]='November'
echo 'B. Third and eleventh months are' ${B[3]} and ${B[11]}
echo
echo


#Array can be initialized using () brackets
#Array indexing by default would start with zero
#Uninitialized indexes return null
C=(zero one two three four five six seven eigth nine ten)
echo "C. 0=${C[0]} 5=${C[5]} 10=${C[10]} 17=${C[17]}"
echo
echo


#Non-zero indexing can be done in following manner
D=([17]="seventeen" [24]="twenty four")
echo "D. 17=${D[17]},  24=${D[24]}"
echo
echo


#Treating normal variable as array
#the variables value would be available at 
#index 0
E="I am normal"
echo "E. 0=${E[0]}, 1=${E[1]}"
echo
echo

exit 0


