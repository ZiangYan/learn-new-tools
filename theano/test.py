import theano
from theano import tensor as T
from theano import function
from theano import Param
from theano import shared
import numpy as np


def test():
    # multiple inputs, multiple outputs
    a, b = T.dmatrices('a', 'b')
    diff = a - b
    abs_diff = T.abs_(diff)
    sqr_diff = diff ** 2
    f = function([a, b], [diff, abs_diff, sqr_diff])
    h, i, j = f([[0, 1], [2, 3]], [[4, 5], [6, 7]])

    # default value for function arguments
    a, b = T.dscalars('a', 'b')
    z = a + b
    f = function([a, Param(b, default=1)], z)
    print f(1, b=2)
    print f(1)
    print f(1, 2)

    # shared variable
    state = shared(0)
    inc = T.lscalar('inc') # state is int64 by default
    accumulator = function([inc], state, updates=[(state, state + inc)])
    print accumulator(300)
    print state.get_value()


if __name__ == '__main__':
    test()
