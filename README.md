# CPU Process Scheduler Simulation

A C++ simulation project to implement, visualize, and benchmark standard Operating System CPU scheduling algorithms.

## ⚙️ Algorithms Implemented
1. **First-Come, First-Served (FCFS)**
2. **Shortest Job First (SJF)** (Preemptive & Non-Preemptive)
3. **Round Robin (RR)** with configurable time quantum
4. **Priority Scheduling** (Preemptive & Non-Preemptive)

## 📊 Metrics Calculated
- Turnaround Time (TAT)
- Waiting Time (WT)
- Average Waiting Time & Efficiency comparison across algorithms

## 🛠️ Tech Stack
- **Language:** C / C++
- **Concepts:** Operating Systems, Process Management, Scheduling

## 🚀 How to Compile & Run
```bash
g++ main.cpp -o scheduler
./scheduler
