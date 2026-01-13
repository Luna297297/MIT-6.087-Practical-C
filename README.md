# MIT 6.087: Practical Programming in C

During the winter holiday of my first year of graduate school (Jan–Feb 2026),  
I used this repo to record my MIT 6.087 journey \(^v^)/

---

## Environment  
gcc / gdb / valgrind / git / Linux (Docker, AArch64)

---

## Progress

### 2026/1/12: Problem 4.1 solved.  
Tried implementing insertion sort using pointers only.  
My first time using GCC, GDB, and Valgrind.  
Checked with Valgrind — no memory errors.

**Note:** I used `malloc()` in this problem simply to get familiar with the syntax,  
but it is not actually necessary for this task.

### 2026/1/13: Problem 4.2 solved.
Tried implementing `strtok()` using pointers only.
My first time using `static char *`. 

**Note:** `static char *` was stored in the Static/Global Storage.
The difference between `signed int` and `unsigned int`.