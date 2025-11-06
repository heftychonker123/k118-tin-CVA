#!/bin/bash
# Clean up the build directory
rm -rf build
mkdir build

# Git operations
read -p "Commit message: " msg
git add .
git commit -m "$msg"
git push origin main