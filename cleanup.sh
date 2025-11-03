#!/bin/bash

# Move files to their designated positions
for file in build/*.cpp; do
    [ -f "$file" ] && echo "$file"
    [ -e "$file" ] || continue
    mkdir -p "$prefix"
    mv "build/$file" "$prefix/"
done

# Clean up the build directory
rm -rf build
mkdir build

# Git operations
git add .

# Use a default or custom commit message
msg="${1:-Auto commit from script}"
git commit -m "$msg"

git push origin main
