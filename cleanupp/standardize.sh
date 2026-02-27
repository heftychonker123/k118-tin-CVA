#!/bin/bash
set -euo pipefail
IFS=$'\n\t'
shopt -u nullglob

# Loop through each directory safely
find . -type d -print0 | while IFS= read -r -d '' directory; do
    # Skip the root directory itself and 'build'
    [ "$directory" = "." ] && continue
    [ "$(basename "$directory")" = "build" ] && continue

    # Loop through .cpp files in the directory
    shopt -s nullglob
    for file in "$directory"/*.cpp; do
        [ -f "$file" ] || continue

        filename=$(basename -- "$file")
        dirname=$(basename -- "$directory")

        # Strip prefix
        while [[ "$filename" == *"_"* ]]; do
            new_filename="${filename#*_}"
            target="$directory/$new_filename"

            # Avoid overwriting existing files
            if [ -e "$target" ]; then
                echo "Skipping rename: $target already exists"
                break
            fi

            echo "Renaming: $file → $target"
            mv -- "$directory/$filename" "$target"
            filename="$new_filename"
        done

        # Add prefix if missing
        if [[ "$filename" != "${dirname}_"* ]]; then
            new_filename="${dirname}_${filename}"
            target="$directory/$new_filename"

            if [ -e "$target" ]; then
                echo "Skipping rename: $target already exists"
                continue
            fi

            echo "Renaming: $directory/$filename → $target"
            mv -- "$directory/$filename" "$target"
        fi
    done
done
