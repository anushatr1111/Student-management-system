# Student Management System (C, File Handling)

## 📌 Overview
The **Student Management System** is a console-based C application that allows users to **store, retrieve, update, and delete** student records using file handling. It is designed to improve C programming skills while implementing real-world data storage techniques.

## 🚀 Features
- **Add Student**: Enter student details and save them in a CSV file.
- **View Students**: Display all stored student records.
- **Update Student**: Modify existing student details.
- **Delete Student**: Remove a student record from the file.
- **Search Student**: Find a student by ID or name.
- **File Handling**: Data is stored in a structured file for persistent storage.

## 🛠️ Technologies Used
- **Programming Language**: C
- **File Handling**: Uses `.csv` or `.txt` files for data storage
- **Compiler**: GCC (MinGW recommended for Windows)

## 📂 Project Structure
```
Student-management-app/
│-- main.c               // Main program file
│-- student_management.c // Core logic for student operations
│-- student_management.h // Header file for function declarations
│-- students.csv         // Data file storing student records
│-- README.md            // Documentation
```

## 🔧 Installation & Compilation
### **1️⃣ Clone the Repository**
```sh
git clone https://github.com/anushatr1111/Student-management-system.git
cd Student-management-app
```

### **2️⃣ Compile the Program**
```sh
gcc main.c student_management.c -o student_mgmt.exe
```

### **3️⃣ Run the Program**
```sh
./student_mgmt.exe
```

## 📜 Usage
1. Run the program.
2. Select an option from the menu:
   - **1: Add Student**
   - **2: View Students**
   - **3: Update Student**
   - **4: Delete Student**
   - **5: Search Student**
   - **0: Exit**

3. Follow the prompts to manage student records.

## 📝 Example Data Format (students.csv)
```
ID, Name, Age, Course, GPA
101, Alice Johnson, 20, Computer Science, 3.8
102, Bob Smith, 21, Mechanical Engineering, 3.5
```

## 🔗 Git Integration
### **1️⃣ Initialize Git**
```sh
git init
git add .
git commit -m "Initial commit"
git branch -M main
git remote add origin https://github.com/anushatr1111/Student-management-system.git
git push -u origin main
```

## 📌 License
This project is **open-source** and available under the **MIT License**.

## 🏆 Contributions
Feel free to fork this repository, make improvements, and submit a pull request! 🚀

