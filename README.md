# Pipex

## Project Overview

**Pipex** was a system programming project focused on recreating Unix shell pipeline functionality in C. The objective was to build a program that executes shell commands connected by pipes, handling input/output redirection between files and processes using low-level system calls.

The project emphasized:
- Creating child processes (`fork`) and managing them (`wait`, `waitpid`)
- Setting up pipes for inter-process communication (`pipe`)
- Redirecting input/output using file descriptor duplication (`dup`, `dup2`)
- Executing external commands with `execve`
- Robust error handling and memory management

Additionally, the project included **bonus features** which allowed:
- Handling **multiple chained pipes**, enabling execution of more than two commands sequentially
- Supporting **here-document (here_doc)** input redirection to simulate shell behavior with inline input streams

---

## Description

#### The purpose of the program is to run:
```bash
./pipex file1 cmd1 cmd2 file2
```
- file1 is the input file providing data to cmd1.
- cmd1 is the first command executed.
- cmd2 is the second command receiving cmd1’s output as input.
- file2 is the file where the final output is written.

This replicated the shell command:
```bash
< file1 cmd1 | cmd2 > file2
```

#### And with bonus it runs as follows:
Chained Commands:
```bash
./pipex file1 cmd1 cmd2 cmd3 cmd4 ... file2
```
To replicate the shell command:
```bash
< file1 cmd1 | cmd2 | cmd3 | cmd4 | ... > file2
```
Here Document:
```bash
./pipex here_doc LIMITER cmd1 cmd2 file2
```
To replicate the shell command:
```bash
cmd1 << LIMITER | cmd2 >> file
```

#### Key requirements:
- Forking processes for each command
- Connecting commands with pipes for proper data flow
- Redirecting input and output file descriptors correctly
- Handling invalid inputs, commands, or file errors gracefully
