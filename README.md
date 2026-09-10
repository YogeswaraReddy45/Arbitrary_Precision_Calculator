# Big Integer Calculator in C

## 📌 Description

This project is a **Big Integer Calculator implemented in C** using a **Doubly Linked List**.

Since normal integer data types in C have a limited range, this project stores each digit of a large number in a doubly linked list and performs arithmetic operations digit by digit.

The calculator supports:

* Addition
* Subtraction
* Multiplication
* Division
* Positive and negative numbers
* Large integers

Each digit of the input number is stored in a node of a doubly linked list. Each node contains `data`, `prev`, and `next` pointers.

---

## 🚀 Features

* Handles large integers beyond the normal integer range
* Uses a Doubly Linked List for storing digits
* Supports positive and negative operands
* Supports `+`, `-`, `x`, `X`, and `/` operators
* Performs each arithmetic operation using a separate function
* Validates input digits
* Handles division by zero
* Uses dynamic memory allocation
* Uses modular programming with multiple source files
* Uses a Makefile for efficient compilation
* Avoids unnecessary recompilation of unchanged source files

---

## 🛠️ Technologies Used

* **Language:** C
* **Data Structure:** Doubly Linked List
* **Compiler:** GCC
* **Build Tool:** Makefile
* **Libraries:** `stdio.h`, `stdlib.h`, `ctype.h`

---

## 📂 Project Structure

```text
Big-Integer-Calculator/
│
├── main.c
├── fun.h
├── create_list.c
├── insert.c
├── add.c
├── sub.c
├── mul.c
├── div.c
├── compare.c
├── makefile
│
├── main.o
├── create_list.o
├── insert.o
├── add.o
├── sub.o
├── mul.o
├── div.o
├── compare.o
│
└── Slist.exe
```

### Source Files

| File            | Description                                        |
| --------------- | -------------------------------------------------- |
| `main.c`        | Main driver program                                |
| `fun.h`         | Structure, macros, and function declarations       |
| `create_list.c` | Creates linked lists from input numbers            |
| `insert.c`      | Inserts nodes at beginning and end                 |
| `add.c`         | Performs addition                                  |
| `sub.c`         | Performs subtraction                               |
| `mul.c`         | Performs multiplication using a single result list |
| `div.c`         | Performs division                                  |
| `compare.c`     | Compares two linked lists                          |
| `makefile`      | Automates and manages compilation                  |

---

## 🧩 File Description

### `main.c`

The main driver program.

It:

* Reads operands and the operator through command-line arguments
* Creates linked lists for both operands
* Determines the sign of the result
* Calls the appropriate arithmetic function
* Prints the final result

The program takes the operands and operator through command-line arguments.

```text
operand1 operator operand2
```

---

### `fun.h`

Contains:

* Doubly linked list structure definition
* Return status macros
* Function declarations

```c
typedef struct list
{
    int data;
    struct list *prev;
    struct list *next;
} list;
```

Status values used in the project:

```c
#define SUCCESS 0
#define FAILURE -1
#define NOT_A_VALID_DIGIT -2
#define LIST_IS_EMPTY -3
```

The header file contains declarations for list creation, insertion, comparison, arithmetic operations, printing, and deletion.

---

### `create_list.c`

Converts the input number into a doubly linked list.

The function:

1. Checks for `+` or `-` sign.
2. Reads each character of the number.
3. Validates whether the character is a digit.
4. Converts the character into an integer digit.
5. Inserts the digit into the linked list.

If an invalid character is found, `NOT_A_VALID_DIGIT` is returned.

---

### `insert.c`

Contains two functions:

* `insert_first()`
* `insert_last()`

These functions dynamically allocate a node and insert it at the beginning or end of the doubly linked list.

```text
insert_first()
      ↓
Insert node at beginning

insert_last()
      ↓
Insert node at end
```

---

### `compare.c`

Compares two linked lists representing large numbers.

