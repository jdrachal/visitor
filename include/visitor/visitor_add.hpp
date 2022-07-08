//
// Created by jond on 05.07.2022.
//

#ifndef VISITOR_VISITOR_ADD_HPP
#define VISITOR_VISITOR_ADD_HPP

#include <string>
#include <visitor/visitor.hpp>
#include <expression/add.hpp>


class VisitorAdd : public Visitor {
public:
    void visit(const Add* ex) override {
        Operands operands = ex->operands();
        result_ = operands.a + operands.b;
        operation_ = "add";
    }
    void visit(const Sub*) override {}
    void visit(const Mul*) override {}
    void visit(const Div*) override {}

    [[nodiscard]] const int & result() const override { return result_; }
    [[nodiscard]] const std::string & operation() const override { return operation_; }
private:
    std::string operation_;
    int result_;
};


#endif //VISITOR_VISITOR_ADD_HPP
