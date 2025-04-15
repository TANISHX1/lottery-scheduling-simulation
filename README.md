# 🎟️ Lottery Scheduler Simulation in C (Linux)

This is a simple **Lottery Scheduler Simulation** written in **C** for **Linux-based systems**. It mimics a probabilistic CPU scheduling strategy by assigning a number of tickets to each job and then randomly selecting a job in proportion to its tickets over multiple scheduling runs.

---

## 🧠 What is Lottery Scheduling?

Lottery scheduling is a CPU scheduling algorithm where each process (or job) is given a number of "lottery tickets," and the scheduler draws a random ticket to decide which job runs next. 
Jobs with more tickets have a higher chance of being selected, but all jobs with at least one ticket have a non-zero chance.

---

## 📌 Features

- Create jobs dynamically with randomly assigned tickets
- Simulate a scheduler over a configurable number of runs (default: 10)
- Display how often each job is selected ("wins")
- Optionally print selected job during each run
- Optionally sort results based on number of wins
- Ability to rerun the simulation without restarting the program
- Clean dynamic memory usage

---

## 🛠 Requirements

- GCC or any standard C compiler
- Linux OS (tested on Fedora, Ubuntu, Arch, etc.)
- Terminal access

---

## 🔧 Compilation

Use `gcc` to compile the program:

```bash
gcc -o lottery_scheduler lottery_scheduler.c
