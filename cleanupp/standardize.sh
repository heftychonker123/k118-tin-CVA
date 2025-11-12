#!/bin/bash

# Loop through each directory
find . -type d | while read -r directory; do
    # Skip the root directory itself and 'build'
    [ "$directory" = "." ] && continue
    [ "$(basename "$directory")" = "build" ] && continue

    # Loop through .cpp files in the directory
    for file in "$directory"/*.cpp; do
        [ -f "$file" ] || continue

        filename=$(basename "$file")
        dirname=$(basename "$directory")

        # Strip repeated prefix
        while [[ "$filename" == "${dirname}_${dirname}"* ]]; do
            new_filename="${filename#*_}"
            mv "$directory/$filename" "$directory/$new_filename"
            filename="$new_filename"  # Update filename for next loop iteration
        done

        # Add prefix if missing
        if [[ "$filename" != "${dirname}_"* ]]; then
            mv "$directory/$filename" "$directory/${dirname}_${filename}"
        fi
    done
done
