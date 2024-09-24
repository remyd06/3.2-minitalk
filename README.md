# Minitalk 📡

Minitalk is a project developed at the 42 school, designed to implement a communication program using Unix signals. The goal is to build two programs: a **server** and a **client**. The client sends a string of characters to the server, which then displays the message. The project explores signal handling and low-level system programming.

## Table of Contents 📋

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Code Overview](#code-overview)
- [Makefile](#makefile)
- [Testing](#testing)

## Introduction

Minitalk is a simple client-server system that uses ***SIGUSR1*** and ***SIGUSR2*** signals to transmit a message one bit at a time. This project is a great way to get familiar with signal handling in Unix-like systems, and it serves as a learning exercise in low-level system programming. The server listens for incoming messages, while the client encodes a message bit by bit and sends it to the server.

## Features

- **Bit-level Communication**: Uses signals to transmit messages bit by bit.
- **Signal Handling**: Implements handlers for Unix signals, specifically SIGUSR1 and SIGUSR2.
- **Multiple Clients**: The server can handle messages from multiple clients in sequence.
- **Bonus**: Handles multiple processes and communication at the same time.

## Installation

To get started with Minitalk, clone the repository and compile the project using the provided Makefile:

```bash
git clone https://github.com/remyd06/3.2-minitalk.git
cd 3.2-minitalk
make
```
This will compile both the server and client executables.

## Usage

**Running the Server**
Start the server by running:

```bash
./server
```
The server will print its Process ID (PID), which you will need to use when running the client.

**Sending a Message**
To send a message from the client to the server, run:
```bash
./client [server_pid] [message]
```
For example:
```bash
./client 12345 "Hello, Server!"
```
This will send the message ***"Hello, Server!"*** to the server with ***PID 12345***.

## Code Overview

**Server**
The server waits for incoming signals, processes each bit received from the client, and reconstructs the message. When the message is complete, it prints it to the console.
Key functions:
- ft_handler(int signal, siginfo_t *info, void *context): Handles signals from the client.
- cat_msg(int msg, int j, int act): Reconstructs the message bit by bit.

**Client**
The client encodes the message into bits and sends each bit as a signal to the server. It sends **SIGUSR1** for a binary *1* and **SIGUSR2** for a binary *0*.
Key functions:
- ft_atoi(char *str): Converts a string to an integer (used for PID).
- ft_memcpy(void *dest, const void *src, size_t n): Copies memory from source to destination.
- ft_realloc(char *ptr, size_t old_size, size_t new_size): Resizes memory blocks dynamically.

**Utility Functions**
- ft_atoi(char *str): Converts a string to an integer (used for PID).
- ft_memcpy(void *dest, const void *src, size_t n): Copies memory from source to destination.
- ft_realloc(char *ptr, size_t old_size, size_t new_size): Resizes memory blocks dynamically.

## MakeFile

The Makefile includes rules to compile both the server and client programs, along with rules for cleaning and recompiling the project.
- Build both programs:
```bash
make
```
- Clean object files:
```bash
make clean
```
- Remove executables:
```bash
make fclean
```
- Rebuild everything:
```bash
make re
```
The Makefile will automatically compile the necessary dependencies, including linking with the libftprintf library for formatted output.

## Testing
**1. Start the server:**
```bash
./server
```
The server will print its *PID*.
**2. Send a message from the client:**
```bash
./client [server_pid] "Your message here"
```
**3. Bonus Testing:**
Try running multiple clients simultaneously to test the server's ability to handle multiple incoming messages.



  




