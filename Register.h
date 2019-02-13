#include <iostream>
#include <list>
#include <vector>
#include <iterator>

using namespace std;

/** REGISTER
 * Class declarations
 * **/

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

    //Stores operations until print
    void addOperation(string op, string value);

    //Clear list of operations
    void clearOperationList();

    //Evaluates the value of a register (at print)
    int calcNewValue(list<Register> regs);

    //Check if string is only numerical
    bool isInt(string str);
    //Calculate new values
    int performCalculation(string op, int opVal);

    //Displays the value of a register (lazy evaluation)
    void print(list<Register> regs);

};

