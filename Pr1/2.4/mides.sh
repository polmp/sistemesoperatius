#!/bin/sh
chmod 700 $0
var=$(ls $1 | wc -l)
if [ "$var" = "0" ] 
then
	ls -all | awk '{print $5}'
else 
	ls -all | awk '{print $5}'
fi


