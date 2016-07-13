#!/usr/bin/env python
#coding=utf-8
import commands
import os

output = commands.getoutput('w')
output = output.split('\n')[2:]
for line in output:
    #print line
    new_line = line.replace('  ', ' ')
    while new_line != line:
        line = new_line
        new_line = line.replace('  ', ' ')
    #print line
    name, pts = line.split(' ')[:2]
    #if name == 'yanziang' or name == 'liuhu':
    if True:
        shell_cmd = 'echo "%s" > /dev/%s' % (msg, pts)
        os.system(shell_cmd)
        shell_cmd = 'sudo ttyecho -n /dev/%s "/usr/games/sl"' % pts
        os.system(shell_cmd)
        date = commands.getoutput("date +'%H:%M'")
        msg = '三点多了，大家起来休息一下 (%s) --by kalen wu' % date

