//
// Created by jond on 04.07.2022.
//

#ifndef VISITOR_EXPRESSION_HPP
#define VISITOR_EXPRESSION_HPP

class Visitor;

typedef struct Operands{
    int a;
    int b;
} Operands;

class Expression {
public:
    virtual ~Expression() = default;
    virtual void accept(Visitor *visitor) const = 0;
};




#endif //VISITOR_EXPRESSION_HPP
