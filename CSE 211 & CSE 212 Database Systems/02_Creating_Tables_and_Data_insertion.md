## Table Information
- showing all the tables in a databases - `SHOW TABLES;`  
- showing the structure/columns of the table - `SHOW COLUMNS FROM <table_name>;`  or `DESC <table_name>;` *Example :* `SHOW COLUMNS FROM employees;`, `SHOW COLUMNS FROM students;`, `SHOW COLUMNS FROM food;`   
- droping a table - `DROP TABLE <table_name>;` *Example :* `DROP TABLE city;`, `DROP TABLE subjects`, `DROP TABLE employees`  

## Creating a Table  
```
CREATE TABLE students(
    id int,  
    student_name varchar(50),  
    gender varchar(10),  
    dept_name varchar(20),  
    admission_date date,  
    fees decimal(8,2),  
    waiver int,  
    gpa double(3, 2),  
    advisor_name varchar(20),  
    primary key (id)
);
```

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
CREATE TABLE Food( 
	shop_name varchar(120), 
	food_name varchar(150), 
	size varchar(25) check (size IN ("large","medium","small")), 
	price smallint
);
```

### Tables with Foreign Keys

```
CREATE TABLE users(
    id int,
    name varchar(50),
    PRIMARY KEY(id)
);

CREATE TABLE transaction(
    id int,
    amount int,
    FOREIGN KEY (id) REFERENCES users(id)
);
```

```
CREATE TABLE city(
    city_id int,
    city_name varchar(50),
    PRIMARY KEY(city_id)
);

CREATE TABLE subjects(
    subject_id int,
    subject_name varchar(50),
    PRIMARY KEY(subject_id)
);

CREATE TABLE undergraduate(
    student_id int,
    student_name varchar(50),
    age int,
    subject int,
    city int,
    PRIMARY KEY(student_id),
    FOREIGN KEY(city) REFERENCES city(city_id), 
    FOREIGN KEY(subject) REFERENCES subjects(subject_id)
);
```


## Inserting Data
```
INSERT INTO students(id, student_name, gender, dept_name, admission_date, fees, waiver, gpa, advisor_name)
VALUES  (22101128, "Sharif Md. Yousuf", "Male", "CSE", '2022-04-04', 85000.00, 50, 3.83, "Shahid"),
        (22101126, "Mostafezur Rahman", "Male", "CSE", '2022-03-03', 85000.00, 25, 3.35, "Shahid"),
        (22101124, "Bokhtear Md. Abid", "Male", "CSE", '2022-03-03', 85000.00, 25, 3.36, "Shahid"),
        (22101123, "Ahsan Habib", "Male", "CSE", '2022-03-03', 85000.00, 25, 3.37, "Shahid"),
        (22101132, "Faisal Hossain", "Male", "CSE", '2022-04-04', 85000.00, 50, 3.50, "Shahid"),
        (22101133, "Mazharul Islam", "Male", "CSE", '2022-04-04', 85000.00, 50, 3.51, "Shahid"), 
        (22101134, "Noor Mohammed Priom", "Male", "CSE", '2022-05-05', 85000.00, 50, 3.52, "Shahid"),
        (22101112, "Md Tausif Uddin", "Male", "CSE", '2022-05-05', 85000.00, 50, 3.53, "Shahid"),
        (22101104, "Raier Rahman Ove", "Male", "CSE", '2022-05-05', 85000.00, 75, 3.80, "Shahid"),
        (22101103, "Mukit Hasan", "Male", "CSE", '2022-04-04', 85000.00, 75, 3.81, "Shahid"),
        (22101105, "Nafiun Yesin Bijoy", "Male", "CSE", '2022-04-04', 85000.00, 75, 3.82, "Shahid"),
        (22101106, "Sadman Sakib", "Male", "CSE", '2022-04-04', 85000.00, 75, 3.84, "Shahid"),
        (22101150, "Rafiullah Al Naim", "Male", "CSE", '2022-03-03', 85000.00, 50, 3.70, "Shahid"),
        (22101111, "Mahmuda Afrin", "Female", "CSE", '2022-03-03', 85000.00, 50, 3.73, "Shahid"),
        (22101138, "Shanjida Islam", "Female", "CSE", '2022-03-03', 85000.00, 50, 3.75, "Shahid"),
        (22101113, "Wasiu Jahan", "Female", "CSE", '2022-03-03', 85000.00, 75, 3.71, "Shahid"),
        (22101115, "Farzana Hossain", "Female", "CSE", '2022-04-04', 85000.00, 75, 3.90, "Shahid"),
        (22101118, "Kashfia Meherin", "Female", "CSE", '2022-04-04', 85000.00, 75, 3.72, "Shahid"),
        (22101122, "Mahia Akter", "Female", "CSE", '2022-05-05', 85000.00, 50, 3.86, "Shahid"),
        (22101107, "Nafisa Akter", "Female", "CSE", '2022-05-05', 85000.00, 50, 3.87, "Shahid"),
        (22101149, "Nafisha Ali", "Female", "CSE", '2022-05-05', 85000.00, 50, 3.88, "Shahid"),
        (22101131, "Nusaiba Binte Amin", "Female", "CSE", '2022-03-03', 85000.00, 50, 3.65, "Shahid"),
        (22101146, "Sarmin Akter Saba", "Female", "CSE", '2022-03-03', 85000.00, 50, 3.89, "Shahid");
