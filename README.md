# Infix-to-Postfix-using-Stack
To convert infix expression to postfix expression, we will use the stack data structure. 
By scanning the infix expression from left to right,
when we will get any operand, simply add them to the postfix form, 
and for the operator and parenthesis, add them in the stack maintaining the precedence of them.
# Evaluation for Postfix Expression
While reading the expression from left to right, push the element in the stack if it is an operand.
Pop the two operands from the stack, if the element is an operator and then evaluate it. 
Push back the result of the evaluation. Repeat it till the end of the expression.
