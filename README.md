# algorithms-gym
Repo containing various algorithmic problems solutions and data structures implementations  

## Project structure  
```
└── src
    ├── algorithms
    │   ├── cpp
    │   └── python
    ├── common
    │   ├── cpp
    │   └── python
    ├── data_structures
    │   ├── cpp
    │   └── python
    └── leetcode
        ├── cpp
        └── python
```
Each section split by the language, and the `common` folder should contain some generic functionality that could be reused across the code.  

## How to run  

### C++

*For mac-os users:*  
Since mac-os uses `clang` by default and here I sometimes use `bits/stdc++.h` header, you'll need to install `gcc` to sue it for compiling:  
```
brew install gcc
```  

Then compile the program:  
```
make compile target=./src/leetcode/cpp/191_number_of_bits.cpp
```  
and execute bunary:  
```
./src/leetcode/cpp/191_number_of_bits.o
```  
or:  
```
cd ./src/leetcode/cpp && ./191_number_of_bits.o
```  

The command to compile looks like this (the same as for Yandex.Contest platform):  
```
g++ -lm -O2 -fno-stack-limit -std=c++1z -x c++ <code> -o <object file name>
```  

### Python  

I've used `python3.8`. You can install and activate any version via [pyenv](https://github.com/pyenv/pyenv).  
To run the code, you can just call: 
```
python3 <script_name>.py
```  
Or compile the bytecode first like that: 
```
py_compile.compile(файл, doraise=True)
```  

### Links  

 - Good tutorial fo C++ syntax which could be useful when you're not using it for a while: [C++ by example](https://cppbyexample.com/)  