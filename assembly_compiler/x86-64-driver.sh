#!/bin/bash

if [ $# -ne 1 ]; then 
    echo "Input as: $0 <file path ending with .calc>"
    exit 1
fi

File=$1

tmp=$1
IFS='/' read -a hierarchy <<< $tmp
file_name=${hierarchy[-1]}

Output_File_name="$(echo $file_name | sed 's/\.calc$//').s"
Output_File_name_2="$(echo $file_name | sed 's/\.calc$//')"


compiler_path="bin/calc3i.exe"

if [ -e "$Output_File_name" ]; then
    rm "$Output_File_name"
fi

"$compiler_path" < "$File" >> "$Output_File_name"

echo "call exit_program" >> "$Output_File_name"

gcc -o $Output_File_name_2 $Output_File_name
