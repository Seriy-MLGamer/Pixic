from time import time

width: int=1000
height: int=1000

array: list=[0]*(width*height)
start: float=time()
a: int=0
y: int=0
while y!=height:
	x: int=0
	while x!=width:
		array[x+y*width]=a+1
		a=(a+1)%5
		x+=1
	y+=1
print("%u ms"%((time()-start)*1000))
print("%i\n%i\n%i\n%i"%(array[0+0*width], array[width-1+0*width], array[width-1+(height-1)*width], array[0+(height-1)*width]))