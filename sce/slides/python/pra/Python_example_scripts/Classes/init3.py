#!/usr/bin/python 

# yet another demo of class instantiation 

# this example creates/updates an address book entry 


class AddressBook:
	'address book entry class'

	def __init__(self, nm, ph):		# two-argument constructor 
		
		self.name = nm
		self.phone = ph
		print 'Created instance for:', self.name

	def updatePhone(self, newph):

		self.phone = newph
		print 'Updated phone# for:', self.name


I1=AddressBook('John Peter', '+91- 123-456-7890')

I2=AddressBook('Mary Joseph', '+91-40-112-233-4444') 

print I1.name, I1.phone  

print I2.name, I2.phone 

I1.updatePhone('+91-987-654-3210') 

print I1.name, I1.phone

