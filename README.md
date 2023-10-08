# algorithms-gym
Repo containing various algorithmic problems solutions and data structures implementations  

## Project structure  
Directories in the `src` split by topic/course/etc.:  
```
└── src
    ├── algorithms
    ├── common
    └── cses
    └── ...
```  
Each directory may contain multiple folders with implementations in different languages.  
The `common` folder should contain some generic functionality that could be reused across the code, like reading from `stdin` or file.  

## How to run  

### C++

*For mac-os users:*  
Since mac-os uses `clang` (which is good for the "real" development, btw) by default and here I sometimes use `bits/stdc++.h` header, you'll need to install `gcc` for using that header:  
```shell
brew install gcc
```  
The command to compile looks like this (the same as for most competitive programming platforms):  
```shell
g++ -lm -O2 -fno-stack-limit -std=c++1z -x c++ <code> -o <executable>
```
`clang` and "newer" C++:  
```
clang++ --std=c++20 -O3 -fsanitize=address,undefined -Wall -Wextra -Werror <code> -o <executable>
```  
Running with test examples:  
```shell
./my_object_file < test.txt
```  

### Python  

I've used `python3.8`. You can install and activate any version via [pyenv](https://github.com/pyenv/pyenv).  
To run the code, you can just call:  
```shell
python3 <file>
```
Or compile the bytecode first like that:  
```shell
py_compile.compile(<file>, doraise=True)
```  

### Go  

Run tests:  
```shell
go test -v -race <file>
```  

### Links  
 - [CSES problem set](https://cses.fi/problemset/);  
 - [Competitive programmer's handbook](https://cses.fi/book/book.pdf);  
 - [C++ refresher](https://cppbyexample.com/index.html);  
 - [C++ Yandex Handbook](https://academy.yandex.ru/handbook/cpp);  
 - [C++ best practices](https://lefticus.gitbooks.io/cpp-best-practices/content/);  
 - [MIT Algorithms video lectures](https://www.youtube.com/playlist?list=PLUl4u3cNGP63EdVPNLG3ToM6LaEUuStEY);  