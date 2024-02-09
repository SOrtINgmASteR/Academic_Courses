- showing databases - `SHOW DATABASES;`  
- creating databases - `CREATE DATABASE <database_name>;`  
- droping databases - `DROP DATABASE <database_name>;`  
- using a particular databases - `USE <database_name>;`  
- checking which database is in use - `SELECT database();`   
- creating a table - 
```
CREATE TABLE employees(
    employee_id int,
    first_name varchar(30),
    last_name varchar(30),
    email varchar(30),
    phone_number varchar(12),
    hiring_date date,
    salary int,
    comission int,
    manager_id int,
    department_id int,
    PRIMARY KEY (employee_id)
);
```
```
CREATE TABLE students (
    student_id int,
    first_name varchar(30),
    last_name varchar(30),
    hometown varchar(15),
    cgpa double(3, 2),
    PRIMARY KEY (student_id)
);
```
- showing all the tables - `SHOW TABLES;`  
- showing the structure of the table - `SHOW COLUMNS FROM <table_name>;`  or `DESC <table_name>;`  
- droping a table - `DROP TABLE <table_name>;`  
- inserting rows in table - 
```
INSERT INTO employees(employee_id, first_name, last_name, email, phone_number, hiring_date, salary, comission, manager_id, department_id)
VALUES (201, "Sharif Md.", "Yousuf", "22101128@uap-bd.edu", "01312345628", '2012-08-25', 25000, 2, 4001, 3),
       (202, "Faisal", "Hossain", "22101132@uap-bd.edu", "01312345632", '2008-02-01', 30000, 3, 4002, 3),
       (203, "Raier Rahman", "Ovi", "22101104@uap-bd.edu", "01312345604", '2007-08-25', 30000, 2, 4001, 4),
       (204, "MD Tausif", "Uddin", "22101112@uap-bd.edu", "01312345612", '2009-02-21', 30000, 4, 4001, 4),
       (205, "Mazharul Islam", "Sourav", "22101133@uap-bd.edu", "01312345633", '2003-02-11', 35000, 2, 4002, 2),
       (206, "Ahsan", "Sourav", "22101123@uap-bd.edu", "01312345623", '2002-08-23', 35000, 3, 4002, 2),
       (207, "Bokhtear Md.", "Abid", "22101124@uap-bd.edu", "01312345624", '2012-08-15', 25000, 2, 4002, 3),
       (208, "Mostafezur Rahman", "Mesbah", "22101126@uap-bd.edu", "01312345623", '2012-02-02', 25000, 3, 4001, 1);  
```
```
INSERT INTO students (student_id, first_name, last_name, hometown, cgpa)
VALUES(22101134, "Noor Mohammed", "Priom", "Cumilla", 3.30), 
      (22101133, "Mazharul Islam", "Sourav", "Gazipur", 3.30),
      (22101132, "Faisal", "Hossain", "Barisal", 3.30),
      (22101128, "Sharif Md.", "Yousuf", "Cumilla", 3.30),
      (22101104, "Raier Rahman", "Ovi", "Noakhali", 3.30);
```  

- showing all attributes from a table - `SELECT * FROM <table_name>;`  
- showing particular attributes from a table - `SELECT attribute_1, attribute_2 FROM <table_name>;`  
- changing the name of an attribute - `SELECT attribute_1 "Registration ID", attribute_2 "Final Result" FROM <table_name>;`  
- arithmatics operations for some attribute - `SELECT ((attribute_1 - 500) * 12) "Registration ID", attribute_2 "Final Result" FROM <table_name>;`
- concatination of attribute - `SELECT CONCAT(first_name, " " ,last_name) "Full Name", other_attribute FROM <table_name>;`  
