# Taken from https://michael0x2a.com/blog/turtle-examples

from turtle import *

speed(0)

for i in range(180):
    fd(90)
    rt(30)
    fd(10)
    lt(60)
    fd(40)
    rt(30)
    
    up()
    setpos(0, 0)
    down()
    
    rt(2)
    
done()
