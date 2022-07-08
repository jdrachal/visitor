//
// Created by jond on 04.07.2022.
//

#ifndef VISITOR_MUL_HPP
#define VISITOR_MUL_HPP

#include <string>
#include <expression/expression.hpp>
#include <visitor/visitor.hpp>


class Mul : public Expression {
public:
    Mul() = default;
    explicit Mul(int a, int b) {
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


#endif //VISITOR_MUL_HPP
