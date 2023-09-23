#include <iostream>
#include <string>
#include <stack>


class AbstractExpression
{
public:
    virtual int interpert() = 0;

};

class TerminalExpression : public AbstractExpression
{
private:
    int value;

public:
    TerminalExpression(int val) :value(val)
    {}

    int interpert() override
    {
        return value;
    }

};


class NonterminalExpression : public AbstractExpression
{
private:

    AbstractExpression* left;
    AbstractExpression* right;
    char operation;

public:
    NonterminalExpression(AbstractExpression* L, AbstractExpression* R, char op)
        :left(L),right(R),operation(op)
    {   
    }

    int interpert() override
    {
        const int leftValue = left ?  left->interpert() : 0;
        const int rightValue = right ?  right->interpert() : 0;

        std::cout << leftValue << " " << operation << " " << rightValue << " " << std::endl;

        if (operation == '+') 
        {
            return leftValue + rightValue;
        }
        else if (operation == '-') 
        {
            return leftValue - rightValue;
        } 
        else if (operation == '*') 
        {
            return leftValue * rightValue;
        } 
        else if (operation == '/') 
        {
            if (rightValue != 0) 
            {
                return leftValue / rightValue;
            } 
            else 
            {
                throw std::runtime_error("Division by zero");
            }
        }

        throw std::runtime_error("operation error");
        return 0;
    }

};

int main()
{
 
 // 构建一个简单的数学表达式：1 + 2 * 3
    AbstractExpression* expression = new NonterminalExpression(
        new TerminalExpression(1), 
        new NonterminalExpression(new TerminalExpression(2), new TerminalExpression(3), '*'),
        '+');

    int result = expression->interpert();
    std::cout << "Result: " << result << std::endl;

    delete expression;

    return 0;
}

