#include <stdio.h>
#include<string.h>
#include<math.h>
//char stack
char stack[100];
int top = -1;

void push(char item){
  stack[++top]=item;
}

char pop(){
  return stack[top--];
}

//returns precedence of operators
int precedence(char symbol){
  switch(symbol){
    case '^':
        return 4;
        break;
    case '*':
    case '/':
        return 3;
        break;
    case '+':
    case '-':
        return 2;
        break;
    case '(':
    case ')':
        return 1;
        break;
  }
}

int isOperand(char ch){
  switch(ch){
    case '+':
      case '-':
      case '*':
      case '/':
      case '^':
      case '(':
      case ')':
          return 0;
          break;
      default:
        return 1;
  }
}


void infixToPostfix(char infix[],char postfix[]) {
   int i,k;
   char ch;
   stack[++top] = '(';

   k = 0;
   for(i=0; i<strlen(infix); i++) {
      ch = infix[i];

      if(isOperand(ch)) {
         postfix[k] = ch;
         k++;
      }
      else if(ch == '(') {
         push(ch);
      }
      else if(ch == ')') {
         while(stack[top] != '(') {
            postfix[k] = pop();
            k++;
         }

         pop();
      }
      else if(precedence(ch)>precedence(stack[top])) {
         push(ch);
      }
      else{
         while(precedence(ch)<=precedence(stack[top])) {
             postfix[k] = pop();
             k++;
         }

         push(ch);
      }
   }

   while(stack[top] != '(') {
      postfix[k] = pop();
      k++;
   }

   postfix[k]='\0';

}
//Evaluation for POSTFIX expression
int stack2[25];
int top2 =-1;

void push2(int item){
  stack2[++top2] = item;

}
char pop2(){
  return stack2[top2--];
}

float evaluate_postfix(char postfix[]){
  char ch;
  int i, operand1, operand2;

  i=0;
  while ((ch = postfix [i++])!= '\0'){
    //if it is a digit then make it integer value via ch-0
    if(isdigit(ch)){
      push2(ch-'0');
    }
    //if it is not a digit then its a operand so do the next
    else{
      operand2=pop2();
      operand1 = pop2();

      switch(ch){
        case '-':
            push2(operand1-operand2);
            break;
        case '+':
            push2(operand1+operand2);
            break;
        case '*':
            push2(operand1*operand2);
            break;
        case '/':
            push2(operand1/operand2);
            break;
      }
    }
  }
  return stack2[top2];
}

int main(void) {
  char infix[100], postfix[100];
  printf("Enter an expression (infix):");

  //taking character input
  gets(infix);

  infixToPostfix(infix, postfix);

  printf("Postfix Expression: %s\n" , postfix);

  int result= evaluate_postfix(postfix);
  printf("Result: %d", result);

}