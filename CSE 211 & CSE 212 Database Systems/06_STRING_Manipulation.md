### LIKE

- "%a%" If the attribute has an 'a' at anywhere 
```SQL
SELECT student_name
FROM students
WHERE student_name LIKE "%a%";
```

- "a%" If the attribute starts with an 'a'
```SQL
SELECT student_name
FROM students
WHERE student_name LIKE "a%";
```

- "%a" If the attribute ends with an 'a'
```SQL
SELECT student_name
FROM students
WHERE student_name LIKE "%a";
```

- "r%e" If the attribute starts with an 'a' & ends with an 'e'
```SQL
SELECT student_name
FROM students
WHERE student_name LIKE "r%e";
```

### CONCAT(a1, s1, a2, s2, .....)

- Contacts all the string attributes and parameters  

```SQL
SELECT CONCAT(student_name, " random ", dept_name, " random ") "Column Name"
FROM students;
```

```SQL
SELECT CONCAT(first_name, " ", last_name) "Full Name"
FROM employees;
```

```SQL
SELECT CONCAT(student_name, " ", dept_name)
FROM students;
```

### UPPER(a) & LOWER(a)

- Makes 'a' attributes lowercase or uppercase.  

```SQL
SELECT UPPER(student_name) "Upper", LOWER(student_name) "Lower"
FROM students;
```

### LENGTH(a)

- Gives the length of 'a' attribute.

```SQL
SELECT LENGTH(student_name)
FROM students;
```

```SQL
SELECT LENGTH(CONCAT(first_name, " ", last_name))
FROM employees;
```

### SUBSTR(a, x, y)

- Starts from x index (1 based indexing), prints y charecters.  

```SQL
SELECT SUBSTR(student_name, 3, 5)
FROM students;
```

```SQL
SELECT SUBSTR(student_name, 3, 50)
FROM students;
```

### REPLACE(a, s1, s2)

- Replaces 's1' with 's2' in 'a' attribute.  

```SQL
SELECT student_name, REPLACE(student_name,"Ra", "xoxo")
FROM students;
```

### INSTR(a, s)

- Finds the first occurrence of 's' in 'a' attribute.   

```SQL
SELECT student_name, INSTR(student_name, "ra")
FROM students;
```

