# ExpressionOperator
A simple C++ program that creates a random binary expression tree. For example, an expression written on a
piece of paper might look like ((x * 8) + (9 - 8)). This program creates a binary tree where the middle most
node is an operator (the + operator), and then each subsequent operator in each set of parentheses acts as child 
nodes (* and - in this case). Finally, all variables (set or unset) occupy the bottom most level of the tree 
as they are not allowed to have childeren (it does not make sense to use a variable as an operator).
          (+)
      (*)     (-)
    (x) (8) (9) (8)
