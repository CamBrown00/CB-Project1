
Style:
I prefer style 1 (CamelCase, RME's, egyptian braces, no variable prefixes), because it doesn't involve the hassle of variable prefixes,
and the rme documentation helps to keep me organized when I'm working.
I'm also not really a fan of snake case, so that's probably part of it too.

Errors:
| Type of error (compiler, runtime, logic) | File | Description | Fix |
| compiler | Board.h | Index error, attempted to index the 2d vector grid and change an integer value before pushing empty vectors of integers onto grid, used debugger to check contents of grid by setting breakpoint before | created an empty vector<int> called tempPieces and pushed into grid in loop |
| compiler | main.cpp | "too few arguments to function 'int getInput(int)'",specified an integer type parameter in global function declaration and forgot to remove it after refactoring code | removed int parameter from function declaration |
| runtime | Board.h | Initally typed "cout << "\nBLACK TEAM SCORE: " + blackScore << endl;", score wouldn't display in console | replaced the + with << |
