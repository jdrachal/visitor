//
// Created by jond on 04.07.2022.
//

#ifndef VISITOR_ADD_HPP
#define VISITOR_ADD_HPP

#include <string>
#include <expression/expression.hpp>
#include <visitor/visitor.hpp>


class Add : public Expression {
public:
    Add() = default;
    explicit Add(int a, int b) {
        operands_.a = a;
        operands_.b = b;
    };
    void accept(Visitor *visitor) const override {
        visitor->visit(this);
    }

    [[nodiscard]] const Operands & operands() const { return operands_; }

private:
    Operands operands_;
};

#endif //VISITOR_ADD_HPP
