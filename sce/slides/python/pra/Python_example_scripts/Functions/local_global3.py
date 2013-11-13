#!/usr/bin/python 



S='I am global' 

def f():
       
    #  global S 			# notice the 'global' keyword
      S='hi'
      print S 
       
  
      S='I am now Local' 

      print S 


f()                        # call f()

print S 

 
