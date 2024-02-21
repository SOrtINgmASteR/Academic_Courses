- Creating a Table  
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

- Inserting Data
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
        (22101150, "Rafiullah Al Naim", "Male", "CSE", '2022-03-03', 85000.00, 50, 3.70, "Shahid");
```

```
INSERT INTO students(id, student_name, gender, dept_name, admission_date, fees, waiver, gpa, advisor_name)
VALUES	(22101138, "Shanjida Islam", "Female", "CSE", '2022-03-03', 85000.00, 50, 3.75, "Shahid"),
        (22101111, "Mahmuda Afrin", "Female", "CSE", '2022-03-03', 85000.00, 50, 3.73, "Shahid"),
        (22101113, "Wasiu Jahan", "Female", "CSE", '2022-03-03', 85000.00, 75, 3.71, "Shahid"),
        (22101115, "Farzana Hossain", "Female", "CSE", '2022-04-04', 85000.00, 75, 3.90, "Shahid"),
        (22101118, "Kashfia Meherin", "Female", "CSE", '2022-04-04', 85000.00, 75, 3.72, "Shahid"),
        (22101122, "Mahia Akter", "Female", "CSE", '2022-05-05', 85000.00, 50, 3.86, "Shahid"),
        (22101107, "Nafisa Akter", "Female", "CSE", '2022-05-05', 85000.00, 50, 3.87, "Shahid"),
        (22101149, "Nafisha Ali", "Female", "CSE", '2022-05-05', 85000.00, 50, 3.88, "Shahid"),
        (22101146, "Sarmin Akter Saba", "Female", "CSE", '2022-03-03', 85000.00, 50, 3.89, "Shahid");
```