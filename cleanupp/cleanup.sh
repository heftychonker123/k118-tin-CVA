#!/bin/bash

# Move files to their designated positions
for file in ../build/*.cpp; do
    [ -f "$file" ] || continue

    echo "Processing: $file"

    filename=$(basename "$file")
    prefix="${filename%%_*}"

    # Skip if no underscore found
    [ "$prefix" = "$filename" ] && continue

    # Create target directory and move file
    mkdir -p "../$prefix"
    mv "$file" "../$prefix/"
done

# Clean and recreate build directory
rm -rf ../build
mkdir ../build
