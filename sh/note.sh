#!/bin/bash
while true
do
echo "Phone number?"
read phone
echo "Name?"
read name
echo "Issue?"
read issue
now=`date "+%Y.%m.%d %H.%M.%S"`
echo "$now/$phone/$name/$issue" >> data.txt
echo "===== We got calls from ====="
cat data.txt | cut -d"/" -f2 | sort | uniq -c
echo "-----------------------------"
done
