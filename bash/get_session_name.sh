#!/bin/bash

set -u

name=$(tmux ls 2>/dev/null)
if [ $? -eq 0 ] ; then
    echo $name | grep monitor &>/dev/null
    if [ $? -eq 0 ] ; then
        name=$(tmux ls | grep monitor | cut -d':' -f1)
        echo "session: "$name
        tmux attach -t $name
    else
        echo "tmux session found, no monitor"
    fi
else
    echo "no tmux session found"
fi

