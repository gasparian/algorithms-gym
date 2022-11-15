.ONESHELL:
SHELL := /bin/bash
.SILENT:

GCC:=g++
ifeq ($(shell uname -s), Darwin)
	GCC:=$(GCC)$(shell find /usr/local/bin -name "*g++*" | head -n 1 | rev | cut -d+ -f1 | rev)
endif

build:
	$(GCC) -std=c++11 -O2 -Wall ${target} -o $${target%.*}.o
