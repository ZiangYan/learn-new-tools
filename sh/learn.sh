#!/bin/bash 
# My first script

# There must be a space between [ and -d
# There also must be a space between .bashrc and ]
if [ -f ~/.bashrc ]; then
    echo "You have a .bashrc file in your home directory"
else
    echo "You do not have a .bashrc file"
fi

if [ $(id -u) -eq "0" ]; then
    echo "You are superuser"
else
    echo "You are not superuser"
    echo "You must run this script as superuser" >&2
fi

echo "Enter the IP Address"
read ip

if [ ! -z $ip ]; then
    ping -c 1 $ip
    if [ $? -eq 0 ]; then
        echo "Machine is giving ping response"
    else
        echo "Machine is not pinging"
    fi
else
    echo "IP Address is empty"
fi
