#!/bin/sh
if [ "$1" != "" ];
then
	sudo find $HOME -type f | grep $1
fi


