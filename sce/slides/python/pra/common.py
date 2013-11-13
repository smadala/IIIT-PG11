
def common(l1,l2):
	cm=[]
	for i in range( len(l1) ):
		if l1[i] in l2:
			cm.append(l1[i])

	print cm


li1=[1,3,5,7,8]
li2=[2,3,5,4,6,8]
common(li1,li2)
	
