# ⚙️ Push Swap Project Summary (42 School)

Here is a summary of the workflow for my **Push Swap** project, designed for the **42 school** curriculum. This project focuses on sorting an unsorted list of random integers using highly restricted operations between two stacks.

---

## 📚 Core Objective & Constraints

The main goal is to sort a list of random numbers from **minimum to maximum values** using only two data structures, **Stack A** and **Stack B**, and a limited set of allowed movements.

The **allowed movements** are:

* **Swap:** `sa`, `sb`, `ss`
* **Push:** `pa`, `pb`
* **Rotate:** `ra`, `rb`, `rr`
* **Reverse Rotate:** `rra`, `rrb`, `rrr`

---

## 🧠 Algorithm & Efficiency

#### Chosen Algorithm: **Turk Sort**

The sorting strategy implemented is the **Turk Algorithm**. This algorithm is highly efficient and designed to minimize the total number of operations, which is the core metric of the project.

The detailed steps followed for this implementation are based on the guidance provided in the article below:

> [Article Reference: Push Swap: Turk Algorithm Explained in 6 Steps](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0)

#### Performance Metric 📈

Most of the time, this **Turk algorithm** completes the task for **500 random numbers** using **under 5500 moves**, demonstrating strong performance relative to the project requirements.

---

## 🎨 Workflow Chart

Find below the visual workflow chart for the project's logic:

![Workflow](assets/workflow_push_swap.png)

Hope it helps!
