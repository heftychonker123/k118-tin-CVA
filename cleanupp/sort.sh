#!/bin/bash
cd "$(dirname "$0")" || exit 1
filedir=$(pwd)
workdir=$(dirname "$filedir")

echo "Target folder name:"
read target
mkdir -p "$workdir/${target}_sorted"


for folders in "$workdir/$target"/*; do
    echo "Current folder being processed: $folders"
    for files in "$folders"/*; do
        code "$files"
        echo "Send to folder (empty filename to ignore):"
        read filename
        if [ -z "$filename" ]; then
            continue
        fi
        echo "Moving to: $workdir/${target}_sorted/$filename"
        mkdir "$workdir/${target}_sorted/$filename"
        mv "$files" "$workdir/${target}_sorted/$filename"
    done
    echo "$folders processed successfully"
done

echo "Sorted successfully"
