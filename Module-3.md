% Wumpus World and Logic Questions – Answers
% Reference: Provided Textbook
% Format: Question & Answer

---
#MODULE-3
---
## 1. Examine Wumpus World game problem and explain the steps involved by the agent in the Wumpus World.

**Answer:**  
The Wumpus World is a classic AI problem where an agent navigates a cave represented by a grid, seeking gold while avoiding pits and the Wumpus monster.  
**Steps involved by the agent:**  
1. **Perception:** The agent senses the environment (e.g., breeze, stench, glitter).
2. **Knowledge Update:** Based on perceptions, it updates its knowledge base about safe and dangerous locations.
3. **Reasoning:** Uses logic to infer new information (e.g., if breeze is felt, a pit is nearby).
4. **Decision:** Decides the next action (move, grab, shoot, climb) using inference.
5. **Action Execution:** Performs the action and loops the process.

---

## 2. List all the basic symbols used in proposition logic and represent below sentences using proposition symbols.

**Answer:**  
**Basic symbols:**  
- Propositional variables (P, Q, R, etc.)
- Logical connectives:  
  - Conjunction (AND): ∧  
  - Disjunction (OR): ∨  
  - Negation (NOT): ¬  
  - Implication: →  
  - Biconditional: ↔  
- Parentheses: ( )

**Sentence representations:**  
a. It is cold and dark  
Let C = "It is cold", D = "It is dark"  
Representation: C ∧ D

b. If I study hard then I get rich  
Let S = "I study hard", R = "I get rich"  
Representation: S → R

c. Logic is not easy  
Let E = "Logic is easy"  
Representation: ¬E

d. I am breathing if and only if I am alive  
Let B = "I am breathing", A = "I am alive"  
Representation: B ↔ A

---

## 3. Describe the forward-chaining and backward-chaining algorithms for propositional logic with suitable examples.

**Answer:**  
- **Forward-chaining:** Starts with known facts and applies inference rules to extract more facts until the goal is reached.  
  *Example:*  
  - Rules:  
    1. If P → Q, and P is true, then Q is true.  
    2. P is true.  
  - Forward-chaining deduces Q.

- **Backward-chaining:** Starts with the goal and works backwards, looking for rules that could conclude the goal, and recursively tries to prove their premises.  
  *Example:*  
  - Goal: Q  
  - Rule: If P → Q  
  - So, try to prove P.

---

## 4. Show the following arguments is valid or not using Truth Table approach

**Answer:**  
i) If it is humid then it will rain and since it is humid today it will rain  
Let H = "It is humid", R = "It will rain"  
Premises: H → R, H  
Conclusion: R

| H | R | H→R | Premises True? | Conclusion |
|---|---|------|---------------|------------|
| T | T |  T   |   Both True   |    T       |
| T | F |  F   |  1st False    |    F       |

Only when both premises are true (H=T, H→R=T), R is also true. Thus, the argument is **valid**.

ii) If it is hot and humid then it is not raining  
Let T = "It is hot", H = "It is humid", R = "It is raining"  
Premise: (T ∧ H) → ¬R

| T | H | R | T∧H | ¬R | (T∧H)→¬R |
|---|---|---|-----|----|-----------|
| T | T | T |  T  | F  |     F     |
| T | T | F |  T  | T  |     T     |
| T | F | T |  F  | F  |     T     |
| T | F | F |  F  | T  |     T     |
| F | T | T |  F  | F  |     T     |
| F | T | F |  F  | T  |     T     |
| F | F | T |  F  | F  |     T     |
| F | F | F |  F  | T  |     T     |

The implication only fails if it is hot, humid, and raining, but otherwise holds. The argument is **not valid in all cases**.

---

## 5. Explain Wumpus world game problem with diagram and PEAS representation.

**Answer:**  
**PEAS Representation:**  
- **Performance measure:** Grab gold, avoid pits & Wumpus, exit safely.
- **Environment:** Grid world of rooms, some with pits/Wumpus/gold.
- **Actuators:** Move forward, turn left/right, grab, shoot, climb.
- **Sensors:** Stench, breeze, glitter, bump, scream.

**Diagram:**  
```
+----+----+----+----+
|    |    |    |    |
+----+----+----+----+
|    |Pit |Wump|Gold|
+----+----+----+----+
|Pit |    |    |    |
+----+----+----+----+
|Agt |    |Pit |    |
+----+----+----+----+
```
(Agent starts at bottom left)

---

## 6. Why proposition logic is required? List all the basic facts about proposition logic with an example.

**Answer:**  
Propositional logic is required for representing and reasoning about facts that can be true or false.

**Basic facts:**  
- Consists of propositions (atomic or compound).
- Uses logical connectives.
- Truth values: True/False.
- Supports inference rules (e.g., Modus Ponens).
- Example:  
  - P: "It is raining", Q: "The ground is wet"
  - If P → Q and P is true, then Q is true.

---

## 7. Write the Pseudocode for Knowledge Based agent. Describe the components of Knowledge Based System with an example.

**Answer:**  
**Pseudocode:**

```
function KnowledgeBasedAgent(percept):
    t ← current time
    KB ← Tell(KB, MakePerceptSentence(percept, t))
    action ← Ask(KB, "What action should I do now?")
    KB ← Tell(KB, MakeActionSentence(action, t))
    return action
```

