#!/usr/bin/env python
import theano.tensor as T
from theano import function
from theano import pp
x = T.dscalar('x')
y = T.dscalar('y')
z = x + y
print pp(z)
f = function([x, y], z)

print f(3, 2)
print f(1.2, 3.4)

