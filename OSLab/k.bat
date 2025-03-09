#!/bin/bash
echo Name : Aditya Pandey
let choice=0
while [ $choice -ne 4 ]
do
echo Choose an option:
echo 1. Print Current Working Directory
echo 2. List files in the current directory
echo 3. Print current time
echo 4. Exit
read choice
case $choice in
 1)pwd;;
 2)ls -ldr;;
 3)date;;
 4)echo Exiting
 break;;
 *)echo Invalid choice;;
esac
done