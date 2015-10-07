#!/usr/bin/env python
#coding=utf-8
__author__ = 'yanziang'

import glog as log
import gflags
import logging

FLAGS = gflags.FLAGS
FLAGS.verbosity = logging.DEBUG


def try_log():
    log.debug('2333happy deubgging....')
    log.info('it works')
    log.warn('something not ideal')
    log.error('something went wrong')
    log.fatal('AAAAAAAAAAA!')


if __name__ == '__main__':
    log.init()
    try_log()
