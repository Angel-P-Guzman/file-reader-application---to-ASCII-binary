================================================================================
README

Author: Angel Guzman

Filename: README

================================================================================

# Project Description

This is a file reader application that will open and read any byte in the user-specified file,
        writing the result in printable (human-readable) ASCII hexadecimal or binary format for each byte.

## File Manifest

- main.cpp
- make
- README

## Compile Instructions

To compile the program, use the following command:

Use the make command to run the compile instructions that are in the makeFile.

## Operating Instructions

Usage:
        ./xed [-b] <file_path> <binary|hex>

    Options:
        -b          : Output in binary format.
        file_path   : Path to the input file.
        binary|hex  : Specify 'binary' or 'hex' for the output format.

## Issues and writing the program: 

Originally I had the belief that we were writing our outputs for either hex or binary as a .txt file. Most of the functionally is the same
except for the four or so lines I had to alter to correctly output to the terminal instead of a text file. Though I believe that the rest
of the program is fairly straight forward. The counters for both the binary and the hex start at 00000000 for the adresses. 