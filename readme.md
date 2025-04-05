# 🏏 Mini Cricket Game (C++)

Welcome to **Mini Cricket**, a fun and interactive command-line cricket game developed in C++. This project simulates a basic cricket match either in single-player mode (against the computer) or two-player mode (player vs player). It's designed to help beginners learn the basics of C++ programming, randomization, user input, control flow, and modular coding with user-defined functions.

---

## 📁 Project Structure

| File Name            | Description                                  |
|----------------------|----------------------------------------------|
| `For-One-Player.cpp` | Single player cricket game (You vs Computer) |
| `For-Two-Players.cpp`| Two-player cricket game                      |
| `a.exe`              | Precompiled executable for Windows systems   |

---

## 🧠 Game Logic Explained

The core idea is inspired by hand cricket. Each player inputs a number (1-6), and the outcome is determined based on random or opposing values.

### 🕹️ Single Player (You vs Computer)
- You bat first or second based on a toss.
- While batting, you enter a number between 1 to 6.
- The computer also generates a number (randomly).
- If both numbers match → **You're out!**
- Otherwise, your number is added to the score.
- Vice versa when the computer is batting.

### 👥 Two Player Mode
- Both players take turns batting and bowling.
- The rules remain the same: matching inputs cause a wicket.
- The game ends when both players complete their innings.
- Player with the higher score wins.

---

## 🛠 Features

- Simple CLI-based interface.
- Randomized logic for realistic outcomes.
- Turn-by-turn gameplay.
- Toss to decide batting/bowling.
- Score tracking and match result display.
- Clear modular code using **User-Defined Functions (UDFs)** for better readability.

---

## 🖥️ How to Run the Game

### Prerequisite
Make sure you have a C++ compiler installed (`g++` or equivalent).

### 🔧 Compile & Run (Manual)

#### For One Player:
```bash
g++ For-One-Player.cpp -o single_player
./single_player

g++ For-Two-Players.cpp -o two_players
./two_players
