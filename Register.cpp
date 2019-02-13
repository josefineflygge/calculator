#include "Register.h"
#include <regex>

/** REGISTER
 * Class definitions for member functions
 * **/

//Constructors
Register::Register(){}

Register::Register(int regVal, string regName){
    value = regVal;
    name = regName;
}

string Register::getName(){
    return name;
}

int Register::getValue(){
    return value;
}

//get the list of operations stored
vector<pair<string,string>>  Register::getOpList(){
    return opList;
}

//Add an integer to a register
void Register::operator + (int& val){
    value = value+val;
};

//Subtract an integer from a register
void Register::operator - (int& val) {
    value = value-val;
};


//Multiply an integer with a register
void Register::operator * (int& val) {
    value = value*val;
};

//Stores operations until used on print
void Register::addOperation(string op, string val){
    opList.push_back(make_pair(op,val));
}

//Evaluates the value of a register (at print)
int Register::calcNewValue(list<Register> regs){

    bool isReg = false;
    bool isInteger = false;
    string op;
    string val;

        //For each operation and value in opList
        for(unsigned i=0; i < opList.size(); i++){
            op = opList.at(i).first;
            val = opList.at(i).second;

            //check if the value is integer
            isInteger = regex_match(val, regex("[+-]?[0-9]+"));

            //Value is a number -> convert to int
            if(isInteger){
                performCalculation(op, stoi(val));
            }
            else{
                //Check if value is stored register
                for(list<Register> :: iterator it = regs.begin(); it != regs.end(); ++it){
                    if(it->getName() == val){
                        performCalculation(op, it->calcNewValue(regs)); //find new value recursively
                        isReg = true;
                    }
                }
            }
            if(!isInteger && !isReg){
                cout << "Error: '" + val +"' is not a valid value!" << endl;
            }

        }


    return value;


}

//Do the operation on the registerobject
int Register::performCalculation(string op, int opVal){

    //perform operation depending on word
    if(op == "add") value=value+opVal;

    else if(op == "subtract") value=value-opVal;

    else if (op == "multiply") value=value*opVal;

    else cout << "Error: '" + op +"' is not a valid operation!" << endl;

    return value;

}

//removes all operations in list
void Register::clearOperationList(){
    opList.clear();
}


//Evaluate the new value and then print
void Register::print(list<Register> regs){
    cout << calcNewValue(regs) << endl;
    clearOperationList();
}
