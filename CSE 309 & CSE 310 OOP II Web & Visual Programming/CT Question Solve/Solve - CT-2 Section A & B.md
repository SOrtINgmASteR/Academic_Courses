# CT - 2 Section A 

### Answer to the Question no 1

- Take two list as parameter
- Typecast both the list into set
- Use `&`(intersection) operator between them
- Typecast the result into another list, then return the list.

```python
def unique_common_elements(list_1, list_2):
    common_elements = list(set(list_1) & set(list_2))
    return common_elements
```

### Answer to the Question no 2

- Declare a new empty string to build the new string without duplicates.
- Declare a set to store characters that have been encountered.
- Traverse the given string & if any character not found in the set, add the character to the empty string.
- Track the encountered character with a set.

```python
def remove_duplicates(s):
    seen = set()
    result = ""
    for char in s:
        if char not in seen:
            result += char
            seen.add(char)
    return result
```


# CT - 2 Section A 