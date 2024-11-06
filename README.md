# Bank-System
# Overview of a C++ Bank System Using OOP
## 1. System Login and Security
Login Feature: The system includes a secure login mechanism that allows a maximum of 3 attempts. After the third failed attempt, the system is locked to prevent unauthorized access.
User Registration Details: When a user registers, their username and the time of registration are recorded in the system for tracking and auditing purposes.
Permissions System: A bitwise permission system ensures security and control access for different operations, allowing role-based access to features.
## 2. Menus and Functionalities
### a. Main Menu
The main menu provides access to all the key features of the system, including:

Client Management: CRUD (Create, Read, Update, Delete) operations for managing client information.
User Management: A menu for managing users of the system, also supporting CRUD operations.
Transaction Menu: Includes options for:
Withdraw: Deduct a specified amount from the user’s balance.
Deposit: Add a specified amount to the user’s balance.
Check Balance: Display the current balance of the user.
Transfer Menu: Supports money transfers from one user to another, ensuring that adequate permissions and balance checks are in place.
System Activity Log: Records and displays the time when each user logs in and logs out, providing an audit trail for administrators.
### b. Client Management
View All Clients: Display the list of all registered clients along with their details.
Add New Client: Create a new client profile, including name, contact information, and initial balance.
Update Client Information: Modify details of existing clients.
Delete Client Profile: Remove a client from the system.
### c. User Management
User CRUD Operations:
Add User: Register a new user to access the system.
View Users: List all users and their roles.
Update User Details: Change the information associated with a user.
Delete User: Remove a user from the system.
User Login Log: A menu option to review when each user has entered and exited the system.
### d. Transaction Operations
Withdraw: Deduct funds from the user’s account after validation checks.
Deposit: Increase the user's balance by adding funds.
Check Total Balance: Display the current balance for an account.
Transfer Money: Transfer funds securely between accounts with built-in checks for sufficient balance and permissions.
## 3. Security and Permissions
Bitwise Permissions: The system leverages bitwise operations to apply and verify permissions across all features. This ensures that each user only has access to the parts of the system relevant to their role (e.g., administrators vs. regular users).
System Protection: The permission system helps protect the bank’s data by preventing unauthorized users from accessing or modifying sensitive information.
## 4. Additional Details
Error Handling: Robust error handling is included to deal with issues like insufficient funds, invalid input, and permission violations.
Time Tracking: Each user’s entry into the system is recorded with timestamps, ensuring transparency in usage patterns.
## OOP Principles Applied:
Encapsulation: User and client data are managed through private member variables, and accessed via public methods.
Inheritance: Different types of users (e.g., admins and standard users) can inherit properties from a base User class.
Polymorphism: Methods like _AddNew() and _RegisterTransferLog() can be overridden for different classes as needed.
Abstraction: Complex operations like transfer and withdrawal are implemented in a user-friendly manner to hide the underlying logic from the end-user.
