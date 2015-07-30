#!/bin/bash 
# My first script

# There must be a space between [ and -d
# There also must be a space between .bashrc and ]
#if [ -f ~/.bashrc ]; then
#    echo "You have a .bashrc file in your home directory"
#else
#    echo "You do not have a .bashrc file"
#fi
#
#if [ $(id -u) -eq "0" ]; then
#    echo "You are superuser"
#else
#    echo "You are not superuser"
#    echo "You must run this script as superuser" >&2
#fi
#
#echo "Enter the IP Address"
#read ip
#
#if [ ! -z $ip ]; then
#    ping -c 1 $ip
#    if [ $? -eq 0 ]; then
#        echo "Machine is giving ping response"
#    else
#        echo "Machine is not pinging"
#    fi
#else
#    echo "IP Address is empty"
#fi

#echo -n "Enter a number between 1 and 3 inclusive > "
#read character
#case $character in
#    [a-z] | [A-Z] ) echo "You entered a letter" 
#        ;;
#    [0-9] ) echo "You entered a digit"
#        ;;
#    * ) echo "You enter something else"
#        ;;
#esac

selection=
until [ "$selection" = "0" ]; do
        echo ""
        echo "PROGRAM MENU"
        echo "1 - display free disk space"
        echo "2 - display free memory"
        echo ""
        echo "0 - exit program"
        echo ""
        echo -n "Enter selection: "
        read selection
        echo ""
        case $selection in
            1 ) df ;;
            2 ) free ;;
            0 ) exit ;;
            * ) echo "Please enter 1, 2, or 0"
        esac
done
