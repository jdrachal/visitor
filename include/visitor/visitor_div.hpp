//
// Created by jond on 05.07.2022.
//

#ifndef VISITOR_VISITOR_DIV_HPP
#define VISITOR_VISITOR_DIV_HPP

#include <string>
#include <visitor/visitor.hpp>
#include <expression/div.hpp>

class VisitorDiv : public Visitor {
public:
    void evaluateDiv(const Div* ex) override {
        Operands operands = ex->operands();
        result_ = operands.a / operands.b;
        operation_ = "div";
    }
    void evaluateAdd(const Add*) override {}
    void evaluateSub(const Sub*) override {}
    void evaluateMul(const Mul*) override {}

    [[nodiscard]] const int & result() const override { return result_; }
    [[nodiscard]] const std::string & operation() const override { return operation_; }
private:
    std::string operation_;
    int result_;
};


#endif //VISITOR_VISITOR_DIV_HPP
