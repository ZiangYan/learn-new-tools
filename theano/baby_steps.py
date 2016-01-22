#!/usr/bin/env python
import theano.tensor as T
from theano import function
from theano import pp

# add two scalars
print 'add two scalars'
x = T.dscalar('x')
y = T.dscalar('y')
z = x + y
print pp(z)
f = function([x, y], z)

print f(3, 2)
print f(1.2, 3.4)


# add two matrices
print 'add two matrices'
x = T.dmatrix('x')
y = T.dmatrix('y')
z = x + y
f = function([x, y], z)
print pp(z)
print f([[1.0]], [[2.0]])
print f([[1.0, 1.0], [1.0, 1.0]], [[1.0, 1.0], [1.0, 1.0]])

