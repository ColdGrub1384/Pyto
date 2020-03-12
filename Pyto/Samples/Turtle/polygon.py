# Taken from https://michael0x2a.com/blog/turtle-examples

from turtle import *

num_sides = 6
side_length = 70
angle = 360.0 / num_sides

for i in range(num_sides):
    fd(side_length)
    rt(angle)
    
done()
