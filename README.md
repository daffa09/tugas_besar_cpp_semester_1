<!-- portfolio -->
<!-- slug: tugas-besar-cpp-semester-1 -->
<!-- title: Tugas Besar C++ Semester 1 -->
<!-- description: Final semester project in C++ featuring CRUD operations for item management system -->
<!-- image: https://github.com/user-attachments/assets/8b23c442-350f-4cf2-abef-1f206bd64c6d -->
<!-- tags: c++, crud, console-app, semester-project, item-management -->

# C++ Semester 1 Final Project (Tugas Besar)

<img width="1536" height="1024" alt="tugas-besar-cpp-semester-1" src="https://github.com/user-attachments/assets/8b23c442-350f-4cf2-abef-1f206bd64c6d" />

A comprehensive item management system built with C++ as a first-semester final project. This console-based application demonstrates CRUD operations, user authentication, and transaction management.

## 📋 Overview

This final project (Tugas Besar) for Semester 1 showcases a complete item management system built entirely with C++. The application features full CRUD functionality for managing inventory items, a login system, and transaction processing - all implemented as a console application.

## ✨ Features

- **Authentication System**
  - Secure login functionality
  - User session management
  - Access control

- **Complete CRUD Operations**
  - **Create**: Add new items to inventory
  - **Read**: View all items and details
  - **Update**: Modify existing item information
  - **Delete**: Remove items from system

- **Transaction Management**
  - Process item transactions
  - Track incoming/outgoing items
  - Transaction history

- **Data Persistence**
  - File-based storage
  - Save and load data between sessions
  - Data integrity maintenance

## 🛠️ Technologies Used

- **C++**: Core programming language
- **Standard Library**: STL containers and file I/O
- **File Handling**: Data persistence
- **OOP Principles**: Classes and objects

## 📁 Project Structure

```
tugas_besar_cpp_semester_1/
├── hasil_akhir.cpp        # Main application file
├── CRUD_barang.cpp        # CRUD implementation
├── login.cpp              # Login system
├── transaksi.cpp          # Transaction management
├── pseudocode.coffee      # Algorithm pseudocode
├── .gitignore
└── README.md
```

## 🚀 Getting Started

### Prerequisites

- C++ compiler (GCC, Clang, or MSVC)
- C++11 or higher standard support
- Command line interface

### Compilation

**Using GCC:**
```bash
g++ -o item_management hasil_akhir.cpp -std=c++11
```

**Using Clang:**
```bash
clang++ -o item_management hasil_akhir.cpp -std=c++11
```

**Using Visual Studio:**
1. Open project in Visual Studio
2. Build → Build Solution
3. Run executable from Debug/Release folder

### Running the Application

**Linux/macOS:**
```bash
./item_management
```

**Windows:**
```bash
item_management.exe
```

Or double-click the executable file.

## 💻 Usage Guide

### Login

1. Launch the application
2. Enter credentials:
   - Username
   - Password
3. Access main menu after successful authentication

### Main Menu Options

1. **View Items** - Display all inventory items
2. **Add Item** - Create new item entry
3. **Update Item** - Modify existing item
4. **Delete Item** - Remove item from inventory
5. **Process Transaction** - Handle item transactions
6. **Exit** - Save and close application

### Managing Items

#### Adding New Item
1. Select "Add Item" from menu
2. Enter item details:
   - Item code/ID
   - Item name
   - Category
   - Quantity
   - Price
   - Description
3. Confirm to save

#### Viewing Items
1. Select "View Items"
2. See formatted list of all items
3. Option to view detailed information

#### Updating Item
1. Select "Update Item"
2. Enter item code to update
3. Modify desired fields
4. Confirm changes

#### Deleting Item
1. Select "Delete Item"
2. Enter item code
3. Confirm deletion
4. Item removed from system

### Processing Transactions

1. Select "Process Transaction"
2. Choose transaction type:
   - Stock In (adding items)
   - Stock Out (removing items)
3. Enter item code and quantity
4. Transaction logged and inventory updated

## 🗂️ Data Structure

### Item Class