**Components:**
- **Knowledge Base (KB):** Stores facts/rules.
- **Inference Engine:** Applies logic to deduce new info.
- **Interface:** Receives percepts, outputs actions.

*Example:*  
In Wumpus World, KB contains rules about breezes and pits, the inference engine deduces safe moves.

---

## 8. Define the role of Propositional Logic in AI. Translate the following into propositional logic:

**Answer:**  
Propositional Logic enables AI to represent facts, reason, and infer new knowledge.

a) If it rains, then the ground is wet.  
P = "It rains", Q = "Ground is wet"  
Representation: P → Q

b) It is not raining or it is cloudy.  
R = "It is raining", C = "It is cloudy"  
Representation: ¬R ∨ C

---

## 9. Define the resolution principle in FOL. Provide a step-by-step example using resolution refutation to prove a conclusion.

**Answer:**  
**Resolution Principle:**  
A rule of inference for FOL; resolves two clauses containing complementary literals to produce a new clause.

**Example:**  
Given:  
1. P ∨ Q  
2. ¬Q ∨ R  
3. ¬R  
Prove: P

**Steps:**  
- From (2) and (3): ¬Q ∨ R, ¬R ⇒ ¬Q (resolving R and ¬R)
- From (1) and above: P ∨ Q, ¬Q ⇒ P

Thus, P is proved.

---

## 10. Given the following facts...prove by resolution that John likes peanuts.

**Answer:**  
**Facts:**  
1. ∀x Food(x) → Likes(John, x)  
2. Food(Apples), Food(Vegetables)  
3. ∀x∀y Eats(x, y) ∧ ¬Killed(x, y) → Food(y)  
4. Eats(Anil, Peanuts), ¬Killed(Anil, Peanuts)  
5. ∀x Eats(Harry, x) ← Eats(Anil, x)

**Goal:** Likes(John, Peanuts)

**Resolution Steps:**  
- From (4): Eats(Anil, Peanuts) and ¬Killed(Anil, Peanuts) ⇒ Food(Peanuts) (by 3)
- From (1): Food(Peanuts) ⇒ Likes(John, Peanuts)

Hence, John likes peanuts.

---

## 11. Explain the syntax and semantics of First Order Logic. Provide suitable examples.

**Answer:**  
- **Syntax:**  
  - **Constants:** objects (e.g., John)  
  - **Predicates:** relations (e.g., Loves(John, Mary))  
  - **Variables:** x, y  
  - **Quantifiers:** ∀ (universal), ∃ (existential)  
  - **Connectives:** ∧, ∨, ¬, →, ↔

- **Semantics:**  
  - Assigns meaning to symbols: objects, relations, truth values.

*Example:*  
∀x Human(x) → Mortal(x): "All humans are mortal."

---

## 12. Define Universal and Existential Instantiation and give examples for both. Prove the following using Backward and Forward chaining...

**Answer:**  
- **Universal Instantiation:**  
  From ∀x P(x), infer P(c) for any constant c.  
  *Example:* ∀x Human(x) → Mortal(x), so Human(Socrates) → Mortal(Socrates)

- **Existential Instantiation:**  
  From ∃x P(x), infer P(c) for some new constant c.  
  *Example:* ∃x Cat(x), so Cat(a) for some a.

**Prove "Solan is criminal":**  
**Given:**  
- Law: ∀x, y, z [American(x) ∧ Weapon(y) ∧ Sells(x, y, z) ∧ Hostile(z)] → Criminal(x)
- Country E is hostile, has missiles sold by Solan (an American).
- Missiles are weapons.

**Forward Chaining:**  
1. American(Solan), Weapon(Missiles), Sells(Solan, Missiles, E), Hostile(E)
2. Apply law: Solan is criminal.

**Backward Chaining:**  
Goal: Criminal(Solan)  
Try to satisfy all premises in the law; each is directly supported by facts.

---

## 13. Explain First order Logic that converts FOL to propositional logic through Instantiation methods

**Answer:**  
FOL can be converted to propositional logic by replacing variables with all possible constants (grounding the formula), turning quantified statements into propositional ones.  
*Example:*  
∀x P(x) with domain {a, b} becomes P(a) ∧ P(b).

---

## 14. Explain in detail Modus Ponens and how it impact inference rules.

**Answer:**  
**Modus Ponens:**  
If P → Q and P is true, then Q is true.

Impact:  
- Fundamental inference rule for deductive reasoning in logic systems.
- Enables automated proof systems to derive new facts.

---

## 15. Write the algorithm for Unification process

**Answer:**  
**Algorithm:**  
1. Input two predicates.
2. If both are identical, return empty substitution.
3. If one is a variable, substitute it.
4. If both are compound, unify their arguments recursively.
5. If fails at any step, return "failure".
6. Output: Most General Unifier (MGU).

---

## 16. Explain in detail resolution principle with suitable examples

**Answer:**  
The resolution principle is a rule of inference for both propositional and first-order logic that produces new clauses by eliminating complementary literals.

*Example:*  
1. A ∨ B  
2. ¬B ∨ C  
Resolution on B and ¬B gives: A ∨ C

This process is repeated until the empty clause is derived, indicating the original set is unsatisfiable (proof by contradiction).
