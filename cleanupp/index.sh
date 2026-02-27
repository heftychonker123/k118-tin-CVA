#!/bin/bash
# Program to execute the cleanup files at regular intervals

filedir=$(cd "$(dirname "$0")" && pwd)

while true; do
    read -p "Do you want to cleanup all the files? (y/n): " choice

    if [ "$choice" = "n" ]; then
        echo "Skipping cleanup this round"
        sleep 3600
        continue
    fi

    # Loop through all scripts in the function directory
    for functions in "$filedir"/function/*; do
        [ -x "$functions" ] || continue   # skip non-executable files
        filename=$(basename "$functions")
        echo "Executing $filename"

        "$functions"
        status_code=$?

        if [ "$status_code" -eq 0 ]; then
            echo "$filename executed successfully"
        else
            echo "$filename executed unsuccessfully with return code $status_code"
        fi
    done

    echo "Completed the execution of all scripts"
    sleep 3600   # wait one hour before asking again
    for i in range
done
