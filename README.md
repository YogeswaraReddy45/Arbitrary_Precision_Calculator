# Big Integer Calculator in C

## 📌 Description

This project is a **Big Integer Calculator implemented in C** using a **Doubly Linked List**.

Since the normal integer data types in C have a limited range, this project stores each digit of a large number in a linked list and performs arithmetic operations digit by digit.

The calculator supports:

* Addition
* Subtraction
* Multiplication
* Division
* Positive and negative numbers
* Large integers

Each digit of the input number is stored as a node in a doubly linked list. The list contains `data`, `prev`, and `next` pointers.

---

## 🚀 Features

* Handles large integers beyond the normal integer range
* Uses Doubly Linked List for storing digits
* Supports positive and negative operands
* Supports `+`, `-`, `x`, `X`, and `/` operators
* Performs arithmetic using separate functions
* Validates input digits
* Handles division by zero
* Dynamic memory allocation
* Uses a Makefile for compilation

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

---

## 🧩 File Description

### `main.c`

The main driver program.

It:

* Reads operands and operator through command-line arguments
* Creates linked lists for both operands
* Determines the sign of the result
* Calls the appropriate arithmetic function
* Prints the final result

The program expects exactly three command-line arguments in addition to the program name.

---

### `fun.h`

Contains:

* Structure definition
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

Status values used in the project include:

```c
#define SUCCESS 0
#define FAILURE -1
#define NOT_A_VALID_DIGIT -2
#define LIST_IS_EMPTY -3
```

The header also declares the functions used for list creation, insertion, comparison, arithmetic operations, printing, and deletion.

---

### `create_list.c`

Converts the input number into a doubly linked list.

The function:

1. Checks for `+` or `-` sign.
2. Reads each character.
3. Validates whether it is a digit.
4. Converts the character into an integer digit.
5. Inserts the digit into the linked list.

Invalid characters result in `NOT_A_VALID_DIGIT`.

---

### `insert.c`

Contains two functions:

* `insert_first()`
* `insert_last()`

## These functions dynamically allocate nodes and insert them at the beginning or end of the doubly linked list.

### `compare.c`

Compares two linked lists representing large numbers.

It traverses both lists and determines which operand is greater.

---

### `add.c`

Performs addition of two large numbers.

The addition starts from the least significant digit and handles the carry generated during addition.

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

The function handles:

* Digit-by-digit subtraction
* Borrow
* Different number of digits

Borrow is propagated to the next digit when required.

---

### `mul.c`

Performs multiplication of large numbers using the digits stored in the linked lists.

It handles:

* Multiplication of individual digits
* Carry
* Position shifting
* Addition of intermediate results

The implementation uses a `count` value to shift the intermediate multiplication result according to the digit position.

---

### `div.c`

Performs division of large numbers.

The implementation repeatedly works with subtraction and comparison to obtain the quotient. It also manages the quotient digits using the linked-list representation.

---

## ▶️ How to Compile

Clone the repository:

```bash
git clone <repository-url>
cd Big-Integer-Calculator
```

Compile using the Makefile:

```bash
make
```

Or compile manually:

```bash
gcc main.c create_list.c insert.c add.c sub.c mul.c div.c compare.c -o Slist
```

---

## ▶️ How to Run

The calculator uses **command-line arguments**.

### Syntax

```bash
./Slist <operand1> <operator> <operand2>
```

### Addition

```bash
./Slist 123456789 + 987654321
```

Output:

```text
1111111110
```

### Subtraction

```bash
./Slist 1000000000 - 1
```

Output:

```text
999999999
```

### Multiplication

```bash
./Slist 12345 x 678
```

Output:

```text
8369910
```

### Division

```bash
./Slist 1000 / 25
```

Output:

```text
40
```

For multiplication, the program accepts both `x` and `X`.

---

## ➕ Supported Operators

| Operator | Operation      |
| -------- | -------------- |
| `+`      | Addition       |
| `-`      | Subtraction    |
| `x`      | Multiplication |
| `X`      | Multiplication |
| `/`      | Division       |

---

## 🔢 Negative Numbers

The calculator also supports signed operands.

Examples:

```bash
./Slist -100 + 50
```

```text
-50
```

```bash
./Slist -100 - 50
```

```text
-150
```

```bash
./Slist -100 x -5
```

```text
500
```

The sign handling is performed in `main.c` before calling the arithmetic functions.

---

## ⚠️ Error Handling

The project handles different invalid inputs.

### Invalid Number

```bash
./Slist 123a + 456
```

Output:

```text
operand1 is invalid
```

### Invalid Operator

```bash
./Slist 100 % 20
```

Output:

```text
not a valid operator
```

### Division by Zero

```bash
./Slist 100 / 0
```

Output:

```text
division with zero not possible
```

## These validations are handled in `main.c` and `create_list.c`.

## 🧠 Concepts Used

This project helped in understanding and implementing:

* Structures
* Doubly Linked Lists
* Pointers
* Pointer-to-pointer concepts
* Dynamic Memory Allocation
* Command Line Arguments
* Header Files
* Modular Programming
* Function Prototypes
* Carry and Borrow
* Large Number Arithmetic
* Memory Management
* Makefile

---

## 💡 Working Principle

Each digit of a large number is stored in a separate linked-list node.

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
data
prev
next
```

This allows the program to traverse the number in both directions.

For arithmetic operations, the program generally starts from the least significant digit and processes digits while maintaining carry or borrow.

---

## 📌 Important Functions

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

These functions are declared in `fun.h` and implemented across separate source files.

---

## 🎯 Learning Outcome

Through this project, I learned how to implement arithmetic operations on numbers larger than the normal C integer limits using a **Doubly Linked List**.

I also gained practical experience with:

* Data structures
* Modular C programming
* Dynamic memory allocation
* Pointers
* Command-line arguments
* Makefile-based compilation
* Handling large integer arithmetic

---

## 👨‍💻 Author

**Gajulapalli Yogeswara Reddy**

---

## ⭐ Future Improvements

Possible improvements for this project:

* Add modulus `%` operation
* Improve division algorithm efficiency
* Add floating-point support
* Add more input validation
* Improve memory cleanup
* Add automated test cases
* Add a user-friendly menu-based interface