```

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
INSERT INTO food(shop_name, food_name, size, price)
VALUES	("Maloncho", "pizza_mac", 'large', 700),
		("Maloncho", "pizza_mac", 'medium', 500),
		("Maloncho", "pizza_mac", 'small', 300),
		("Maloncho", "burger", 'large', 600),
		("Maloncho", "burger", 'medium', 400),
		("Maloncho", "burger", 'small', 200),

		("Hut", "pizza_mac", 'large', 750),
		("Hut", "pizza_mac", 'medium', 550),
		("Hut", "pizza_mac", 'small', 350),
		("Hut", "burger", 'large', 650),
		("Hut", "burger", 'medium', 450),
		("Hut", "burger", 'small', 250);
```

#### Foreign key table data
```
INSERT INTO users(id, name)
VALUES  (1, "Person 1"),
        (2, "Person 2"),
        (3, "Person 3");
        
INSERT INTO transaction(id, amount)
VALUES  (1, 100),
        (2, 200),
        (3, 700),
        (1, 100),
        (2, 200),
        (3, 700),
        (1, 100),
        (2, 200),
        (3, 700);
```

```
INSERT INTO city (city_id, city_name)
VALUES	(1, "Dhaka"),
        (2, "Chittagong"),
        (3, "Mymensingh"),
        (4, "Comilla"),
        (5, "Rangpur"),
        (6, "Barishal"),
        (7, "Noakhali"),
        (8, "Chorakandi");

INSERT INTO subjects (subject_id, subject_name)
VALUES	(101, "Artificial Intelligence"),
        (102, "Game Development"),
        (103, "Software Engineering"),
        (104, "Cybersecurity"),
        (105, "Systems Design"),
        (106, "Operating System"),
        (107, "Advance Algorithms"),
        (108, "Computer Network"),
        (109, "Computation Theory"),
        (420, "Curibidda");

INSERT INTO undergraduate (student_id, student_name, age, subject, city)
VALUES	(1101, "Sharif Md. Yousuf", 21, 101, 4),
        (1102, "Mazharul Islam Sourav", 22, 102, 1),
        (1103, "Faisal Hossain", 20, 103, 6),
        (1104, "Noor Mohammed Priom", 21, 102, 4),
        (1105, "Nusaiba Binte Amin", 22, 104, 1),
        (1106, "Shanjida Islam", 20, 105, 4),
        (1107, "Sarmin Akter Saba", 23, 109, 2),
        (1108, "Shornali Akter", 24, 108, 3),
        (1109, "Nafisa Ali", 19, 107, 3),
        (1110, "Sadman Sakib", 24, 106,5),
        (1111, "Md. Mukit Hasan", 22, 105, 5),
        (1112, "Md. Raier Rahman Ove", 25, 104, 7),
        (1113, "Md. Mahfujur Rahman Shuvo", 25, 104, 7), 
        (1114, "Surovi Akter", 21, NULL, NULL),
        (1115, "Sharifa Akter", 22, NULL, NULL);

```