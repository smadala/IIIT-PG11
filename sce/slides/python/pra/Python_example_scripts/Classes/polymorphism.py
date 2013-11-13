#!/usr/bin/python

# Demo of polymorphism in Python 

class Animal:
    def __init__(self, name):                    # Constructor of the class
        self.name = name

    def talk(self):             
        raise NotImplementedError("Subclass must implement abstract method")
 

class Cat(Animal):
    def talk(self):
        return 'Meow!'

 
class Dog(Animal):
    def talk(self):
        return 'Woof! Woof!'
 

animals = [Cat('Missy'),
           Dog('Lassie')]

 
for animal in animals:
    print animal.name + ': ' + animal.talk()
 
 
