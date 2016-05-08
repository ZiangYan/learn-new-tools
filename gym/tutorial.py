#!/usr/bin/env python
import gym
import glog as log


env = gym.make('CartPole-v0')
env.reset()
for iter_idx in range(100000):
    log.info('Iteration %d' % iter_idx)
    observation = env.reset()
    for t in xrange(100):
        env.render()
        print observation
        action = env.action_space.sample()
        observation, reward, done, info = env.step(action)
        if done:
            print "Episode finished after {} timesteps".format(t+1)
            break
