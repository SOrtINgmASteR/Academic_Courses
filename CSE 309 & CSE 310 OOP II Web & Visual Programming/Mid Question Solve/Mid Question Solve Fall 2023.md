# CSE 309 - Fall 2023

### Answer to the Question no 1

**(a)**:  
```python
def fun(*numbers):
    sum = 0
    avg = 0
    x = []
    for n in numbers:
        sum += n
    avg = sum / len(numbers)
    x.append(sum)
    x.append(avg)
    return x

x = fun(1, 2, 3, 4)
print(f"Sum: {x[0]} Avg: {x[1]}")

x = fun(1, 2, 3, 4, 5, 6)
print(f"Sum: {x[0]} Avg: {x[1]}")
```  

**(b)**  
```python
my_list = [1, 2, 3, 4 ,5 ,6 ,7, 8, 9, 10]
output = my_list[-2:-9:-2]
print(output)
```  

- [start : end : step]
- We know in list slicing the start index is inclusive & the end index is exclusive.   
- When the step index is negative it means reverse traversal.  
- So the output list will be every 2nd element from `-2` index to `-8` index in reverse order.  
- output = [9, 7, 5, 3]  

```python
addition = 0
for i in output:
    if i % 2 == 0:
        addition += i
print(addition)
```  

- Here `i` iterates over the `output` list and adds the elements of the list when it's divisible by 2
- so `addition` = 0. Because no element of the output list is divisible by 2.  


### Answer to the Question no 2

Corresponding HTML code for the given table-   

```html  
<table border="2">
    <tr>
        <th>Serial no</th>
        <th>Product name</th>
        <th>Product Price</th>
    </tr>
    <tr>
        <td>1</td>
        <td>Rice</td>
        <td>150</td>
    </tr>
    <tr>
        <td>2</td>
        <td>Meat</td>
        <td>350</td>
    </tr>
    <tr>
        <td colspan="2">Total</td>
        <td>500</td>
    </tr>
</table>
```  


### Answer to the Question no 3  

**(a)**  

```python
class Vehicle:
    def __init__(self, brand, model, year):
        self.brand = brand
        self.model = model
        self.year = year
    
    def describe(self):
        print(f"Brand: {self.brand}")
        print(f"Model: {self.model}")
        print(f"Year: {self.year}")

```   

**(b)**  

```python
class Car(Vehicle):
    def __init__(self, brand, model, year, milage, seat_capacity, color):
        super().__init__(brand, model, year)
        self.milage = milage
        self.seat_capacity = seat_capacity
        self.color = color

    def calculate_milage(self):
        return self.milage
```

**(c)**  

```python
my_car = Car("Toyota", "Prius", "2022", 25, 5, "Red")
my_car.describe()
print(f"Milage : {my_car.calculate_milage()}")
```
