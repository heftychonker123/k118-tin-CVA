#!/bin/bash

# Move files to their designated positions
for file in build/*.cpp; do
    [ -f "$file" ] || continue

    echo "Processing: $file"

    # Extract prefix before colon (e.g., foo from foo:bar.cpp)
    filename=$(basename "$file")
    prefix="${filename%%:*}"

    # Skip if no colon found
    [ "$prefix" = "$filename" ] && continue

    # Create target directory and move file
    mkdir -p "$prefix"
    mv "$file" "$prefix/"
done

