
//
// Created by jflyg on 2019-02-10.
//

#include "Register.h"

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

    //adds an operation to the list
    opList.push_back(make_pair(op,val));
}

//Evaluates the value of a register (at print)
void Register::calcNewValue(string op, string val, list<Register> &regs){

    bool isReg = false;
    int opVal = 0;

    //check if the value is a register
    list<Register> :: iterator it;
    for(it = regs.begin(); it != regs.end(); ++it)
        if(it->getName() == val){
           opVal = it->getValue();
           isReg = true;
    }

    //If the value is a number, convert to int
    if(!isReg){
         if(isdigit(val[0])) opVal = stoi(val); //do for all characters
         else cout << "Wrong input";
    }

    //perform operation depending on word
    if(op == "add") value=value+opVal;

    else if(op == "subtract") value=value-opVal;

    else if (op == "multiply") value=value*opVal;

    else cout << "Wrong input!";

}


void Register::clearOperationList(){

    //removes all operations in list
    opList.clear();
}

//for each pair in list, evaluate the new value and then print
void Register::print(list<Register> regs){

        for(unsigned i=0; i < opList.size(); i++){
           calcNewValue(opList.at(i).first, opList.at(i).second, regs);
        }

    //print the value
    cout << value << endl;

    //clear the list of operaations
    clearOperationList();
}
