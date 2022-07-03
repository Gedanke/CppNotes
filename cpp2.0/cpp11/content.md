# C++ 新特性

---

## C++11 新特性

* Variadic Templates
* Spaces in Template Expressions

```cpp
vector<list<int>> // ok in each C++ version
vector<list<int>> // before c++ 11 error error: ‘>>’ should be ‘> >’ within a nested template argument list,c++11后可以正常通过
nullptr and nullptr_t
```

* Automatic Type Deduction with auto
* Uniform Initialization
* initializer_list
* explicit for ctors taking more than one argument
* range-based for statement

```cpp
for(decl : col) {
    statement
}
```

* =default,=delete

```text
如果你自行定义了一个 ctor,那么编译器就不会给你一个default ctor 如果强制加上=default,就可以重新获得并使用default ctor.
```

* Alias(化名)Template(template typedef)
    * alias.cpp
    * template_template.cpp
* template template parameter
* type alias
* noexcept
* override
* final
* decltype
* lambda
* Rvalue reference
* move aware class
* 容器-结构与分类
    * 序列式容器包括：array(C++2.0新引入),vector,deque,list,forward_list(C++2.0新引入)
    * 关联式容器包括：set/multiset,map/multimap
    * 无序容器(C++2.0新引入,更换原先hash_xxx为unordered_xxx)包括：unordered_map/unordered_multimap,unordered_set/unordered_multiset
* Hash Function
* tuple
