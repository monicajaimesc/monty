# Stacks, Queues - Project

Stack is a linear data structure which follows a particular order in which the operations are performed.
 The order may be LIFO(Last In First Out) or FILO(First In Last Out).

## :muscle: Goal
The goal of this project is to create an interpreter for Monty ByteCodes files.

## Monty Language

Monty is a scripting language that is first compiled into Monty byte codes. It relies on a unique stack, with specific instructions to manipulate it. This structions are called opcodes.

## :page_with_curl: Opcodes
These are the opcodes that our interpreter can take and operate.


Opcode | Description
---- | ----
push| Pushes an element to the stack.
pall| Prints all the values on the stack, starting from the top of the stack.
pint| Prints the value at the top of the stack.
pop| Removes the top element of the stack.
swap| Swaps the top two elements of the stack.
add| Adds the top two elements of the stack.
nop| Doesnt do anything.

## :open_file_folder: Files
Files | Description
---- | ----
instructions.c| Functions for the opcode.
instruction_errors.c| Error messages for add, swap, pop, push.
program_error.c| Errors of the program, file and malloc.
main.c| Main of the program.
nop_function.c| nop function.
monty.h| Header file with prototypes of the functions and structures.
operations_functions.c| Function for add.
queues_functions.c| Functions for the queue.
stack.c| Function for the stack.
stack_queue.c| Stack and queue flow.




## :computer: Installation
Clone this repository on and new directoy:
``` bash
https://github.com/monicajaimesc/monty.git
```
Compile:
``` bash
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```
Execute:
``` bash
monty <file>
```
## :pushpin: Examples
``` bash
push 1$
push 2$
push 3$
pall$

OUTPUT
3
2
1
```

## Authors
Natalia Medina ,
Monica Jaimes
