# CSE 309 - Spring 2023

### Answer to the Question no 1  

HTML code for the Following Form-  

```html  
<form>
    <h1>HTML FORM</h1>
    
    <!Text areas>
    <label>Username: </label>
    <input type="text">
    <br>

    <label>Account ID: </label>
    <input type="number">
    <br>

    <label>E-mail: </label>
    <input type="email">
    <br>

    <label>Password: </label>
    <input type="password">
    <br>
    
    <label>Comment: </label>
    <textarea></textarea>
    <br>
    
    <!Radio Buttons>
    <label>Gender:    </label>
    <input type="radio" name="x">
    <label>Male</label>
    <input type="radio" name="x">
    <label>Female</label>
    <br>
    
    <!Check Boxes>
    <label>Hobbies:    </label>
    <input type="checkbox">
    <label>Gardening</label>
    <input type="checkbox">
    <label>Reading</label>
    <input type="checkbox">
    <label>Traveling</label>
    
    <!Submit Button>
    <br>
    <input type="submit">
</form>
```  

### Answer to the Question no 2

```python
list = [1, 2, 3, 4, 5]       # list = [1, 2, 3, 4, 5]
print(list[-1])              # 5 (list[-1] => 5)
list.append(6)               # 6 will be added to last so, list = [1, 2, 3, 4, 5, 6]
print(list)                  # [1, 2, 3, 4, 5, 6]
list.insert(2, 7)            # 7 will be inserted in the 2nd index os, list = [1, 2, 7, 3, 4, 5, 6]
print(list)                  # [1, 2, 7, 3, 4, 5, 6]
list.pop()                   # the last element 6 will be removed so, list = [1, 2, 7, 3, 4, 5]
print(list)                  # [1, 2, 7, 3, 4, 5]
list.remove(1)               # 1 will be removed from the list so, list = [2, 7, 3, 4, 5]
print(list)                  # [2, 7, 3, 4, 5]
list = list + [8, 9, 10]     # some new elements will be added so, list = [2, 7, 3, 4, 5, 8, 9, 10]
print(list)                  # [2, 7, 3, 4, 5, 8, 9, 10]
print(len(list))             # 8 (len(list) ==> 8)
print(list[1:4])             # [7, 3, 4] (value of 1 to 3 indexes)
print(list[:3])              # [2, 7, 3] (value of 0 to 2 indexes)
print(list * 2)              # The list will be printed two times [2, 7, 3, 4, 5, 8, 9, 10, 2, 7, 3, 4, 5, 8, 9, 10]
```  

Output -  

```
5
[1, 2, 3, 4, 5, 6]
[1, 2, 7, 3, 4, 5, 6]
[1, 2, 7, 3, 4, 5]
[2, 7, 3, 4, 5]
[2, 7, 3, 4, 5, 8, 9, 10]
8
[7, 3, 4]
[2, 7, 3]
[2, 7, 3, 4, 5, 8, 9, 10, 2, 7, 3, 4, 5, 8, 9, 10]
```  

### Answer to the Question no 3  

Out of Syllabus...