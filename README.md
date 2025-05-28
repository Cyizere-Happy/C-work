# 🧾 CRUD in C
> *It all starts with file functions.*

This project demonstrates how to implement basic **CRUD (Create, Read, Update, Delete)** operations using the **C programming language**, specifically through **file handling**.

---

## 📁 Working with Files in C

C provides the `fopen()` function to open files for different purposes:

```c
FILE *file = fopen("filename", "mode");

🔧 Modes Overview
Mode	Description
"r"	Open for reading only. Returns NULL if the file does not exist.
"w"	Open for writing only. Creates the file if it doesn't exist. Erases the contents if it does.
"a"	Open for appending. Creates the file if it doesn't exist. Preserves existing content and appends new data.
"r+"	Open for both reading and writing. Returns NULL if the file doesn't exist.
"w+"	Open for both reading and writing. Creates the file if it doesn't exist. Erases content if it does.
"a+"	Open for both reading and appending. Creates the file if it doesn't exist. Appends new data to the end of the file.

⚠️ fopen() returns a NULL pointer if the file cannot be opened.

📦 Binary Modes
For handling binary data, simply add a b to the mode string:

Text Mode	Binary Mode	Description
"r"	"rb"	Read only (binary)
"w"	"wb"	Write only (binary, erases file)
"a"	"ab"	Append only (binary)
"r+"	"rb+"	Read and write (binary)
"w+"	"wb+"	Read and write (binary, erases file)
"a+"	"ab+"	Read and append (binary)

🛠 File Pointer Basics
Before using file operations, you must declare and initialize a file pointer:

c
Copy code
#include <stdio.h>

FILE *file = NULL;
✅ The FILE structure is defined in the stdio.h header.

# 🚀 C Programming Projects by Happy

Welcome to my collection of **low-level, high-impact C programming projects**.  
From classic **sorting algorithms** to a dynamic **song playlist manager** built with **linked lists**, this repo is a playground of core CS fundamentals and practical data structures — all written in pure C.

---

## 📁 Project Structure

### 🔹 `SortingAlgorithms/`
A curated set of **classic sorting algorithms** implemented from scratch, perfect for interviews or education.

- ✅ Bubble Sort
- ✅ Selection Sort
- ✅ Insertion Sort
- ✅ Merge Sort
- ✅ Quick Sort

Each file is standalone and documented for easy understanding.

---

### 🔹 `LinkedLists/`
This is where the magic happens.

#### 🎧 `SongPlaylistManager.c`
A **fully functional, menu-driven playlist app** written in C using **singly linked lists**.

Features:
- Add songs to front, middle, or end  
- Delete songs  
- List all songs  
- Uses dynamic memory allocation  
- Clean and scalable structure  

> ✨ This is the highlight of the repo — showing off real-world linked list usage in a fun way.

---

## 🧰 Tech Stack

- 🧠 Language: C (ISO/ANSI standard)
- 🏁 Platform: Works on Windows, Linux, macOS

---

## 🛠️ How to Run Any File

```bash
# Compile
gcc filename.c -o program

# Run
./program
