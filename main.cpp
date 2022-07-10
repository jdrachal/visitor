#include <iostream>
#include <array>
#include <memory>

#include <expression/expression.hpp>
#include <visitor/visitor_add.hpp>
#include <visitor/visitor_sub.hpp>
#include <visitor/visitor_mul.hpp>
#include <visitor/visitor_div.hpp>
#include <static_visitor/static_visitor.hpp>
#include <fc/static_variant.hpp>


int main() {

    int a = 5;
    int b = 3;
    std::cout << "Static visitor" << std::endl;

    {
        StaticVisitor visitor;
        using SVar = fc::static_variant<Add, Sub, Mul, Div>;

        std::array<std::unique_ptr<SVar>, 4> expressions = {std::make_unique<SVar>(Add(a, b)),
                                                            std::make_unique<SVar>(Sub(a, b)),
                                                            std::make_unique<SVar>(Mul(a, b)),
                                                            std::make_unique<SVar>(Div(a, b))};

        for (const auto& e : expressions){
            e->visit(visitor);
            std::cout << "Result(" << visitor.operation() << ")=" << visitor.result() << std::endl;
        }

    }

    std::cout << "Abstract visitor" << std::endl;
    {
        std::array<std::unique_ptr<Visitor>, 4> visitors = {std::make_unique<VisitorAdd>(),
                                                            std::make_unique<VisitorSub>(),
                                                            std::make_unique<VisitorMul>(),
                                                            std::make_unique<VisitorDiv>()};

        std::array<std::unique_ptr<Expression>, 4> expressions = {std::make_unique<Add>(a, b),
                                                                  std::make_unique<Sub>(a, b),
                                                                  std::make_unique<Mul>(a, b),
                                                                  std::make_unique<Div>(a, b)};


        for (int i = 0; i < visitors.size(); i++) {
            expressions[i]->accept(visitors[i].get());
            std::cout << "Result(" << visitors[i]->operation() << ")=" << visitors[i]->result() << std::endl;
        }
    }

    return 0;
}
