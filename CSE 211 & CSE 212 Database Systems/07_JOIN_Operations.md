```
SELECT u.student_name, s.subject_name
FROM undergraduate u 
JOIN subjects s
ON u.subject = s.subject_id;
```

```
SELECT u.student_name, s.subject_name, c.city_name
FROM undergraduate u 
JOIN subjects s
ON u.subject = s.subject_id
JOIN city c
ON u.city = c.city_id;
```

```
SELECT u.student_name, s.subject_name, c.city_name
FROM undergraduate u 
INNER JOIN subjects s
ON u.subject = s.subject_id
INNER JOIN city c
ON u.city = c.city_id;
```