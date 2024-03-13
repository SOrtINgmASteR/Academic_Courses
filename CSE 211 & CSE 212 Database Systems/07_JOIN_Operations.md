## JOIN Operation
`JOIN` is used to combine rows from two or more tables, based on a related column between them. There are many kinds of JOIN operations :   
1. INNER JOIN
2. LEFT JOIN
3. RIGHT JOIN
4. SELF JOIN  

**To run all the queries first implement the `undergraduate`, `subjects` & `city` tables**  

### INNER JOIN

```SQL
SELECT u.student_name, s.subject_name
FROM undergraduate u 
INNER JOIN subjects s
ON u.subject = s.subject_id;
```

```SQL
SELECT u.student_name, s.subject_name, c.city_name
FROM undergraduate u 
INNER JOIN subjects s
ON u.subject = s.subject_id
INNER JOIN city c
ON u.city = c.city_id;
```

### LEFT JOIN

```SQL
SELECT u.student_name, c.city_name
FROM undergraduate u
LEFT JOIN city c
ON u.city = c.city_id;
```

```SQL
SELECT u.student_name, s.subject_name
FROM undergraduate u
LEFT JOIN subjects s
ON u.subject = s.subject_id;
```

```SQL
SELECT u.student_name, s.subject_name, c.city_name
FROM undergraduate u
LEFT JOIN subjects s
ON u.subject = s.subject_id
LEFT JOIN city c
ON u.city = c.city_id;
```

### RIGHT JOIN

```SQL
SELECT u.student_name, s.subject_name
FROM undergraduate u
RIGHT JOIN subjects s
ON u.subject = s.subject_id;
```

```SQL
SELECT u.student_name, c.city_name
FROM undergraduate u
RIGHT JOIN city c
ON u.city = c.city_id;
```

```SQL
SELECT u.student_name, s.subject_name, c.city_name
FROM undergraduate u
RIGHT JOIN subjects s
ON u.subject = s.subject_id
RIGHT JOIN city c
ON u.city = c.city_id;
```