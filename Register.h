//
// Created by jflyg on 2019-02-10.
//
#include <iostream>
#include <list>
#include <vector>
#include <iterator>

using namespace std;

/** Declarations for class Register **/
class Register {

private:

    string name;
    int value;

    //stores pairs containing <operation, value/register>
    //operations to be performed on print
    vector<pair<string,string>> opList;

public:

    //Default constructor
    Register();

    //Constructor that initializes the register with a value and name
    Register(int regVal, string regName);

    string getName();

    int getValue();

    vector<pair<string,string>> getOpList();

    //Add an integer to a register
    void operator+(int& val);

    //Subtract an integer from a register
    void operator- (int& val);

    //Multiply an integer with a register
    void operator* (int& val);

    //stores operations until print
    void addOperation(string op, string value);

    //clear list of operations (used on print)
    void clearOperationList();

    //Evaluates the value of a register (at print)
    void calcNewValue(string op, string val, list<Register> &regs);

    //Displays an expression
    //friend
    void print(list<Register> regs);

};

