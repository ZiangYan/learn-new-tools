# 简介
截止2015.10.7,Google官方从未对外开放过glog模块的python版,现有的python版glog模块是网友们仿照Google开放的glog C++版写的简单log库.

# 用法
* 不是debug时:

        import glog as log
        log.info('Hey')
        log.warn('something seems abnormal')
        log.error('something went wrong')
        log.fatal('AAAAAAAAA!')

* 是debug时:

        import glog as log
        import gflags 
        import logging
        FLAGS = gflags.FLAGS
        FLAGS.verbosity = logging.DEBUG
        log.init()
        log.debug('This is a debug message')
        
在这些log等级中,debug是最低的,log模块默认从INFO开始显示.因此在发行版中,只要把verbosity设为INFO,就不会显示debug信息,防止刷屏