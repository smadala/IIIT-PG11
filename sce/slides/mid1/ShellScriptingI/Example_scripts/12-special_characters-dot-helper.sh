#!/bin/bash


echo "Child process ID is" $$

#Can access value of A as using same environment
echo "Value of A is $A"

exit 0 #This would exit the parent too if called with . (source) option

