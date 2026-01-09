#!/bin/bash

# Get the directory containing the script
filedir=$(cd "$(dirname "$0")" && pwd)
# Get the parent directory
workdir=$(dirname "$(dirname "$filedir")")
# Ensure globbing behaves nicely (skip if no matches)
shopt -s nullglob

# Move files to their designated positions
for file in "$workdir"/build/*.cpp; do
    filename=$(basename "$file")
    prefix="${filename%%_*}"
    echo "Processing: $filename"
    # Skip if no underscore found
    [ "$prefix" = "$filename" ] && continue

    # Create target directory
    mkdir -p "$workdir/$prefix"
    echo
    echo "Moving file : $filename"
    mv "$file" "$workdir/$prefix"
    echo "From : $workdir/build"
    echo "To   : $workdir/$prefix"
    echo
    sleep 0.5;
done

# Clean and recreate build directory safely
if [ -d "$workdir/build" ]; then
    rm -rf "$workdir/build"
fi
mkdir "$workdir/build"
echo "Code execution successful."
