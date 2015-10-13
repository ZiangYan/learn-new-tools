#!/usr/bin/env python
import matplotlib.pylab as plt
import numpy as np

__author__ = 'yanziang'


X = np.linspace(-np.pi, np.pi, 256, endpoint=True)
C, S = np.cos(X), np.sin(X)

fig = plt.figure(2)

ax = fig.add_subplot(121)
ax.plot(X, S, color='blue', label='cosine')
ax.plot(X, C, color='red', label='sin')
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_title('sin(x)')
ax.legend(loc='upper left', frameon=False)

ax = fig.add_subplot(122)
ax.plot(X, C)
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_title('cos(x)')

plt.savefig('cos.jpg')
plt.clf()



ax = fig.add_subplot(121)
ax.plot(X, S, color='blue', label='cosine')
ax.plot(X, C, color='red', label='sin')
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_title('sin(x)')
ax.legend(loc='upper left', frameon=False)

ax = fig.add_subplot(122)
ax.plot(X, C)
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_title('cos(x)')

plt.savefig('cos2.jpg')



