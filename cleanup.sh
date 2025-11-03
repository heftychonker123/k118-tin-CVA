#!/bin/bash

#move file to their designated pos
for file in build/*:*.cpp ; do
    prefix="${file%%:*}"

    mkdir -p "$prefix"

    mv "$file" "$prefix/"
done

#clean up the build directory
rm -rf build;
mkdir build;


read -p "Enter commit message: " msg

git add .
git commit -m "$msg"
git push origin main

