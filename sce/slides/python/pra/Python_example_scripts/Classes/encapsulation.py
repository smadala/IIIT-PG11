#!/usr/bin/python 

# class definition to be used by 'data_hiding.py' 
# can be imported just like modules 


class privacy :

    def __init__(self, a, b):

        self.public = a			# a is public 
        self.__private = b		# b is a private member 

	
