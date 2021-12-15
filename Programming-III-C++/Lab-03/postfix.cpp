//Eric Blanco

#include <iostream>
#include <string>
#include <cctype>

#define MAX 1000 //max size of the stack used

//postfix class
class Postfix{
    private:
        int stack[MAX];
        int top;
        std::string expr;

    public:
        Postfix();
        void setExpr(std::string s);
        void push(int value);
        int pop();
        void evaluate();
        void show();
};

//construct empty stack
Postfix::Postfix(){top = -1;}

//set expression string
void Postfix::setExpr(std::string s){expr = s;}

//stack push
void Postfix::push(int value){
    if (top == MAX - 1)
        std::cout << std::endl << "Stack is full";
    else{
        top++;
        stack[top] = value;
    }
}

//stack pop
int Postfix ::pop(){
    if (top == -1){
        std::cout << std::endl << "Stack is empty";
        return 0;
    }
    int data = stack[top];
    top--;
    return data;
}

//evaluate expression string
void Postfix::evaluate(){
    int i = 0;
    while (expr[i]){
        //if space or tab, move on
        if (expr[i] == ' ' || expr[i] == '\t'){
            i++;
            continue;
        }
        //if operand, push to stack
        if (isdigit(expr[i])){
            int temp = expr[i] - '0';
            push(temp);
        }
        // in operator, pop two operands, apply operator and push again
        else{
            int top1 = pop();
            int top2 = pop();
            int result;
            switch (expr[i]){
            case '+':
                result = top2 + top1;
                break;
            case '-':
                result = top2 - top1;
                break;
            case '/':
                result = top2 / top1;
                break;
            case '*':
                result = top2 * top1;
                break;
            }
            push(result);
        }
        i++;
    }
}

//show result of expression
void Postfix ::show(){
    int result = pop();
    std::cout << "Result is: " << result << std::endl;
}

//driver function
int main(){

    bool running = true;
    while(running){
        std::string expr = "";
        std::cout << "\nEnter Postfix expression to be evaluated (type quit to stop): ";
        getline(std::cin, expr);//expression in one line
        if(expr == "quit")
            running = false;
        else{
            Postfix p;
            p.setExpr(expr);
            p.evaluate();
            p.show();
        }
    }
    return 0;
}