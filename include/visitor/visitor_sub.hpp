//
// Created by jond on 05.07.2022.
//

#ifndef VISITOR_VISITOR_SUB_HPP
#define VISITOR_VISITOR_SUB_HPP

#include <string>
#include <visitor/visitor.hpp>
#include <expression/sub.hpp>

class VisitorSub : public Visitor {
    void evaluateSub(const Sub* ex) override {
        Operands operands = ex->operands();
        result_ = operands.a - operands.b;
        operation_ = "sub";
    }
    void evaluateAdd(const Add*) override {}
    void evaluateMul(const Mul*) override {}
    void evaluateDiv(const Div*) override {}

    [[nodiscard]] const int & result() const override { return result_; }
    [[nodiscard]] const std::string & operation() const override { return operation_; }
private:
    std::string operation_;
    int result_;
};


#endif //VISITOR_VISITOR_SUB_HPP
