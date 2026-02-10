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

# Sanitize pname (replace spaces and special chars with underscores)
safe_pname=$(echo "$pname" | tr -d '\n' | tr -c '[:alnum:]_' '_')
filename="${cdtype}${cdnum}_${safe_pname}"

# Directories
filedir=$(dirname "$(realpath "$0")")
workdir=$(dirname "$filedir")
template="$workdir/template/template_boilerplate.cpp"
builddir="$workdir/build"

mkdir -p "$builddir"
# Check template exists
if [ ! -f "$template" ]; then
    echo "Template file not found: $template"
    exit 1
fi

# Create new file with boilerplate
{
    echo "#include <bits/stdc++.h>"
    echo "using namespace std;"
    echo "#define filename \"$safe_pname\""
    cat "$template"
} > "$builddir/$filename.cpp"

# Open in VS Code
if ! pwd >/dev/null 2>&1; then
    cd "$HOME"
fi
code "$builddir/$filename.cpp"
echo "Đã tạo file: $filename.cpp"

