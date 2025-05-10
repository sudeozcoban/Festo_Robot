
# Festo Robot Control System with Encrypted Access

This C++ project is a robot control interface designed for the **Festo Robot**, allowing users to securely connect and control the robot using a 4-digit encrypted access code. The robot can move in multiple directions, track its position, and operate based on user input via a menu-based console interface.

## 🚀 Features

- 🔐 **Encrypted Operator Access**
  - Operators must enter a valid 4-digit access code.
  - The code is encrypted using a custom algorithm before comparison.
  - Prevents unauthorized robot control.

- 🤖 **Festo Robot Movement Control**
  - Move Forward, Backward, Left, Right
  - Rotate Left or Right
  - Stop robot at any time
  - Position and orientation tracking using `Pose` class

- 📡 **Sensor Integration**
  - LIDAR (Laser Range Finder): Collects range data to assist in navigation
  - Pose estimation (X, Y, θ) to print current position and heading
  - Future support for proximity and obstacle detection (expandable)

- 💻 **Modular Design with OOP**
  - `FestoRobotAPI`: Interface to connect with actual robot hardware
  - `FestoRobotInterface`: Movement and pose logic abstraction
  - `RobotOperator`: Operator access handling and encryption
  - `Encryption`: Encryption/Decryption utility
  - `Point` and `Pose` classes for spatial computations

## 🔐 Encryption Logic

The access code is a 4-digit integer that is encrypted before validation using the following algorithm:

1. Add 7 to each digit and take modulo 10.
2. Swap 1st ↔ 3rd and 2nd ↔ 4th digits.

```cpp
Example:
Original code: 1234
Step 1: (1+7)%10 = 8, (2+7)%10 = 9, (3+7)%10 = 0, (4+7)%10 = 1 → [8,9,0,1]
Step 2: Swap → [0,1,8,9]
Encrypted Code: 0189
