#!/usr/bin/env python
import multiprocessing
import os


def f(x):
    print os.getpid()
    current = multiprocessing.current_process()
    print type(current._identity)
    print current._identity

p = multiprocessing.Pool()
p.map(f, range(6))
