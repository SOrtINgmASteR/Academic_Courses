## SELECT & FROM

- `SELECT` is used for selecting attributes or columns.  
- `FROM` is used for selecting tables.  

### For showing all attributes or columns

```
SELECT * 
FROM <table_name>;
```

```
SELECT * 
FROM employees;
```

```
SELECT * 
FROM food;
```

```
SELECT * 
FROM undergraduate;
```

```
SELECT * 
FROM suudents;
```

### For showing particular attributes or columns

```
SELECT column1, column2, column3... 
FROM <table_name>;
```

```
SELECT student_name, gender
FROM students;
```

```
SELECT admission_date, gpa, waiver
FROM students;
```

```
SELECT student_id, student_name, age 
FROM undergraduate;
```
## WHERE

- `WHERE` is used for applying condition  

```
SELECT * 
FROM <table_name>
WHERE <condition>;
```

```
SELECT * 
FROM students
WHERE gender = "Male";
```

```
SELECT * 
FROM students
WHERE admission_date = '2022-03-03';
```

```
SELECT * 
FROM students
WHERE gpa >= 3.8;
```

```
SELECT * 
FROM students
WHERE gpa < 3.7;
```

```
SELECT * 
FROM students
WHERE waiver = 75;
```

```
SELECT * 
FROM employees
WHERE comission = 4;
```

```
SELECT * 
FROM employees
WHERE hiring_date = '2012-12-12';
```

## Usecase of AND, OR & NOT  
- `AND`, `OR` & `NOT` is used for applying more complex conditions (range, inclusion & exclusion)

### For `AND` both needs to be true

```
SELECT * 
FROM students
WHERE gender = "Male" AND gpa >= 3.8;
```

```
SELECT * 
FROM students
WHERE admission_date >= '2022-04-04' AND waiver > 50;
```

Range :  
```
SELECT * 
FROM students
WHERE gpa >= 3.7 AND gpa <= 3.8;
```

### For `OR` any one of needs to be true

```
SELECT * 
FROM students
WHERE waiver = 75 OR waiver = 25;
```

```
SELECT * 
FROM students
WHERE gender = "Male" OR gpa >= 3.8;
```

```
SELECT * 
FROM students
WHERE admission_date >= '2022-04-04' OR waiver > 50;
```


### `NOT` reverses the conditoin

```
SELECT * 
FROM students
WHERE NOT gender = "Male" AND gpa >= 3.8;
```

```
SELECT * 
FROM students
WHERE NOT gender = "Male" AND NOT gpa >= 3.8;
```

```
SELECT * 
FROM students
WHERE NOT admission_date >= '2022-04-04' AND NOT waiver > 50;
```

```
SELECT * 
FROM students
WHERE NOT (gpa >= 3.7 AND gpa <= 3.8);
```

```
SELECT * 
FROM students
WHERE NOT gender = "Male";
```