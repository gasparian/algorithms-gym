# algorithms-gym
Repo containing algorithmic problems solutions and data structures implementations  

## How to run  

*For mac-os users:*  
Since mac-os uses `clang` by default and here I'm using `bits/stdc++.h` header with all necessary imports, you'll need to install `gcc` and it will be used for compiling:  
```
brew install gcc
```  

Run `make` to compile all the tasks one by one. Binaries would be stored alongside with source code with the `*.{o|out}` ext.  
To run compiled program, navigate to the corresponding folder and execute binary (it will read needed input file from the same folder you are in):  
```
cd ./src/leetcode/191_number_of_bits && ./191_number_of_bits.o
```  

Or compile manually, after navigating to the task folder:  
```
g++ -std=c++11 -O2 -Wall 191_number_of_bits.cpp -o 191_number_of_bits.o
```  

*Hint:*  
Good tutorial fo C++ syntax which could be useful when you're not using it for a while: [C++ by example](https://cppbyexample.com/)  