The function traverses the lists and compares their corresponding digits to determine which number is greater.

The comparison operation is used by subtraction and division.

---

### `add.c`

Performs addition of two large numbers.

The addition starts from the least significant digit and processes the numbers digit by digit.

It handles:

* Addition of corresponding digits
* Carry
* Different number of digits
* Creating the result list

Example:

```text
   999
 + 123
 -----
  1122
```

The result digits are inserted at the beginning of the result list.

---

### `sub.c`

Performs subtraction of large numbers.

The function processes the digits from the least significant digit and handles borrowing whenever required.

It handles:

* Digit-by-digit subtraction
* Borrow
* Numbers with different number of digits

Example:

```text
  1000
-    1
------
   999
```

---

### `mul.c`

Performs multiplication of large numbers using a **single result linked list**.

Instead of creating separate linked lists for each intermediate multiplication result, this implementation uses **one result list** and continuously updates it while processing the digits of the second operand.

The multiplication handles:

* Multiplication of individual digits
* Carry
* Position shifting
* Updating the same result list
* Processing the second operand digit by digit

A `count` variable is used to shift the multiplication position according to the current digit of the second operand.

### Multiplication Approach

For example:

```text
       123
     ×  45
     -----
       615
      4920
     ------
      5535
```

In this implementation, separate lists are **not created for `615` and `4920`**.

Instead, a **single result list** is maintained and updated as each digit of the second operand is processed.

This reduces the need for multiple intermediate result lists.

---

### `div.c`

Performs division of large numbers.

The implementation uses:

* Linked-list representation
* Comparison
* Subtraction
* Result-list manipulation

The divisor is repeatedly subtracted while comparison is used to determine when the division should stop.

The program also checks for division by zero before performing the operation.

---

# 🔨 Makefile

The project uses a **Makefile** to simplify and make the compilation process more efficient.

Since the project contains multiple source files, manually compiling every `.c` file each time can be inefficient.

Instead, the Makefile manages the compilation of the source files and their corresponding object files.

---

## ⚡ Efficient Compilation

One of the main advantages of using a Makefile is **efficient compilation**.

When the project is compiled, the source files are converted into object files:

```text
main.c          → main.o
create_list.c   → create_list.o
insert.c        → insert.o
add.c           → add.o
sub.c           → sub.o
mul.c           → mul.o
div.c           → div.o
compare.c       → compare.o
```

The object files are then linked together to create the final executable.

```text
Object Files
     ↓
   Linking
     ↓
 Slist.exe
```

If only one source file is modified, the Makefile can compile only the modified source file and then link the updated object files.

For example:

```text
add.c modified
      ↓
compile only add.c
      ↓
    add.o
      ↓
link with other .o files
      ↓
  Slist.exe
```

This avoids recompiling unchanged source files and makes the build process more efficient.

---

## ▶️ Compile Using Makefile

Run:

```bash
make
```

The Makefile handles the compilation and linking process automatically.

---

## 🧹 Clean Generated Files

To remove generated object files and the executable:

```bash
make clean
```

This allows the project to be rebuilt from scratch when required.

---

## ▶️ Manual Compilation

The project can also be compiled manually using GCC:

```bash
gcc main.c create_list.c insert.c add.c sub.c mul.c div.c compare.c -o Slist
```

However, using the Makefile is more convenient and efficient for a multi-file project.

---

# ▶️ How to Run

The calculator uses **command-line arguments**.

### Syntax

```bash
./Slist <operand1> <operator> <operand2>
```

---

# 🧪 Examples

## Addition

```bash
./Slist 123456789 + 987654321
```

Output:

```text
1111111110
```

---

## Subtraction

```bash
./Slist 1000000000 - 1
```

Output:

```text
999999999
```

---

## Multiplication

```bash
./Slist 12345 x 678
```

Output:

```text
8369910
```

---

## Division

```bash
./Slist 1000 / 25
```

Output:

