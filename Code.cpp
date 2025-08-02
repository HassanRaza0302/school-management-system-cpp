#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <string>
#include <limits>

using namespace std;

// Simple validation functions
class ValidationUtils {
public:
    // Clear input buffer
    static void clearInputBuffer() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    // Validate roll number (6 digits)
    static bool isValidRollNumber(int roll) {
        return roll >= 100000 && roll <= 999999;
    }
    
    // Validate age (reasonable range)
    static bool isValidAge(int age) {
        return age >= 3 && age <= 25;
    }
    
    // Validate class
    static bool isValidClass(const string& _class) {
        return (_class == "1st" || _class == "2nd" || _class == "3rd" || _class == "4th" || _class == "5th");
    }
    
    // Validate section
    static bool isValidSection(char section) {
        return (section == 'A' || section == 'B' || section == 'C' || section == 'D');
    }
    
    // Validate blood group
    static bool isValidBloodGroup(const string& b_grp) {
        return (b_grp == "A+" || b_grp == "A-" || b_grp == "B+" || b_grp == "B-" || 
                b_grp == "O+" || b_grp == "O-" || b_grp == "AB+" || b_grp == "AB-");
    }
    
    // Validate phone number (11 digits)
    static bool isValidPhoneNumber(const string& phone) {
        if (phone.length() != 11) return false;
        for (char c : phone) {
            if (!isdigit(c)) return false;
        }
        return true;
    }
    
    // Validate CNIC (13 digits)
    static bool isValidCNIC(const string& cnic) {
        if (cnic.length() != 13) return false;
        for (char c : cnic) {
            if (!isdigit(c)) return false;
        }
        return true;
    }
    
    // Validate fee (positive number)
    static bool isValidFee(float fee) {
        return fee >= 0;
    }
    
    // Get validated integer input
    static int getValidIntInput(const string& prompt, bool (*validator)(int) = nullptr, int min = INT_MIN, int max = INT_MAX) {
        int input;
        do {
            cout << prompt;
            if (!(cin >> input)) {
                cout << "Invalid input! Please enter a valid number." << endl;
                clearInputBuffer();
                continue;
            }
            
            if (input < min || input > max) {
                cout << "Input out of range! Please enter a value between " << min << " and " << max << "." << endl;
                continue;
            }
            
            if (validator && !validator(input)) {
                cout << "Invalid input! Please try again." << endl;
                continue;
            }
            break;
        } while (true);
        clearInputBuffer();
        return input;
    }
    
    // Get validated float input
    static float getValidFloatInput(const string& prompt, bool (*validator)(float) = nullptr, float min = -FLT_MAX, float max = FLT_MAX) {
        float input;
        do {
            cout << prompt;
            if (!(cin >> input)) {
                cout << "Invalid input! Please enter a valid number." << endl;
                clearInputBuffer();
                continue;
            }
            
            if (input < min || input > max) {
                cout << "Input out of range! Please enter a value between " << min << " and " << max << "." << endl;
                continue;
            }
            
            if (validator && !validator(input)) {
                cout << "Invalid input! Please try again." << endl;
                continue;
            }
            break;
        } while (true);
        clearInputBuffer();
        return input;
    }
    
    // Get validated character input
    static char getValidCharInput(const string& prompt, bool (*validator)(char) = nullptr) {
        char input;
        do {
            cout << prompt;
            cin >> input;
            input = toupper(input);
            
            if (validator && !validator(input)) {
                cout << "Invalid input! Please try again." << endl;
                clearInputBuffer();
                continue;
            }
            break;
        } while (true);
        clearInputBuffer();
        return input;
    }
};

