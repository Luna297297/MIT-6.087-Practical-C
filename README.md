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

### 2026/1/16: Problem 4.3 solved.
* Implemented Shell Sort using pointer arithmetic.

**Note:** I used to worry about whether setting `cur - gap >= base` would cause undefined behavior, but then I realized it won't happen. The reason is: undefined behavior only occurs when a user tries to r/w an address they aren't allowed to access. Otherwise, even if the user calculates an illegal address, the behavior won't cause a Segment Fault.
