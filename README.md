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
- [Author](#author)
- [License](#license)

## Introduction

Minitalk is a simple client-server system that uses **SIGUSR1** and **SIGUSR2** signals to transmit a message one bit at a time. This project is a great way to get familiar with signal handling in Unix-like systems, and it serves as a learning exercise in low-level system programming. The server listens for incoming messages, while the client encodes a message bit by bit and sends it to the server.

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
