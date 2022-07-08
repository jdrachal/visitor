//
// Created by jond on 04.07.2022.
//

#ifndef VISITOR_DIV_HPP
#define VISITOR_DIV_HPP

#include <string>
#include <stdexcept>
#include <expression/expression.hpp>
#include <visitor/visitor.hpp>


class Div : public Expression {
public:
    Div() = default;
    explicit Div(int a, int b) {
        if (b == 0) {
            throw std::invalid_argument("Division by zero is not allowed");
        }
        operands_.a = a;
        operands_.b = b;
    };
    void accept(Visitor *visitor) const override {
        visitor->evaluateDiv(this);
    }

    [[nodiscard]] const Operands & operands() const { return operands_; }

private:
    Operands operands_;
};


#endif //VISITOR_DIV_HPP
