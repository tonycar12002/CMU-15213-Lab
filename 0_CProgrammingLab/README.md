# Lab0 CProgrammingLab

* 原始壓縮檔: cprogramminglab-handout.tar
* lab说明： cprogramminglab.pdf.
* 自行练习解答: cprogramminglab-handout-solution


## 说明（fork repo内建）
After untaring cprogramminglab-handout.tar, you follow the instructions in 
`cprogramming.pdf` to untar the folder. You can run `make` directly

- To run `make test`:
1. Install python2 in your environment;
2. Change `./driver.py` in `Makefile` to `python2 ./driver.py`;
3. Run `make test`;

- To use `driver.py` directly:
1. Install python2 in your environment;
2. Run `python2 driver.py`.

The most tricky part in this lab is to pass trace case 11 and 12. You can try
commentting out the 2 lines in `queue.c` marked as "IMPORTANT", which would cause
memory leak. 
Lesson: when a function relies on the success of a series of memory allocation,
remember to free all previous allocated memory, in case any one of the memory
allocation step fails.

I read the book: *The C Programming Language* before doing this lab. The note
when reading the book is in folder `TheCProgrammingLanguage`.
