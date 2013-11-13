#!/usr/bin/python 

# Function to print the elements of the Fibonacci series < = N 

def fib(N):    

     n1, n2 = 0, 1

     while n1 <= N:

           print n1,

           n1, n2 = n2, n1 + n2 
    
     return 0

print fib(1000)


