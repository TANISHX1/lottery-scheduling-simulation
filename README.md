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
```
▶️ Running the Program
```bash
./lottery_scheduler
```
## Sample Interaction:
```
Enter number of jobs:   2
Press [1]: To see job selection per schedule  | [0]: To Skip :  1
Press [1]: To short the Wins Statics | [0]: To Skip :   1
 Selected Job: Job_B (winning ticket # 12)
 Selected Job: Job_A (winning ticket # 0)
 Selected Job: Job_A (winning ticket # 5)
 Selected Job: Job_B (winning ticket # 13)
 Selected Job: Job_A (winning ticket # 0)
 Selected Job: Job_B (winning ticket # 13)
 Selected Job: Job_A (winning ticket # 6)
 Selected Job: Job_A (winning ticket # 4)
 Selected Job: Job_B (winning ticket # 12)
 Selected Job: Job_A (winning ticket # 8)

==Job Wins Statics(out of 10 runs)===
Job_B-> Wins: 4 (40.00%)
Job_A-> Wins: 6 (60.00%)
Press [Y]:To Run Again [N]: To Exit     N
```
##📁 Code Structure

  -  lottery_scheduler.c – Main C program implementing:
  -    Linked list for job tracking
  -    Random ticket allocation
  -    Lottery selection algorithm
  -    Optional sorting of job stats
  -    Memory management

##🔄 Program Flow

   - Prompt user to enter the number of jobs.
   - Assign each job a random number of tickets.
   - Ask if the user wants to:
       - View selection per run
       - Sort stats after the simulation
   - Run the lottery scheduler for a predefined number of times.
   - Show job win statistics and prompt for rerun.

🧼 Memory Management

All dynamically allocated memory is freed at the end of each simulation using free_job_list().