class Student {
private:
    string fname;
    string lname;
    string father_name;
    int roll;
    int age;
    string _class;
    char section;
    string b_grp;
    string phone_num;
    string cnic;
    float fee;
    
public:
    void add_students() {
        system("cls");
        
        int n;
        cout << "Enter how many student you want to enter: ";
        cin >> n;
        cout << endl << endl;
        
        for (int i = 0; i < n; i++) {
            cout << "Enter the details of student " << i + 1 << endl;
            cout << "First Name: ";
            cin >> fname;
            cout << "Last name: ";
            cin >> lname;
            cout << "Father's name (e.g first_name.last_name): ";
            cin >> father_name;
            
            // Roll number validation
            do {
                cout << "Roll number (6-digit): ";
                cin >> roll;
                if (roll < 100000 || roll > 999999) {
                    cout << "Invalid roll number! Please enter a 6-digit number." << endl;
                    continue;
                }
                break;
            } while (true);
            
            // Age validation
            do {
                cout << "Age: ";
                cin >> age;
                if (age < 3 || age > 25) {
                    cout << "Invalid age! Please enter age between 3 and 25." << endl;
                    continue;
                }
                break;
            } while (true);
            
            // Class validation
            do {
                cout << "Class: ";
                cin >> _class;
                if (_class != "1st" && _class != "2nd" && _class != "3rd" && _class != "4th" && _class != "5th") {
                    cout << "Class not found" << endl;
                    cout << "Available classes are: " << endl;
                    cout << "\t1st" << endl;
                    cout << "\t2nd" << endl;
                    cout << "\t3rd" << endl;
                    cout << "\t4th" << endl;
                    cout << "\t5th" << endl;
                    cout << "Enter again: ";
                    continue;
                }
                break;
            } while (true);
            
            // Section validation
            do {
                cout << "Section: ";
                cin >> section;
                section = toupper(section);
                if (section != 'A' && section != 'B' && section != 'C' && section != 'D') {
                    cout << "Section not found" << endl;
                    cout << "Available Sections are: " << endl;
                    cout << "\tA" << endl;
                    cout << "\tB" << endl;
                    cout << "\tC" << endl;
                    cout << "\tD" << endl;
                    cout << "Enter again: ";
                    continue;
                }
                break;
            } while (true);
            
            // Blood group validation
            do {
                cout << "Blood group: ";
                cin >> b_grp;
                if (b_grp != "A+" && b_grp != "A-" && b_grp != "B+" && b_grp != "B-" && 
                    b_grp != "O+" && b_grp != "O-" && b_grp != "AB+" && b_grp != "AB-") {
                    cout << "Invalid blood group!!" << endl;
                    cout << "Enter valid blood group: ";
                    continue;
                }
                break;
            } while (true);
            
            // Phone number validation
            do {
                cout << "Phone number: ";
                cin >> phone_num;
                if (phone_num.length() != 11) {
                    cout << "Invalid mobile number" << endl;
                    cout << "Enter a valid phone number (11-digits)" << endl;
                    continue;
                }
                bool validPhone = true;
                for (char c : phone_num) {
                    if (!isdigit(c)) {
                        validPhone = false;
                        break;
                    }
                }
                if (!validPhone) {
                    cout << "Phone number should contain only digits!" << endl;
                    continue;
                }
                break;
            } while (true);
            
            // CNIC validation
            do {
                cout << "CNIC: ";
                cin >> cnic;
                if (cnic.length() != 13) {
                    cout << "Invalid CNIC" << endl;
                    cout << "Enter a valid CNIC (13-digits, without dashes)" << endl;
                    continue;
                }
                bool validCNIC = true;
                for (char c : cnic) {
                    if (!isdigit(c)) {
                        validCNIC = false;
                        break;
                    }
                }
                if (!validCNIC) {
                    cout << "CNIC should contain only digits!" << endl;
                    continue;
                }
                break;
            } while (true);
            
            cout << "Fee: ";
            cin >> fee;
            
            // Save to appropriate file based on class
            if (_class == "1st") {
                fstream file("class1.txt", ios::out | ios::app);
                if (file.is_open()) {
                    file << fname << endl;
                    file << lname << endl;
                    file << father_name << endl;
                    file << roll << endl;
                    file << age << endl;
                    file << _class << endl;
                    file << section << endl;
                    file << b_grp << endl;
                    file << phone_num << endl;
                    file << cnic << endl;
                    file << fee << endl << endl;
                    file.close();
                    cout << endl << endl;
                    cout << "Student record saved successfully!" << endl << endl;
                } else {
                    cout << "Unable to open file!" << endl;
                }
            } else if (_class == "2nd") {
                fstream file("class2.txt", ios::out | ios::app);
                if (file.is_open()) {
                    file << fname << endl;
                    file << lname << endl;
                    file << father_name << endl;
                    file << roll << endl;
                    file << age << endl;
                    file << _class << endl;
                    file << section << endl;
                    file << b_grp << endl;
                    file << phone_num << endl;
                    file << cnic << endl;
                    file << fee << endl << endl;
                    file.close();
                    cout << endl << endl;
                    cout << "Student record saved successfully!" << endl << endl;
                } else {
                    cout << "Unable to open file!" << endl;
                }
            } else if (_class == "3rd") {
                fstream file("class3.txt", ios::out | ios::app);
                if (file.is_open()) {
                    file << fname << endl;
                    file << lname << endl;
                    file << father_name << endl;
                    file << roll << endl;
                    file << age << endl;
                    file << _class << endl;
                    file << section << endl;
                    file << b_grp << endl;
                    file << phone_num << endl;
                    file << cnic << endl;
                    file << fee << endl << endl;
                    file.close();
                    cout << endl << endl;
                    cout << "Student record saved successfully!" << endl << endl;
                } else {
                    cout << "Unable to open file!" << endl;
                }
            } else if (_class == "4th") {
                fstream file("class4.txt", ios::out | ios::app);
                if (file.is_open()) {
                    file << fname << endl;
                    file << lname << endl;
                    file << father_name << endl;
                    file << roll << endl;
                    file << age << endl;
                    file << _class << endl;
                    file << section << endl;
                    file << b_grp << endl;
                    file << phone_num << endl;
                    file << cnic << endl;
                    file << fee << endl << endl;
                    file.close();
                    cout << endl << endl;
                    cout << "Student record saved successfully!" << endl << endl;
                } else {
                    cout << "Unable to open file!" << endl;
                }
            } else if (_class == "5th") {
                fstream file("class5.txt", ios::out | ios::app);
                if (file.is_open()) {
                    file << fname << endl;
                    file << lname << endl;
                    file << father_name << endl;
                    file << roll << endl;
                    file << age << endl;
                    file << _class << endl;
                    file << section << endl;
                    file << b_grp << endl;
                    file << phone_num << endl;
                    file << cnic << endl;
                    file << fee << endl << endl;
                    file.close();
                    cout << endl << endl;
                    cout << "Student record saved successfully!" << endl << endl;
                } else {
                    cout << "Unable to open file!" << endl;
                }
            }
        }
    }
};

