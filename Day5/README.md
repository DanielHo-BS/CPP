# Day5

In C++, it is possible to inherit attributes and methods from one class to another. We group the ``inheritance concept`` into two categories:

- derived class (child) - the class that inherits from another class
- base class (parent) - the class being inherited from

To inherit from a class, use the : symbol.

## Inheritance

- Rule
  - derived_class_name:name of the new class, which will inherit the base class
  - access-specifier: either of private, public or protected. If neither is specified, PRIVATE is taken as default
  - base-class-name: name of the base class

```cpp
class  <derived_class_name> : <access-specifier> <base_class_name>
{
        //body
}
```

- Access

```cpp
1. class ABC : private XYZ              //private derivation
            {                }
2. class ABC : public XYZ              //public derivation
            {               }
3. class ABC : protected XYZ              //protected derivation
            {              }
4. class ABC: XYZ                            //private derivation by default
{            }
```

- Virtual

  The virtual keyword is used to avoid ambiguity in multiple inheritance.

## Run the code

```bash
# Complier with CMake and Make
./rebuild.sh

# run all in ./build/<File Name>
./build/*
```

## Reference

[Inheritance in C++](https://www.geeksforgeeks.org/inheritance-in-c/)

[C++中關於 virtual 的兩三事](https://medium.com/theskyisblue/c-%E4%B8%AD%E9%97%9C%E6%96%BC-virtual-%E7%9A%84%E5%85%A9%E4%B8%89%E4%BA%8B-1b4e2a2dc373)

[What is Virtual Inheritance?](https://www.freecodecamp.org/news/what-is-virtual-inheritance/)
