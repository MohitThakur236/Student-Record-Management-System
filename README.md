Student Record Management System

A C++ console-based Student Record Management System that allows users to manage student records with persistent file storage.

Features:-

* Add a new student
* Display all student records
* Search for a student using Roll Number
* Update student details
* Delete a student record
* Prevent duplicate Roll Numbers
* Validate Roll Number, Semester, and CGPA
* Store student records permanently in a text file
* Automatically load existing records when the program starts

Student Information:-

Each student record contains:-

* Name
* Roll Number
* Branch
* Semester
* CGPA

Technologies Used:-

* C++
* Object-Oriented Programming
* File Handling
* STL Vector
* String Handling
* StringStream

How It Works:-

When the program starts, existing student records are loaded from data.txt into a vector<Student>.
When a student is added, updated, or deleted, the current records in the vector are written back to data.txt.
This allows the student data to remain available even after the program is closed.

Data Storage:-

Student records are stored in data.txt using the | delimiter.

Example:-

Rahul|101|CSE|3|8.5

The fields are stored in the following order:

Name | Roll Number | Branch | Semester | CGPA

Input Validation:-

The program validates user input to maintain valid student records.

* Roll Number must be positive
* Roll Number must be unique
* Semester must be between 1 and 8
* CGPA must be between 0 and 10
* Invalid numeric input is handled using input validation functions

CRUD Operations:-

The system supports the four basic CRUD operations:

* Create - Add a new student
* Read - Display and search student records
* Update - Modify existing student details
* Delete - Remove a student record

## Project Structure

```text
Student-Record-Management-System/
│
├── StudentManagement.cpp
├── data.txt
├── .gitignore
└── README.md
```

StudentManagement.cpp

Contains the complete C++ implementation of the Student Record Management System.

data.txt

Stores student records permanently using a delimiter-separated format.

.gitignore

Prevents compiled files and other unnecessary files from being tracked by Git.

README.md

Contains information about the project, its features, structure, and usage.

How to Run

1. Clone the Repository

git clone https://github.com/MohitThakur236/Student-Record-Management-System.git

2. Open the Project Directory

cd Student-Record-Management-System

3. Compile the Program

g++ StudentManagement.cpp -o StudentManagement

4. Run the Program

./StudentManagement

Concepts Practiced:-

* Classes and Objects
* Functions
* Vectors
* Loops and Conditional Statements
* File Input/Output
* String Handling
* StringStream
* Input Validation
* Searching
* Updating and Deleting Records
* CRUD Operations
* Git and GitHub

Future Scope

* Add sorting of student records
* Add filtering by branch or semester
* Add a graphical user interface
* Replace text-file storage with a database
* Add authentication and user roles