class Faculty {
private:
    string fname;
    string lname;
    string phone_num;
    int age;
    int id;
    string designation;
    float salary;
    
public:
    void add_faculty_member() {
        system("cls");
        
        int n;
        cout << "Enter how many faculty members you want to enter: ";
        cin >> n;
        cout << endl << endl;
        
        for (int i = 0; i < n; i++) {
            cout << "Enter the details of faculty member " << i + 1 << endl;
            cout << "First Name: ";
            cin >> fname;
            cout << "Last name: ";
            cin >> lname;
            
            // Phone number validation
            do {
                cout << "Phone number: ";
                cin >> phone_num;
                if (phone_num.length() != 11) {
                    cout << "Invalid mobile number" << endl;
                    cout << "Enter a valid phone number (11-digits)" << endl;
                    continue;
                }
                bool validPhone = true;
                for (char c : phone_num) {
                    if (!isdigit(c)) {
                        validPhone = false;
                        break;
                    }
                }
                if (!validPhone) {
                    cout << "Phone number should contain only digits!" << endl;
                    continue;
                }
                break;
            } while (true);
            
            // Age validation
            do {
                cout << "Age: ";
                cin >> age;
                if (age < 22 || age > 65) {
                    cout << "Invalid age! Please enter age between 22 and 65." << endl;
                    continue;
                }
                break;
            } while (true);
            
            // ID validation
            do {
                cout << "Faculty ID (5-digit): ";
                cin >> id;
                if (id < 10000 || id > 99999) {
                    cout << "Invalid faculty ID! Please enter a 5-digit number." << endl;
                    continue;
                }
                break;
            } while (true);
            
            cout << "Designation: ";
            cin >> designation;
            
            // Salary validation
            do {
                cout << "Salary: ";
                cin >> salary;
                if (salary < 0) {
                    cout << "Invalid salary! Please enter a positive number." << endl;
                    continue;
                }
                break;
            } while (true);
            
            // Save to faculty file
            fstream file("faculty.txt", ios::out | ios::app);
            if (file.is_open()) {
                file << fname << endl;
                file << lname << endl;
                file << phone_num << endl;
                file << age << endl;
                file << id << endl;
                file << designation << endl;
                file << salary << endl << endl;
                file.close();
                cout << endl << endl;
                cout << "Faculty record saved successfully!" << endl << endl;
            } else {
                cout << "Unable to open file!" << endl;
            }
        }
    }
};

