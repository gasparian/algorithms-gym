Compile:  
```
g++ -std=c++11 -Werror %FILE_1%.cpp %FILE_2%.cpp -o %NAME%
```  
or to compile all code in folder:  
```
g++ -std=c++11 -Werror *.cpp -o %NAME%
```  
or if you need to use newer version of compiler:  
```
g++-7 -std=c++1z -Werror %FILE%.cpp -o %NAME%
```  

Zipping the folder with solution:  
```
zip -r %filename%.zip /path/to/folder
```  
