# Makefile for Operating Systems programs.

# Author: John M. Weiss, Ph.D.
# Adapted by Charles Parsons.

# Usage:  make 

#-----------------------------------------------------------------------

# GNU C/C++ compiler and linker:
CC = gcc
CXX = g++
LINK = g++

# Turn on optimization and warnings (add -g for debugging with gdb):
# CPPFLAGS = 		# preprocessor flags
CFLAGS = -O -Wall
CXXFLAGS = -O -Wall -std=c++11 -g


#-----------------------------------------------------------------------

# MAKE allows the use of "wildcards", to make writing compilation instructions
# a bit easier. GNU make uses $@ for the target and $^ for the dependencies.

all:    dash

# specific targets
dash:	dash.cpp commands.cpp commands.h
	$(LINK) $(CXXFLAGS) -o $@ $^

# utility targets
clean:
	rm -f *.o *~ dash