class Admin {
private:
    Student student;
    Faculty faculty;
    
    // Simple authentication helper functions
    bool authenticateUser(const string& username, const string& password, const string& userType) {
        string filename;
        if (userType == "student") {
            filename = "students password.txt";
        } else if (userType == "faculty") {
            filename = "faculty password.txt";
        } else if (userType == "admin") {
            filename = "admin password.txt";
        } else {
            return false;
        }
        
        fstream file(filename, ios::in);
        if (!file.is_open()) {
            return false;
        }
        
        string storedUsername, storedPassword;
        while (file >> storedUsername >> storedPassword) {
            if (storedUsername == username && storedPassword == password) {
                file.close();
                return true;
            }
        }
        
        file.close();
        return false;
    }
    
    void saveUserCredentials(const string& username, const string& password, const string& userType) {
        string filename;
        if (userType == "student") {
            filename = "students password.txt";
        } else if (userType == "faculty") {
            filename = "faculty password.txt";
        } else if (userType == "admin") {
            filename = "admin password.txt";
        } else {
            cout << "Error: Invalid user type!" << endl;
            return;
        }
        
        fstream file(filename, ios::out | ios::app);
        if (!file.is_open()) {
            cout << "Error: Unable to save credentials!" << endl;
            return;
        }
        
        file << username << " " << password << endl;
        file.close();
        cout << "Registration successful!" << endl;
    }
    
    bool isUsernameTaken(const string& username, const string& userType) {
        string filename;
        if (userType == "student") {
            filename = "students password.txt";
        } else if (userType == "faculty") {
            filename = "faculty password.txt";
        } else if (userType == "admin") {
            filename = "admin password.txt";
        } else {
            return false;
        }
        
        fstream file(filename, ios::in);
        if (!file.is_open()) {
            return false;
        }
        
        string storedUsername, storedPassword;
        while (file >> storedUsername >> storedPassword) {
            if (storedUsername == username) {
                file.close();
                return true;
            }
        }
        
        file.close();
        return false;
    }
    
public:
    // Student signup
    void s_signup() {
        system("cls");
        cout << "\n=== STUDENT SIGNUP ===" << endl;
        
        string username, password, confirmPassword;
        cout << "Enter username: ";
        cin >> username;
        
        if (isUsernameTaken(username, "student")) {
            cout << "Username already taken! Please choose another." << endl;
            return;
        }
        
        cout << "Enter password: ";
        cin >> password;
        cout << "Confirm password: ";
        cin >> confirmPassword;
        
        if (password != confirmPassword) {
            cout << "Passwords do not match!" << endl;
            return;
        }
        
        saveUserCredentials(username, password, "student");
    }
    
    // Student login
    void s_login() {
        system("cls");
        cout << "\n=== STUDENT LOGIN ===" << endl;
        
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        
        if (authenticateUser(username, password, "student")) {
            cout << "Login successful!" << endl;
            studentMenu();
        } else {
            cout << "Invalid username or password!" << endl;
        }
    }
    
