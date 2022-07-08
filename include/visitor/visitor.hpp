//
// Created by jond on 04.07.2022.
//

#ifndef VISITOR_VISITOR_HPP
#define VISITOR_VISITOR_HPP

#include <string>
class Add;
class Sub;
class Mul;
class Div;

class Visitor {
public:
    virtual void visit(const Add*) = 0;
    virtual void visit(const Sub*) = 0;
    virtual void visit(const Mul*) = 0;
    virtual void visit(const Div*) = 0;
    virtual const int & result() const = 0;
    virtual const std::string & operation() const = 0;
};


#endif //VISITOR_VISITOR_HPP
