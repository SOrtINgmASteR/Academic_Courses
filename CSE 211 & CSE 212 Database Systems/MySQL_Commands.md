- showing databases - `SHOW DATABASES;`  
- creating databases - `CREATE DATABASE <database_name>;`  
- droping databases - `DROP DATABASE <database_name>;`  
- using a particular databases - `USE <database_name>;`  
- checking which database is in use - `SELECT dayabase();`   
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
INSERT INTO students (student_id, first_name, last_name, hometown, cgpa)
VALUES	(22101134, "Noor Mohammed", "Priom", "Cumilla", 3.30),
		(22101133, "Mazharul Islam", "Sourav", "Gazipur", 3.30),
        (22101132, "Faisal", "Hossain", "Barisal", 3.30),
        (22101128, "Sharif Md.", "Yousuf", "Cumilla", 3.30),
        (22101104, "Raier Rahman", "Ovi", "Noakhali", 3.30);
```  

- showing all attributes from a table - `SELECT * FROM <table_name>;`  
- showing particular attributes from a table - `SELECT attribute_1, attribute_2 FROM <table_name>;`  
- changing the name of an attribute - `SELECT attribute_1 "Registration ID", attribute_2 "Final Result" FROM <table_name>;`  
- arithmatics operations for some attribute - `SELECT ((attribute_1 - 500) * 12) "Registration ID", attribute_2 "Final Result" FROM <table_name>;`
- concatination of attribute - 