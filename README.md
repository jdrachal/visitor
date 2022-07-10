# visitor

### Description

#### Purpose
This application was made to prove that I'm  able to understand and use *visitor*, *static visitor* and *static variant*
patterns

#### Externals
It uses external *fc* library (link below)
https://gitlab.syncad.com/hive/hive/-/tree/develop/libraries/fc

#### Build and run
Build for Ubuntu 20.04
```
git clone https://github.com/jdrachal/visitor.git
cd visitor
git submodule update --init --recursive
cmake .
make
./visitor
```


#### Output
Program returns the evaluations of four expressions for *static visitor* and *abstract visitor*

Expressions:
* add: *a + b*
* sub: *a - b*
* mul: *a * b*
* div: *a / b*

Where operands are hardcoded as follows: *a=5* and *b=3*