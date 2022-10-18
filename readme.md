# Refactoring exercise

Examine the code in `TicTacToe.cpp` and the test in `test.cpp`. It has a simple implementation of a TicTacToe game.
Notice that the `winner()` method is simplified: you win by getting three in a row horizontally. 
Notice also that the heuristics for what to play are primitive: win if you can, play any valid move otherwise. 
We’ll migrate toward something capable of more sophisticated strategies.

## Smells

Go through this code and identify smells.

## Easy changes

It’s not always easy to know what to do with code. Let’s fix some of the easy things first.
Fix them one at a time. Run theest aerach change.

- [ ] The name `move()` isn’t descriptive enough. Change it to `bestMoveFor()`. Usse `F2` key.
- [ ] The variable `i` doesn’t explain much either. It's not just an index variable, it represents something the game world. Change it to `move`. Use `F2` key.
- [ ] The value -1 is a flag value; create a constant `NoMove` to represent it.
- [ ] The `winner()` function has a lot of duplication. Eliminate the duplication.
- [ ] The check for a board character being a ‘-’ is really a check that the square is unoccupied. Extract a method to do this, and name it appropriately.

## Fuse loops

We have two “for” loops: one to find a winning move, the other to find a default move.
The loops have the same number of iterations. Maybe its reddundant visiting every part of the grid twice?
One way to handle this would be to merge the two loops and handle things in one pass through the possible moves.

**“Fuse Loops”** means combine two loops into one. Do so in small steps, in such a way that you maintain safety (keeps tests passing) as you do it. 
When is it safe to merge two loops?

One step along the way might be to assign a value to a temporary variable rather than return it right away. 
You might have made the second loop look like this:

```
 defaultMove = NoMove;
 for (int i = 0; i < 9; i++) {
 if (board[i] == ‘-‘)
   if (defaultMove == NoMove)
     defaultMove = i;
 }
 ```
 
 That was the safest approach, used because we did not want our refactoring to change behavior. 
 To be equivalent to the original, we need the guard clause to make sure we haven’t assigned a defaultMove yet.
 But let’s put on a development hat: we don’t really care which default move we make, so we could delete the “defaultMove==NoMove” condition. 
 It’s not necessary to stop when we find a viable move. (That is, there’s no harm in trying each possible move provided we prefer wins to defaults.) 
 So you can delete the “break” tests that exit early. Run the tests again and be sure you haven’t changed anything important. 
 (*You may have to change the tests**. What does this tell you?)
 
 Now we have a single loop, but the condition to decide what to return is still a little complicated:
 
 ```
   if (winningMove != NoMove)
     return winningMove;
   if (defaultMove != NoMove)
     return defaultMove;
   return NoMove;
 ```
 
 How would you simplify the above?
 
 *Hint: use a `result` var to return the correct move. Also no need to continue the loop if a winning move is found*
 
 
