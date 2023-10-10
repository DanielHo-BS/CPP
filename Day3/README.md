# Day 3

Static Function and Static Member.

- static_member.cpp

  1. Static members belong to the class rather than individual objects.
  2. Non-const static members need to be initialized outside the class definition.
  3. They can be accessed using the name of an object instance or the class name followed by the :: operator.
   Typically, the class name followed by :: is used to access them, which can help avoid confusion with non-static data members.
  4. Static members also adhere to public, protected, and private access restrictions.

- inline.cpp: ``lambda`` mehtod
- predeclare.cpp
- constructor.cpp: to create a constructor, use the same name as the class.
- Projects
  - swap.cpp
  - poolPrice.cpp

## Run the code

```bash
# Complier with CMake and Make
./rebuild.sh

# run all in ./build/<File Name>
./build/poorPrice
```

## Reference

[C++筆記 靜態成員Static Member、靜態函數Static Function](https://medium.com/%E9%87%8F%E5%8C%96%E4%BA%A4%E6%98%93%E7%9A%84%E8%B5%B7%E9%BB%9E-%E9%82%81%E5%90%91%E9%87%8F%E5%8C%96%E4%BA%A4%E6%98%93%E7%85%89%E9%87%91%E8%A1%93%E5%B8%AB%E4%B9%8B%E8%B7%AF/c-%E7%AD%86%E8%A8%98-%E9%9D%9C%E6%85%8B%E6%88%90%E5%93%A1-static-member-%E9%9D%9C%E6%85%8B%E5%87%BD%E6%95%B8-static-function-3cc370f3fca6)

[C++ inline](https://learn.microsoft.com/zh-tw/cpp/cpp/inline-functions-cpp?view=msvc-170)

[C++ Constructors](https://www.w3schools.com/cpp/cpp_constructors.asp#gsc.tab=0)
