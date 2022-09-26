.ONESHELL:
SHELL := /bin/bash
# .SILENT:
DEFAULT_GOAL := build

# TODO: make it work
define compile_all_tasks = 
for dir in ./src/leetcode/*
do 
	for src in ${dir}*.cpp
		do 
			g++ -std=c++11 -O2 -Wall ${src} -o ${src%.*}.o
		done
done
endef

.PHONY: build
build:
	$(call compile_all_tasks)