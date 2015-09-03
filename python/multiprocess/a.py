from multiprocessing import Pool
import numpy as np


def func(x):
    A = np.random.random((2000, 2000))
    U, S, V = np.linalg.svd(A)
    print 'done'

if __name__ == '__main__':
    pool = Pool(processes=3)
    result = pool.map(func, range(100))
    print 'before close'
    pool.close()
    print 'before join'
    pool.join()
    print 'before exit'
