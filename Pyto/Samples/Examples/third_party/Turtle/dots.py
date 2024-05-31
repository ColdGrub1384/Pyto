# Taken from https://michael0x2a.com/blog/turtle-examples

from turtle import *

dot_distance = 25
width = 12
height = 12

speed(0)
goto(-140, 140)

up()

for y in range(height):
    for i in range(width):
        dot(3)
        fd(dot_distance)
    goto(-140)
    rt(90)
    fd(dot_distance)
    lt(90)
    
done()