    // Faculty signup
    void f_signup() {
        system("cls");
        cout << "\n=== FACULTY SIGNUP ===" << endl;
        
        string username, password, confirmPassword;
        cout << "Enter username: ";
        cin >> username;
        
        if (isUsernameTaken(username, "faculty")) {
            cout << "Username already taken! Please choose another." << endl;
            return;
        }
        
        cout << "Enter password: ";
        cin >> password;
        cout << "Confirm password: ";
        cin >> confirmPassword;
        
        if (password != confirmPassword) {
            cout << "Passwords do not match!" << endl;
            return;
        }
        
        saveUserCredentials(username, password, "faculty");
    }
    
    // Faculty login
    void f_login() {
        system("cls");
        cout << "\n=== FACULTY LOGIN ===" << endl;
        
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        
        if (authenticateUser(username, password, "faculty")) {
            cout << "Login successful!" << endl;
            facultyMenu();
        } else {
            cout << "Invalid username or password!" << endl;
        }
    }
    
    // Admin signup
    void admin_signup() {
        system("cls");
        cout << "\n=== ADMIN SIGNUP ===" << endl;
        
        string username, password, confirmPassword;
        cout << "Enter username: ";
        cin >> username;
        
        if (isUsernameTaken(username, "admin")) {
            cout << "Username already taken! Please choose another." << endl;
            return;
        }
        
        cout << "Enter password: ";
        cin >> password;
        cout << "Confirm password: ";
        cin >> confirmPassword;
        
        if (password != confirmPassword) {
            cout << "Passwords do not match!" << endl;
            return;
        }
        
        saveUserCredentials(username, password, "admin");
    }
    
    // Admin login
    void admin_login() {
        system("cls");
        cout << "\n=== ADMIN LOGIN ===" << endl;
        
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        
        if (authenticateUser(username, password, "admin")) {
            cout << "Login successful!" << endl;
            adminMenu();
        } else {
            cout << "Invalid username or password!" << endl;
        }
    }
    
    // Student menu
    void studentMenu() {
        char choice;
        do {
            system("cls");
            cout << "\n=== STUDENT MENU ===" << endl;
            cout << "1. View Student Records" << endl;
            cout << "2. Search Student" << endl;
            cout << "3. View Attendance" << endl;
            cout << "4. View Fee Records" << endl;
            cout << "5. Logout" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            
            switch (choice) {
                case '1':
                    cout << "View Student Records - Feature coming soon!" << endl;
                    break;
                case '2':
                    cout << "Search Student - Feature coming soon!" << endl;
                    break;
                case '3':
                    cout << "View Attendance - Feature coming soon!" << endl;
                    break;
                case '4':
                    cout << "View Fee Records - Feature coming soon!" << endl;
                    break;
                case '5':
                    cout << "Logging out..." << endl;
                    return;
                default:
                    cout << "Invalid choice! Please try again." << endl;
            }
            
            cout << "\nPress any key to continue...";
            _getch();
        } while (true);
    }
    
    // Faculty menu
    void facultyMenu() {
        char choice;
        do {
            system("cls");
            cout << "\n=== FACULTY MENU ===" << endl;
            cout << "1. Add Student" << endl;
            cout << "2. View Student Records" << endl;
            cout << "3. Search Student" << endl;
            cout << "4. Mark Attendance" << endl;
            cout << "5. View Faculty Records" << endl;
            cout << "6. Logout" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            
            switch (choice) {
                case '1':
                    student.add_students();
                    break;
                case '2':
                    cout << "View Student Records - Feature coming soon!" << endl;
                    break;
                case '3':
                    cout << "Search Student - Feature coming soon!" << endl;
                    break;
                case '4':
                    cout << "Mark Attendance - Feature coming soon!" << endl;
                    break;
                case '5':
                    cout << "View Faculty Records - Feature coming soon!" << endl;
                    break;
                case '6':
                    cout << "Logging out..." << endl;
                    return;
                default:
                    cout << "Invalid choice! Please try again." << endl;
            }
            
            cout << "\nPress any key to continue...";
            _getch();
        } while (true);
    }
    
