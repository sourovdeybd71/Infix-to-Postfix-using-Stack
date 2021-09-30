#include <stdio.h>
#include<string.h>

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

int main(void) {
  char infix[100], postfix[100];
  printf("Enter an expression (infix):");

  //taking character input
  gets(infix);

  infixToPostfix(infix, postfix);

  printf("Postfix Expression: %s\n" , postfix);
}