# Math Game (C++)

A simple console-based math quiz game written in C++. The program generates random arithmetic questions and evaluates the user's answers.

## Features

- Choose the number of questions.
- Select difficulty level:
  - Easy
  - Medium
  - Hard
  - Mixed
- Select operation type:
  - Addition
  - Subtraction
  - Multiplication
  - Division
  - Mixed Operations
- Instant feedback after each answer.
- Final score summary.
- Pass/Fail result based on performance.
- Option to play again.

---

## Difficulty Levels

| Level | Number Range |
|---------|-------------|
| Easy | 1 - 10 |
| Medium | 10 - 40 |
| Hard | 40 - 100 |
| Mix | 1 - 100 |

---

## Supported Operations

| Option | Operation |
|----------|----------|
| 1 | Addition (+) |
| 2 | Subtraction (-) |
| 3 | Multiplication (×) |
| 4 | Division (/) |
| 5 | Mixed |

---

## How It Works

1. Enter the number of questions.
2. Choose a difficulty level.
3. Choose an operation type.
4. Answer each generated question.
5. Receive immediate feedback:
   - Right Answer :-)
   - Wrong Answer :-(
6. View the final results summary.

---

## Example

```text
How many Questions do you want answer? 3

Enter Questions Level:
[1] Easy
[2] Med
[3] Hard
[4] Mix

Enter Operation Type:
[1] Add
[2] Sub
[3] Mul
[4] Div
[5] Mix

Question [1/3]

8
5 +

___________
13

Right Answer :-)
```

---

## Final Results Example

```text
_______________________

 Final Results is PASS :-)

_______________________

Number of Questions : 10
Questions Level     : Easy
OpType              : Add
Number of Right Answers : 8
Number of Wrong Answers : 2
```

---

## Requirements

- C++ Compiler (C++11 or later)
- Windows Console (the program uses `system("cls")` and `system("color")`)

### Compile

Using g++:

```bash
g++ MathGame.cpp -o MathGame
```

### Run

```bash
./MathGame
```

---

## Project Structure

- `stQuiz` → Stores information about a single question.
- `stQuizResults` → Stores final quiz statistics.
- `PlayGame()` → Main quiz loop.
- `StartGame()` → Handles replaying the game.
- `GetAnswer()` → Calculates the correct answer.
- `FillQuizResult()` → Generates final results.

---

## Notes

- Division uses integer division.
- Random numbers are generated using `rand()`.
- The console color changes:
  - Green for correct answers.
  - Red for wrong answers.
- The game continues until the user chooses not to play again.

---

Console Math Quiz Game implemented in C++ for practicing:
- Functions
- Structures
- Enumerations
- Loops
- Random Number Generation
- User Input Validation
