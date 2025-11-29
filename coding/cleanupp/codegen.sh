#!/bin/bash

echo "Loại bài là gì? :"
read cdtype
cdnum=""
if [ "$cdtype" = "CĐ" ]; then
    echo "CĐ thứ bao nhiêu? :"
    read cdnum
fi

echo "Tên bài là gì? :"
read pname

# Sanitize pname (replace spaces with underscores)
safe_pname=$(echo "$pname" | tr ' ' '_')

filename="${cdtype}${cdnum}_${safe_pname}"

# Directories
filedir=$(dirname "$(realpath "$0")")
workdir=$(dirname "$filedir")
template="$workdir/template/template_boilerplate.cpp"
builddir="$workdir/build"

mkdir -p "$builddir"

# Create new file with boilerplate
{
    echo "#include <bits/stdc++.h>"
    echo "using namespace std;"
    echo "#define filename \"$pname\""
    cat "$template"
} > "$builddir/$filename.cpp"

# Open in VS Code
code "$builddir/$filename.cpp"
echo "Đã tạo file: $filename.cpp"
