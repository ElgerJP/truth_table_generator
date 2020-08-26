| Truth Table Finder - Instructions for use |
---------------------------------------------

INSTRUCTIONS

1. Open the file "input.txt" and insert the logical expression you want to see its truth table, typing one logical expression per line. At the end of each logical expression, break the line with an enter.
1.1. Use the following syntax for the formulation of the logical expression:
---------------------------------------
| Propositions = Capital Characters   |
---------------------------------------
|  -> | Conditional                   |
|  ~  | Denial                        |
|  ^  | Conjunction                   |
|  v  | Disjunction                   |
| <-> | Biconditional                 |
|  #  | Exclusive disjunction         |
---------------------------------------
1.2. Proposals must be entered in alphabetical order, but can be repeated later. Example:
A ^ B ^ C ^ B ^ A = Correct, correct alphabetical order (1st = A, 2nd = B, 3rd = C)
A ^ P ^ B ^ A = Incorrect, compromised alphabetical order (1st = A, 2nd = C)

2. After entering the expressions you want to calculate, close and save the file "input.txt" and execute the file "TruthTableFinder.exe".

3. A file called "output.txt" originated in the same folder where the executable is located.


* NOTE: For more information, see the .pdf in its folder, only available in PT/BR.