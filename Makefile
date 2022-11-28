.ONESHELL:
SHELL := /bin/bash
.SILENT:

GCC:=g++
ifeq ($(shell uname -s), Darwin)
	GCC:=$(GCC)$(shell find /usr/local/bin -name "*g++*" | head -n 1 | rev | cut -d+ -f1 | rev)
endif

compile:
	$(GCC) -std=c++1z -lm -O2 -Wall -fno-stack-limit -x c++ ${target} -o $${target%.*}.o
