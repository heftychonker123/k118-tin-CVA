#!/bin/bash

echo "Loại bài là gì? :"
read cdtype
cdnum=""
pname=""

if [ "$cdtype" = "CĐ" ]; then
    echo "CĐ thứ bao nhiêu? :"
    read cdnum
fi
while [ -z "$pname" ]; do
    echo "Tên bài là gì? :"
    read pname
done

# Sanitize pname (replace sp