//
// Created by jond on 08.07.2022.
//

#ifndef VISITOR_STATIC_VISITOR_HPP
#define VISITOR_STATIC_VISITOR_HPP

#include <boost/variant/static_visitor.hpp>
#include <expression/add.hpp>
#include <expression/sub.hpp>
#include <expression/div.hpp>
#include <expression/mul.hpp>

class StaticVisitor
        : public boost::static_visitor<>
{
public:

    void operator()(Add& a)
    {
        result_ = a.operands().a + a.operands().b;
        operation_ = "add";
    }

    void operator()(Sub& a)
    {
        result_ = a.operands().a - a.operands().b;
        operation_ = "sub";
    }

    void operator()(Mul& a)
    {
        result_ = a.operands().a * a.operands().b;
        operation_ = "mul";
    }

    void operator()(Div& a)
    {
        result_ = a.operands().a / a.operands().b;
        operation_ = "div";
    }

    template <typename T>
    void operator()(const T& t)
    {
        std::cerr << "Type - " << typeid(t).name() << " - is not supported" << std::endl;
    }

    [[nodiscard]] const int & result() const { return result_; }
    [[nodiscard]] const std::string & operation() const { return operation_; }

private:
    std::string operation_;
    int result_;

};

#endif //VISITOR_STATIC_VISITOR_HPP
