# Simple Shell

A simple UNIX command interpreter implemented in C. This project replicates core functionalities of the Bourne Again Shell (bash) and was developed as part of the Holberton School curriculum.

---

## Table of Contents

- [Description](#description)
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
  - [Interactive Mode](#interactive-mode)
  - [Non-Interactive Mode](#non-interactive-mode)
- [Built-in Commands](#built-in-commands)
- [Examples](#examples)
- [Authors](#authors)

---

## Description

The **Simple Shell** project is a command-line interpreter that allows users to interact with the operating system by executing commands. It supports basic shell functionalities such as handling commands with arguments, built-in commands, and executing external programs.

This shell can operate in two modes:
1. **Interactive Mode**: The shell displays a prompt and waits for user input.
2. **Non-Interactive Mode**: The shell executes commands provided via a pipeline or file input.

---

## Features

- **Command Execution**: Supports executing commands with arguments.
- **Built-in Commands**: Includes basic shell commands like `cd`, `exit`, and `help`.
- **PATH Resolution**: Searches for executable programs in the directories listed in the `PATH` environment variable.
- **Error Handling**: Displays appropriate error messages for invalid commands.
- **Interactive and Non-Interactive Modes**: Operates seamlessly in both modes.

---

## Requirements

- **Operating System**: Ubuntu 20.04 LTS
- **Compiler**: GCC 9.3.0
- **Editor**: Compatible with `vi`, `vim`, or `emacs`

---

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/Kariaki58/simple_shell.git

Navigate to the project directory:

```bash
  cd simple_shell
```

Compile the program:

```gcc -Wall -Werror -Wextra -pedantic *.c -o hsh```

Usage

Interactive Mode
To start the shell in interactive mode:

```./hsh```

The shell will display a prompt ($) and wait for the user to input commands.

Example:

```
$ ls
file1.c file2.c README.md
```

Non-Interactive Mode
To use the shell in non-interactive mode, provide commands via a pipeline or input file:
```
echo "ls -l" | ./hsh
```
Example:
```
total 8
-rw-r--r-- 1 user user 1024 Jan 16 14:00 file1.c
-rw-r--r-- 1 user user 1024 Jan 16 14:00 file2.c
```

Built-in Commands
  - cd [directory]: Changes the current working directory.
  - exit [status]: Exits the shell with the specified status code.

help: Displays information about the shell and its built-in commands.

# Examples

List files in the current directory:


```$ ls -l
total 8
-rw-r--r-- 1 user user 1024 Jan 16 14:00 file1.c
-rw-r--r-- 1 user user 1024 Jan 16 14:00 file2.c
```

# Change the current directory:
```
$ cd ..
$ pwd
/home/user
```

# Exit the shell:

```
$ exit 0
Display help for built-in commands:
```
```
$ help
Simple Shell - A UNIX command interpreter
```

# Built-in commands:
  cd [directory]        Change the current working directory
  help                  Display information about built-in commands
  exit [status]         Exit the shell

### Authors
Kariaki58
