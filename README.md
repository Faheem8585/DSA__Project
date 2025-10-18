# College Management System — C++ (DSA Final Project)

A simple console application for managing student and teacher records. It uses a linked-list structure and a menu-driven interface with an admin login.

# Features

Admin login (username admin, password 123). 

Student management: add, search, edit, delete, and list students. 

Teacher management: add, search, and list teachers. 

Discipline suggestion based on entered percentage (Pre-Medical, Pre-Engineering, ICS, I.Com, F.A).

# Data structures

Node stores fields such as first/last name, roll number or ID, section, percentage, qualification, gender, and links (next, prev). Instances are linked to form in-memory lists. 

Student and teacher classes each maintain head/last pointers for their respective lists.

# Menu flow

Main menu → 1 Student Management or 2 Faculty Management → operation submenu (e.g., add/search/edit/delete/list). Exit returns to the previous menu.

# Windows (MinGW or MSVC)

The program uses conio.h, getch(), and system("cls"), which are available on Windows.

# Linux / macOS

conio.h and system("PAUSE") are not portable. Replace those calls or compile with stubs before building:

Replace system("cls") with system("clear") or remove clears.

Replace getch() pauses with std::cin.get().

# Usage

Run the program.

Log in with admin / 123.

Choose Student Management or Faculty Management and then an operation.

Follow the prompts to enter or search records.

# Limitations

Data lives in memory only; it is lost on exit. 

Search loops assume a matching record exists; missing records can lead to invalid access and should be guarded in future revisions. 

Windows-specific console calls reduce portability.
