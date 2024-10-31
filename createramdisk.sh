#!/bin/sh

echo "RAM PRE:"
/data/john/wttesting/dropcache.sh
free -h

mkdir -p /data/john/ramdisk

if mount -t ramfs -o size=$1Gi ramfs /data/john/ramdisk; then
    dd if=/dev/zero iflag=fullblock of=/data/john/ramdisk/biggbfile bs=1G count=$1
fi

echo "RAM POST:"
/data/john/wttesting/dropcache.sh
free -h
