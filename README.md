# CS213-Assignment2
Write a program to read in 2 fully parenthesized expressions involving operators + and / and determine if they are equivalent.  In doing this you should assume that / is neither associative nor commutative, and + is commutative but not associative.  Thus (5+(2+(3/7))) is equivalent to (((3/7)+2)+5) but not to ((5+2)+(3/7)).  The basic idea is to convert both expressions into some canonical form, where equivalent expressions have the same canonical form.  After the conversion, the results can simply be compared to detect equivalence.

There are many ways in which a canonical form can be defined.  For example, we could define some kind of comparison order < on expression trees, and stipulate that in the canonical form the lhs tree must be < or = to the rhs tree.  So to convert to canonical form you will need to rearrange the tree to fit this rule (recursively as needed).  

Finally, < can also be defined in many ways. For example, you could say that at NULL tree is < than any tree.  If two trees have different op members, then the one with the smaller value of op (by ASCII code) is < the other and so on recursively. If two trees are primitive expressions, then the values can be compared (string comparison).

Input: two fully parenthesized expressions, separated by whitespace
Output:	1 if the expressions are equivalent, 0 if not.
