# CT - 1 Section A 

### Answer to Question no 1  

Taking user input-  

```python
number_list = []
n = int(input("Enter n: "))
print("Enter list elements: ")
for i in range(n):
    x = int(input())
    number_list.append(x)
print(number_list)

# calling functions to do the given tasks
avg = find_average(number_list)
print(avg)

unique_list = remove_duplicate(number_list)
print(unique_list)
```

Function for finding average of the numbers-  

```python
def find_average(number_list):
    summation = 0
    average = 0
    for n in number_list:
        summation += n
    average = summation / len(number_list)
    return average
```

We can use two approach to remove duplicate elements-  

**First approach:**

- In the First approach we will take a list as parameter.
- Then we will typecast the list into set.
- Then again typecast the set in to list.
- This will change the order of the list.
  
```python
def remove_duplicate(number_list):
    unique_list = list(set(number_list))
    return unique_list
```

**Second approach:**

- In the Second approach we will take a list as parameter.
- Then we declare a empty list, & start traversing the given list.
- If any element is not found in the empty list, we will append the the element in the empty list.
  
```python
def remove_duplicate(number_list):
    unique_list = []
    for n in number_list:
        if n not in unique_list:
            unique_list.append(n)
    return unique_list
```

### Answer to Question no 2  

Function for removing unwanted spaces from the beginning and end of the string-  

```python
def remove_unwanted_spaces(my_string):
    striped_string = my_string.strip()
    return striped_string
```  

Function for counting all the vowels-  

- We will predefine a string which will contain all the vowels & a count variable to 0.  
- The we will traverse the given string, if any character found in vowel string we will increase the count.

```python
def count_vowels(my_string):
    vowels = "AEIOUaeiou"
    vowel_count = 0
    for char in my_string:
        if char in vowels:
            vowel_count += 1
    return vowel_count
```

# CT - 1 Section B 


### Answer to Question no 1