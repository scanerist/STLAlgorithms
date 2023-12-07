# Алгоритмы STL, xrange, zip

### Алгоритмы

- **all_of** - returns true if all elements in the range satisfy a certain predicate. Otherwise, false.
- **any_of** -  returns true if at least one element in the range satisfies a certain predicate. Otherwise, false.
- **none_of** - returns true if none of the elements in the range satisfy a certain predicate. Otherwise, false.
- **one_of** - returns true if exactly one element in the range satisfies a certain predicate. Otherwise, false.
- **is_sorted** -  returns true if all elements in the range are in sorted order according to a certain criterion.
- **is_partitioned** - returns true if there is an element in the range that divides all elements into those satisfying and not satisfying a certain predicate. Otherwise, false.
- **find_not** -  finds the first element not equal to a given value.
- **find_backward** - finds the first element equal to a given value, starting from the end.
- **is_palindrome** - returns true if the given sequence is a palindrome according to a certain condition. Otherwise, false.

### xrange
- xrange(start, end)
- xrange(end)
- xrange(start, end, step)

```cpp
auto x = xrange(1.5, 5.5);
std::vector<int> v{x.begin(), x.end()}; // 1.5 2.5 3.5 4.5
```

```cpp
auto x = xrange(4);
std::vector<int> v{x.begin(), x.end()}; // 0 1 2 3
```

```cpp
// 1 3 5
for(auto i : xrange(1, 6, 2)) {
    std::cout << i <<  " ";
}
```
### zip

example:
```c++
std::list l = {1, 2, 3, 4, 5};
std::vector v = {'a', 'b, 'c', 'd'};
/*
1 a
2 b
3 c
4 d
*/
for(auto value : zip(l, v)) {
  std::cout << value.first << " " << value.second << std::endl;
}
```