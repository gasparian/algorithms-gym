.ONESHELL:
SHELL := /bin/bash
.SILENT:
DEFAULT_GOAL := build

GCC:=g++
ifeq ($(shell uname -s), Darwin)
	GCC:=$(GCC)$(shell find /usr/local/bin -name "*g++*" | head -n 1 | rev | cut -d+ -f1 | rev)
endif

define compile_all_tasks
for dir in ./src/leetcode; \
do \
	for src in $${dir}/*.cpp; \
		do \
 			$(GCC) -std=c++11 -O2 -Wall $${src} -o $${src%.*}.o; \
		done; \
done
endef

.PHONY: build
build:
	$(call compile_all_tasks)