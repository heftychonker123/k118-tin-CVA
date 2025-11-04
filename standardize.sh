#!/bin/bash

# Loop through each directory
find . -type d | while read -r directory; do
    # Skip the root directory itself
    [ "$directory" = "." ] && continue
    [ "$(basename "$directory")" = "build" ] && continue

    # Loop through .cpp files in the directory
    for file in "$directory"/*.cpp; do
        [ -f "$file" ] || continue

        filename=$(basename "$file")
        dirname=$(basename "$directory")

        # If file starts with dirname_dirname, strip one
        if [[ "$filename" == "${dirname}_${dirname}"* ]]; then
            new_filename="${filename#*_}"
            mv "$file" "$directory/$new_filename"
            continue
        fi

        # If not already prefixed, add prefix
        if [[ "$filename" != "${dirname}_"* ]]; then
            mv "$file" "$directory/${dirname}_${filename}"
        fi
    done
done
