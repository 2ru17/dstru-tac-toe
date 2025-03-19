# Game Mechanics and Explanation

## **Overview**
This game is a **strategic, turn-based game** played on a **4x4 grid** where two players (Uno and Tres) take turns selecting positions. The goal is to form specific patterns while following strict movement and turn-based rules. Dos is a neutral entity that wins by default if the grid fills up.

--- 

## **Game Components**
### **Sets and Elements**
- **A**: `{1, 2, 3, 4}` (The numbers representing rows and columns in the grid)
- **P**: The Cartesian product `A × A`, representing all possible positions `(x, y)` on the 4x4 grid.
- **B**: Boolean values `{true, false}` (used for turn and game state tracking).
- **C**: Predefined winning position sets:
  - **Horizontal Line**: `{(1,1), (1,2), (1,3), (1,4)}`
  - **Main Diagonal**: `{(1,1), (2,2), (3,3), (4,4)}`
  - **Anti-Diagonal**: `{(1,4), (2,3), (3,2), (4,1)}`
  - **Vertical Line**: `{(4,1), (4,2), (4,3), (4,4)}`
- **T**: A relation on `A` that is **reflexive, symmetric, antisymmetric, and transitive**, ensuring valid movements.

### **System Variables**
- **Uno, Dos, Tres**: Sets containing occupied positions for each entity.
- **F (Free Positions)**: `F = P − (Uno ∪ Tres)`, represents available moves.
- **turn**: Boolean tracking whose turn it is (`true` for Uno, `false` for Tres).
- **go**: Boolean used to enforce specific movement conditions.
- **over**: Boolean indicating if the game has ended.

---

## **Game Flow**
### **Initialization**
- `Uno = ∅`, `Dos = ∅`, `Tres = ∅`
- `turn = true` (Uno starts first)
- `go = false`
- `over = false`

### **Turn-Based Actions**
- **Player Uno's Move**:
  - If `turn == true` and `go == true` and `pos ∈ F`:
    - Add `pos` to `Uno`.
    - Switch `turn` and `go` (`turn = false`, `go = false`).
- **Tres's Move (Opponent)**:
  - If `turn == false` and `pos ∈ (Uno ∪ Tres)`, they can **remove** a previously occupied position.
  - Switch `turn` (`turn = true`).
- **Player Tres's New Move**:
  - If `turn == true` and `go == false` and `pos ∈ F`:
    - Add `pos` to `Tres`.
    - Toggle `go` (`go = true`).

### **Winning Conditions**
- If `Uno`'s occupied positions match any predefined winning pattern in `W`, **Uno Wins**.
- If `Tres`'s occupied positions match any predefined winning pattern in `W`, **Tres Wins**.
- If `F = ∅` (grid is fully occupied), **Dos Wins**.

### **Game Over Condition**
The game **immediately ends** when any of the following occurs:
- `Uno` achieves a pattern in `W` → **Uno Wins**.
- `Tres` achieves a pattern in `W` → **Tres Wins**.
- The grid is completely occupied (`F = ∅`) → **Dos Wins**.

---

## **How to Apply**
1. **Initialize a 4x4 grid** and define `P` (all possible positions).
2. **Track player positions dynamically** using `Uno`, `Dos`, and `Tres` sets.
3. **Implement turn-based logic** ensuring players follow move constraints.
4. **Enforce game-over checks** after every move.
5. **Display the game state** clearly, showing occupied and free positions.
6. **End the game when a win condition is met** and display the result.

---

> This message proves that this has been edited and used commit to apply changes.

