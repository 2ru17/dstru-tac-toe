# DSTRU-TAC-TOE Game Mechanics and Documentation

*Last edited by: 2ru17*  

---

## **Overview**
DSTRU-TAC-TOE is a **strategic, turn-based game** played on a **4x4 grid** where two players (Uno and Tres) take turns selecting positions. The goal is to form specific patterns while following strict movement and turn-based rules. Dos is a neutral entity that wins by default if the grid fills up.

---

## **Formal Mathematical Foundation**

### **Sets and Relations**
- **A**: `{1, 2, 3, 4}` (The set of positive integers less than 5)
- **P**: The Cartesian product `A × A`, representing all possible positions `(x, y)` on the 4x4 grid
- **B**: Boolean values `{true, false}` (used for system variables)
- **C**: Set of winning patterns:
  - **Horizontal Line**: `{(1,1), (1,2), (1,3), (1,4)}`
  - **Main Diagonal**: `{(1,1), (2,2), (3,3), (4,4)}`
  - **Anti-Diagonal**: `{(1,4), (2,3), (3,2), (4,1)}`
  - **Vertical Line**: `{(4,1), (4,2), (4,3), (4,4)}`
- **T**: A relation on `A` that is **reflexive, symmetric, antisymmetric, and transitive:** `{(1,1), (2,2), (3,3), (4,4)}`
- **W**: Set `C - T` (winning patterns that are not in relation T): `{ {(1,1), (1,2), (1,3), (1,4)}, {(1,4), (2,3), (3,2), (4,1)}, {(4,1), (4,2), (4,3), (4,4)} }`

### **System Variables**
- **Uno, Dos, Tres**: Subsets of P representing positions occupied by each entity
- **F**: Set of free positions, defined as `F = P − (Uno ∪ Tres)`
- **turn**: Boolean variable indicating turn state
- **go**: Boolean variable tracking which player's turn it is
- **over**: Boolean variable indicating if the game has ended

---

## **Game Rules and Logic**

### **Initialization**
- `Uno = ∅` (Empty set)
- `Dos = ∅` (Empty set)
- `Tres = ∅` (Empty set)
- `turn = true`
- `go = false`
- `over = false`

### **State Transitions (NextPlayerMove)**

- **Sequence of movement as follows:** `Tres -> Uno -> Dos`

When a position `(pos ∈ P)` is selected, the following state transitions occur:

1. **Uno's Move**:
   - **Condition**: `turn ∧ go ∧ pos ∈ F`
   - **Effect**:
     - `Uno = Uno ∪ {pos}` (Add position to Uno's set)
     - `turn = ¬turn` (Toggle turn)
     - `go = ¬go` (Toggle go)

2. **Position Removal (Dos)**:
   - **Condition**: `¬turn ∧ pos ∈ (Uno ∪ Tres)`
   - **Effect**:
     - `Uno = Uno − {pos}` (Remove position from Uno's set)
     - `Tres = Tres − {pos}` (Remove position from Tres's set)
     - `turn = ¬turn` (Toggle turn)

3. **Tres's Move**:
   - **Condition**: `turn ∧ ¬go ∧ pos ∈ F`
   - **Effect**:
     - `Tres = Tres ∪ {pos}` (Add position to Tres's set)
     - `go = ¬go` (Toggle go)

### **Game Over Conditions**

The `over` variable is true when any of the following occurs:
- `Uno ∈ W` (Uno has achieved a winning pattern)
- `Tres ∈ W` (Tres has achieved a winning pattern)
- `F = ∅` (No free positions remain)

### **Result Determination**
- If `over ∧ Uno ∈ W`, then **Uno Wins**
- If `over ∧ F = ∅`, then **Dos Wins**
- If `over ∧ Tres ∈ W`, then **Tres Wins**

---

## **Turn-Based Gameplay Flow**

1. **Initial State**: Game starts with Tres (first player since `turn = true` and `go = false`)
2. **Regular Turn Cycle**:
   - **Tres makes a move** (when `turn = true` and `go = false`)
   - **Uno makes a move** (when `turn = true` and `go = true`)
   - **Position removal** occurs (when `turn = false`)
3. **Win Detection**: After each state transition, check if the game is over

---

## **Implementation Guidelines**

1. **Data Structures**:
   - Use arrays or sets to represent Uno, Tres, and free positions
   - Track the game state using boolean variables as specified
   - Store the winning patterns in a suitable data structure

2. **Core Algorithms**:
   - Implement the state transition logic exactly as specified
   - Create efficient methods to check if a player has achieved a winning pattern
   - Implement proper set operations (union, difference, membership testing)

3. **User Interface**:
   - Display the grid with clear visual distinction between Uno's and Tres's positions
   - Indicate whose turn it is and what action is expected
   - Show the game result clearly when the game ends



