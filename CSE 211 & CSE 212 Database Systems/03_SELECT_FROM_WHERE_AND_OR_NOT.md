## SELECT & FROM

- `SELECT` is used for selecting attributes or columns.  
- `FROM` is used for selecting tables.  

### For showing all attributes or columns

```SQL
SELECT * 
FROM <table_name>;
```

```SQL
SELECT * 
FROM employees;
```

```SQL
SELECT * 
FROM food;
```

```SQL
SELECT * 
FROM undergraduate;
```

```SQL
SELECT * 
FROM suudents;
```

### For showing particular attributes or columns

```SQL
SELECT column1, column2, column3... 
FROM <table_name>;
```

```SQL
SELECT student_name, gender
FROM students;
```

```SQL
SELECT admission_date, gpa, waiver
FROM students;
```

```SQL
SELECT student_id, student_name, age 
FROM undergraduate;
```
## WHERE

- `WHERE` is used for applying condition  

```SQL
SELECT * 
FROM <table_name>
WHERE <condition>;
```

```SQL
SELECT * 
FROM students
WHERE gender = "Male";
```

```SQL
SELECT * 
FROM students
WHERE admission_date = '2022-03-03';
```

```SQL
SELECT * 
FROM students
WHERE gpa >= 3.8;
```

```SQL
SELECT * 
FROM students
WHERE gpa < 3.7;
```

```SQL
SELECT * 
FROM students
WHERE waiver = 75;
```

```SQL
SELECT * 
FROM employees
WHERE comission = 4;
```

```SQL
SELECT * 
FROM employees
WHERE hiring_date = '2012-12-12';
```

## Usecase of AND, OR & NOT  
- `AND`, `OR` & `NOT` is used for applying more complex conditions (range, inclusion & exclusion)

### For `AND` both needs to be true

```SQL
SELECT * 
FROM students
WHERE gender = "Male" AND gpa >= 3.8;
```

```SQL
SELECT * 
FROM students
WHERE admission_date >= '2022-04-04' AND waiver > 50;
```

Range :  
```SQL
SELECT * 
FROM students
WHERE gpa >= 3.7 AND gpa <= 3.8;
```

### For `OR` any one of needs to be true

```SQL
SELECT * 
FROM students
WHERE waiver = 75 OR waiver = 25;
```

```SQL
SELECT * 
FROM students
WHERE gender = "Male" OR gpa >= 3.8;
```

```SQL
SELECT * 
FROM students
WHERE admission_date >= '2022-04-04' OR waiver > 50;
```


### `NOT` reverses the conditoin

```SQL
SELECT * 
FROM students
WHERE NOT gender = "Male" AND gpa >= 3.8;
```

```SQL
SELECT * 
FROM students
WHERE NOT gender = "Male" AND NOT gpa >= 3.8;
```

```SQL
SELECT * 
FROM students
WHERE NOT admission_date >= '2022-04-04' AND NOT waiver > 50;
```

```SQL
SELECT * 
FROM students
WHERE NOT (gpa >= 3.7 AND gpa <= 3.8);
```

```SQL
SELECT * 
FROM students
WHERE NOT gender = "Male";
```