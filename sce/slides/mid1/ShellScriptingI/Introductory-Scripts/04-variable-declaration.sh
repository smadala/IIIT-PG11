#!/bin/sh

# Declaration Syntax: <variableName>=<value> 
# Without spaces in between
# To access value use $<variableName>

MY_MESSAGE="Hello World"
echo $MY_MESSAGE

# This line will produce an error as spaces
# will make shell interpret the line as
# a command MY_VAR called with parameters:
# = and "MyValue"
MY_VAR = "My value"
