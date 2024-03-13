



### CONCAT(a1, s1, a2, s2, .....)

```
SELECT CONCAT(first_name, " ", last_name) "Full Name"
FROM employees;
```

```
SELECT CONCAT(student_name, " ", dept_name)
FROM students;
```

### UPPER(a) & LOWER(a)

```
SELECT UPPER(student_name) "Upper", LOWER(student_name) 
FROM students;
```