    // Admin menu
    void adminMenu() {
        char choice;
        do {
            system("cls");
            cout << "\n=== ADMIN MENU ===" << endl;
            cout << "1. Add Student" << endl;
            cout << "2. Add Faculty Member" << endl;
            cout << "3. View Student Records" << endl;
            cout << "4. View Faculty Records" << endl;
            cout << "5. Search Student" << endl;
            cout << "6. Search Faculty" << endl;
            cout << "7. Remove Student" << endl;
            cout << "8. Remove Faculty" << endl;
            cout << "9. Manage Attendance" << endl;
            cout << "10. Manage Fee Payments" << endl;
            cout << "11. Logout" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            
            switch (choice) {
                case '1':
                    student.add_students();
                    break;
                case '2':
                    faculty.add_faculty_member();
                    break;
                case '3':
                    cout << "View Student Records - Feature coming soon!" << endl;
                    break;
                case '4':
                    cout << "View Faculty Records - Feature coming soon!" << endl;
                    break;
                case '5':
                    cout << "Search Student - Feature coming soon!" << endl;
                    break;
                case '6':
                    cout << "Search Faculty - Feature coming soon!" << endl;
                    break;
                case '7':
                    cout << "Remove Student - Feature coming soon!" << endl;
                    break;
                case '8':
                    cout << "Remove Faculty - Feature coming soon!" << endl;
                    break;
                case '9':
                    cout << "Manage Attendance - Feature coming soon!" << endl;
                    break;
                case '0':
                    cout << "Manage Fee Payments - Feature coming soon!" << endl;
                    break;
                case '1':
                    cout << "Logging out..." << endl;
                    return;
                default:
                    cout << "Invalid choice! Please try again." << endl;
            }
            
            cout << "\nPress any key to continue...";
            _getch();
        } while (true);
    }
};

int main() {
    char key;
    Admin a;
    
    do {
        int choice;
        
        cout << endl;
        cout << "\t\t\t\t******************************************************" << endl;
        cout << "\t\t\t\t|                                                    |" << endl;
        cout << "\t\t\t\t|             School Management System               |" << endl;
        cout << "\t\t\t\t|                                                    |" << endl;
        cout << "\t\t\t\t******************************************************" << endl;
        
        cout << endl << endl;
        
        s:
        cout << "\t\t_____________________________________________________________________________" << endl;
        cout << "\t\t|                                                                           |" << endl;
        cout << "\t\t|    *********" << setw(45) << " ********" << "                 |" << endl;	
        cout << "\t\t|     Sign-up " << setw(45) << "  Log-in " << "                 |" << endl;
        cout << "\t\t|    *********" << setw(45) << " ********" << "                 |" << endl;
        cout << "\t\t|                                                                           |" << endl;
        cout << "\t\t|                                                                           |" << endl;
        cout << "\t\t|  1---Student sign-up" << setw(45) << "4---Student login" << "         |" << endl;
        cout << "\t\t|  2---Faculty sign-up" << setw(45) << "5---Faculty login" << "         |" << endl;
        cout << "\t\t|  3---Admin sign-up" << setw(45) << "6---Admin login" << "           |" << endl;
        cout << "\t\t|                                                                           |" << endl;
        cout << "\t\t|___________________________________________________________________________|" << endl;
        
        cout << endl << endl;
        cout << "\t\t\"ENTER YOUR CHOICE\" : ";
        cin >> choice;
        
        system("cls");
        
        switch (choice) {
            case 1:
                a.s_signup();
                break;
                
            case 2:
                a.f_signup();
                break;
                
            case 3:
                a.admin_signup();
                break;
                
            case 4:
                a.s_login();
                break;
                
            case 5:
                a.f_login();
                break;
                
            case 6:
                a.admin_login();
                break;
                
            default:
                cout << "Enter a valid choice!!" << endl;
                cout << "Please enter your choice again" << endl;
                goto s;
                break;
        }
        
        cout << endl;
        cout << "Do you want to return to main menu? (Y/N): ";
        cin >> key;
        system("cls");
    } while (key == 'Y' || key == 'y');
    
    return 0;
}