```cpp
class Item {
private:
    string code;
    string name;
    string category;
    int quantity;
    double price;
    string description;
    
public:
    // Constructor
    Item(string c, string n, string cat, int qty, double p, string desc);
    
    // Getters and Setters
    string getCode();
    void setQuantity(int qty);
    // ... other methods
};
```

### Transaction Record

```cpp
struct Transaction {
    string itemCode;
    string type; // "IN" or "OUT"
    int quantity;
    string date;
    string time;
};
```

## 📊 File Storage

Data is stored in text files:
- `items.txt` - Item inventory data
- `transactions.txt` - Transaction history
- `users.txt` - User credentials (if applicable)

File format example:
```
001|Item Name|Category|100|25.50|Description
002|Another Item|Category B|50|15.75|Description
```

## 🎓 Learning Objectives

This project demonstrates:
- **C++ Fundamentals**: Variables, loops, conditionals
- **OOP  Concepts**: Classes, encapsulation, inheritance
- **File I/O**: Reading from and writing to files
- **Data Structures**: Vectors, arrays, structs
- **Error Handling**: Input validation and exception handling
- **Modular Programming**: Function organization
- **CRUD Operations**: Complete data management
- **User Authentication**: Basic security implementation

## 🎯 Project Components

### Main Application (`hasil_akhir.cpp`)
- Program entry point
- Main menu loop
- Module integration
- User interface

### CRUD Module (`CRUD_barang.cpp`)
- Create item function
- Read/display items
- Update item details
- Delete item records

### Login System (`login.cpp`)
- User authentication
- Password verification
- Session management
- Access control

### Transaction Module (`transaksi.cpp`)
- Stock in/out processing
- Transaction recording
- Inventory updates
- Transaction history

### Algorithm Documentation (`pseudocode.coffee`)
- Pseudocode for main algorithms
- Logic flow documentation
- Implementation guide

## 🔧 Configuration

### Default Settings

Item fields:
- Code: Alphanumeric (max 10 chars)
- Name: String (max 50 chars)
- Category: String (max 30 chars)
- Quantity: Integer (>= 0)
- Price: Decimal (>= 0.0)

### Customization

Edit constants in main file:
```cpp
const int MAX_ITEMS = 1000;
const string DATA_FILE = "items.txt";
const string TRANS_FILE = "transactions.txt";
```

## 🐛 Troubleshooting

**Login Failed**
- Check credentials
- Verify users.txt file exists
- Check file permissions

**Data Not Saving**
- Ensure write permissions
- Check disk space
- Verify file paths

**Compilation Errors**
- Use C++11 or higher
- Check all source files included
- Verify #include statements

**Program Crashes**
- Validate user inputs
- Check array bounds
- Handle null/empty cases

## 🚀 Future Enhancements

Potential improvements:
- Database integration (SQLite)
- GUI implementation (Qt, wxWidgets)
- Advanced search and filter
- Export to CSV/Excel
- Multi-user support
- Report generation
- Barcode integration
- Cloud synchronization

## 📝 Assignment Requirements

This project fulfills semester requirements:
- ✅ Console-based application
- ✅ CRUD operations
- ✅ File handling
- ✅ User authentication
- ✅ Data validation
- ✅ Error handling
- ✅ Code documentation
- ✅ Pseudocode included

## 🎓 Academic Context

**Course**: Introduction to Programming / C++ Programming  
**Semester**: 1  
**Type**: Final Project (Tugas Besar)  
**Language**: C++  
**Paradigm**: Procedural & Object-Oriented

## 🤝 Contributing

This is an academic project. For learning purposes, feel free to:
- Study the implementation
- Suggest improvements
- Fork for your own learning
- Share feedback

## 📄 License

Created for educational purposes as a semester final project.

## 💭 Reflection

This first semester final project was an amazing learning experience that taught me:
- How to structure a complete application
- The importance of modular code organization
- File handling and data persistence
- User authentication basics
- CRUD operation implementation
- Problem-solving and debugging skills

It laid the foundation for my programming journey!

---

**First Semester Final Project** 🎓💻  
Complete item management system showcasing C++ fundamentals!
