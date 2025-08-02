# School Management System

A comprehensive C++ console application for managing school records including students, faculty, attendance, and fee management.

## Features

### Student Management
- Add student records with validation
- View student information
- Search students by various criteria
- Manage student attendance
- Track fee payments

### Faculty Management
- Add faculty member records
- View faculty information
- Search faculty members
- Manage faculty records

### Authentication System
- Student login/signup
- Faculty login/signup
- Admin login/signup
- Secure password management

### Data Validation
- Input validation for all fields
- Roll number validation (6-digit)
- Age validation (3-25 for students, 22-65 for faculty)
- Phone number validation (11 digits)
- CNIC validation (13 digits)
- Blood group validation
- Class and section validation

## File Structure

```
├── Code.cpp                 # Main application file
├── class1.txt              # Student records for 1st class
├── class2.txt              # Student records for 2nd class
├── class3.txt              # Student records for 3rd class
├── class4.txt              # Student records for 4th class
├── class5.txt              # Student records for 5th class
├── faculty.txt             # Faculty member records
├── students password.txt   # Student login credentials
├── faculty password.txt    # Faculty login credentials
├── admin password.txt      # Admin login credentials
├── attendence class 1.txt # Attendance records for 1st class
├── attendence class 2.txt # Attendance records for 2nd class
├── attendence class 3.txt # Attendance records for 3rd class
├── attendence class 4.txt # Attendance records for 4th class
├── attendence class 5.txt # Attendance records for 5th class
└── README.md              # This file
```

## How to Compile and Run

### Using g++ (GNU Compiler)
```bash
g++ -o SchoolManagement Code.cpp
./SchoolManagement
```

### Using Visual Studio
```bash
cl Code.cpp
Code.exe
```

### Using MinGW
```bash
g++ -o SchoolManagement.exe Code.cpp
SchoolManagement.exe
```

## Usage

1. **Compile the program** using one of the methods above
2. **Run the executable**
3. **Choose from the main menu:**
   - Student signup/login
   - Faculty signup/login
   - Admin signup/login
4. **Follow the prompts** to add or view records

## System Requirements

- C++ compiler (g++, clang++, or Visual Studio)
- Windows/Linux/macOS
- Console/terminal access

## Features in Detail

### Student Records
- First and last name
- Father's name
- Roll number (6-digit)
- Age (3-25 years)
- Class (1st, 2nd, 3rd, 4th, 5th)
- Section (A, B, C, D)
- Blood group
- Phone number (11 digits)
- CNIC (13 digits)
- Fee amount

### Faculty Records
- First and last name
- Phone number (11 digits)
- Age (22-65 years)
- Faculty ID (5-digit)
- Designation
- Salary

### Authentication
- Username/password system
- Separate credential files for each user type
- Password confirmation during signup
- Duplicate username prevention

## Data Storage

All data is stored in text files:
- Student records are saved in class-specific files (class1.txt, class2.txt, etc.)
- Faculty records are saved in faculty.txt
- Login credentials are stored in separate password files
- Attendance records are stored in class-specific attendance files

## Error Handling

The system includes comprehensive error handling:
- Input validation for all fields
- File operation error checking
- Invalid choice handling
- Graceful error recovery

## Contributing

Feel free to contribute to this project by:
- Reporting bugs
- Suggesting new features
- Improving code quality
- Adding documentation

## License

This project is open source and available under the MIT License. 

**Author:** Hassan Raza
**GitHub:** https://github.com/HassanRaza0302

Copyright (c) 2025 Hassan Raza. All rights reserved.
---
*Developed with ?? by Hassan Raza*
