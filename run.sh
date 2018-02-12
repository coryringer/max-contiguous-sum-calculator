#!/bin/sh

# variables
PROG_SUCCESS="Program compiled successfully."
PS_WRITTEN="PostScript file written."

make && echo $PROG_SUCCESS
make clean
./maxcontig && echo $PS_WRITTEN
