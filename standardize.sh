#!/bin/bash

# Loop through each directory
find . -type d | while read -r directory; do
    # Skip the root directory itself
    [ "$directory" = "." ] && continue
    [ "$(basename "$directory")" = "build" ] && continue
    # Loop through files in the directory
    for file in "$directory"/*.cpp; do
        # Skip if it's not a regular file
        [ -f "$file" ] || continue

        # Get the base filename
        filename=$(basename "$file")

        # Get the directory name without path
        dirname=$(basename "$directory")

        # Rename the file by prefixing the directory name
        mv "$file" "$directory/${dirname}_${filename}"
    done
done
