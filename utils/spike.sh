#!/bin/bash

# Prompt the user for a file name
read -p "Enter the name of the file you want to compile: " filename

# go to the directory
cd "ASM/$filename"

# Compile the file
riscv64-unknown-elf-gcc $filename.c $filename.s -o main
spike $pk main