```text
40
```

---

# ➕ Supported Operators

| Operator | Operation      |
| -------- | -------------- |
| `+`      | Addition       |
| `-`      | Subtraction    |
| `x`      | Multiplication |
| `X`      | Multiplication |
| `/`      | Division       |

---

# ➖ Negative Numbers

The calculator supports positive and negative operands.

### Example

```bash
./Slist -100 + 50
```

Output:

```text
-50
```

### Example

```bash
./Slist -100 - 50
```

Output:

```text
-150
```

### Example

```bash
./Slist -100 x -5
```

Output:

```text
500
```

The sign of the result is determined based on the signs of the two operands and the selected operator.

---

# ⚠️ Error Handling

## Invalid Number

```bash
./Slist 123a + 456
```

Output:

```text
operand1 is invalid
```

---

## Invalid Operator

```bash
./Slist 100 % 20
```

Output:

```text
not a valid operator
```

---

## Division by Zero

```bash
./Slist 100 / 0
```

Output:

```text
division with zero not possible
```

---

## Invalid Number of Arguments

If the required command-line arguments are not provided:

```text
provide valid arguments
```

---

# 🔗 Doubly Linked List Representation

Each digit of a number is stored in a separate node.

For example:

```text
Input: 12345

NULL
  ↓
[1] ⇄ [2] ⇄ [3] ⇄ [4] ⇄ [5]
                              ↓
                             NULL
```

Each node contains:

```text
+-------+-------+-------+
| prev  | data  | next  |
+-------+-------+-------+
```

* `prev` points to the previous node
* `data` stores the digit
* `next` points to the next node

This allows traversal in both directions.

---

# 🧠 Working Principle

The project represents a large number as a doubly linked list.

For example:

```text
Number = 987654321

[9] ⇄ [8] ⇄ [7] ⇄ [6] ⇄ [5] ⇄ [4] ⇄ [3] ⇄ [2] ⇄ [1]
```

The arithmetic operations process the digits individually instead of storing the complete number in a normal integer variable.

For addition and subtraction, processing starts from the least significant digit using the `prev` pointer.

The project uses separate functions for each arithmetic operation, making the implementation modular and easier to maintain.

---

# 🧹 Memory Management

The project uses dynamic memory allocation for creating linked-list nodes.

Memory is allocated using:

```c
malloc(sizeof(list));
```

The project also contains a `delete_list()` function to free dynamically allocated nodes.

---

# 🧩 Important Functions

```c
create_list()
insert_first()
insert_last()
compare_list()

add_operator()
sub_operator()
mul_operator()
div_operator()

print_list()
delete_list()
```

---

# 📚 Concepts Used

This project uses the following C programming and data-structure concepts:

* Structures
* Doubly Linked Lists
* Pointers
* Pointer-to-pointer concepts
* Dynamic Memory Allocation
* Command Line Arguments
* Header Files
* Function Prototypes
* Modular Programming
* Carry and Borrow
* Large Number Arithmetic
* Memory Management
* Makefile
* Object Files
* Compilation and Linking
* Switch Case
* Character Handling

---

# 🎯 Learning Outcome

Through this project, I learned how to implement arithmetic operations on **large integers** using a **Doubly Linked List** instead of relying on the limited range of built-in integer data types.

I also gained practical experience with:

* Doubly Linked List implementation
* Dynamic memory allocation
* Pointers
* Command-line arguments
* Modular programming in C
* Carry and borrow handling
* Large integer arithmetic
* Memory management
* Compilation and linking
* Makefile-based efficient compilation
* Working with object files

---

# 🚀 Future Improvements

Possible improvements for this project:

* Add modulus `%` operation
* Improve division algorithm efficiency
* Add more input validation
* Add automated test cases
* Improve memory cleanup
* Add a user-friendly menu-based interface
* Add floating-point number support

---

# 👨‍💻 Author

**Gajulapalli Yogeswara Reddy**
