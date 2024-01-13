#!/bin/bash

for var in "$@"
do
    rsync --verbose "$var" hri7566@192.168.1.71:/var/www/home.hri7566.info/$(basename "$var")
done
