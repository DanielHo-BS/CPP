# Day7

Customizes the C++ operators for operands of user-defined types.

- Operator
  - Assignment operator
  - Stream extraction and insertion
  - Function call operator
  - Increment and decrement
  - Binary arithmetic operators
  - Comparison operators
  - Array subscript operator

## Syntax

Overloaded operators are functions with special function names:

---
operator op

---
operator type

---
operator new  
operator new []

---
operator delete  
operator deleta []

---
operator "" suffix-identifier (since C++11)

---
operator co_await (since C++20)

---

- overloaded operator;
- user-defined conversion function;
- allocation function;
- deallocation function;
- user-defined literal;
- overloaded co_await operator for use in co_await expressions.

### Overloaded operators

|Expression|As member function  |
|----------|--------------------|
|@a        |(a).operator@ ( )   |
|a@b       |(a).operator@ (b)   |
|a=b       |(a).operator= (b)   |
|a(b...)   |(a).operator()(b...)|
|a[b...]   |(a).operator[](b...)|
|a->       |(a).operator-> ( )  |
|a@        |(a).operator@ (0)   |

## Reference

[運算子多載](https://learn.microsoft.com/zh-tw/cpp/cpp/operator-overloading?view=msvc-170)

[operator overloading](https://en.cppreference.com/w/cpp/language/operators)
