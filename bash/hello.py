#!/usr/bin/env python
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
    msg = 'Broadcast message from zcs@FIT3-117\n\
            (/dev/pts/2) at 10:30 ...\n\
                                 \n\
%s, you have made good work, keep doing well and I\'ll buy you a NIPS candy!' % name
    print msg
    shell_cmd = 'echo "%s" > /dev/%s' % (msg, pts)
    print shell_cmd + '\n'
    os.system(shell_cmd)

