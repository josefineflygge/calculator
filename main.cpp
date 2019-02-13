#include <iostream>
//#include <string>
#include <list>
#include <iterator>
#include <fstream> //ifstream
#include <regex> //for splitting strings


#include "Register.h"

using namespace std;

/** SECTRA ARBETSPROV - SIMPLE CALCULATOR

The simple calculator can perform operations in a set of registers.
Operations: add, multiply, subtract
Value format: integer or register.

Input is read from text file,
one command per line.

Syntax:
<register> <operation> <value>
print <register>
quit

**/


//Get the saved register object with name "n"
Register getRegister(list<Register> regs, string n);
void printWelcomeText();
bool isInt(string str);

int main(int argc, char* argv[]) {


    list<Register> registers; //added registers
    ifstream inFile;  //inreader from file
    string line;
    regex ws_re("\\s+"); //used to split by whitespaces in strings
    bool regExists = false;

    //right amount of input arguments
    if (argc == 2) {

        inFile.open(argv[1]);
        if (!inFile) {
        cerr << "Textfile not found! :(" << endl;
            return 1;
        }
    }
    // too many or few input arguments
    else
        {
        // Tell the user how to run the program
        cerr << "Error: Incorrect number of input arguments. Usage: " << argv[0] << " filepath" << std::endl;
        return 1;
        }

    printWelcomeText();


    if (inFile.is_open())
    {
        //Get all them lines
        while (getline(inFile,line))
        {
            //Make input case insensitive
            for(int i = 0; i < (int)line.length(); ++i) {
            line[i] = tolower(line[i]);
            }

            //Split words in line by whitespace into vector
            vector<string> splittedLine{
            sregex_token_iterator(line.begin(), line.end(), ws_re, -1), {}};


            int wordCount = (int)splittedLine.size();

            //If the line contains a mathematical operation
            if(wordCount == 3){
                regExists = false;

                //Only numerical reg is invalid
                if(isInt(splittedLine.at(0))){
                    cout << "Error: '"+splittedLine.at(0)+"' is an invalid register name." << endl;
                    continue;
                }

                /* Check if the register already exists. If it does,
                    store the operation and value in the object */
                list<Register> :: iterator it;
                for(it = registers.begin(); it != registers.end(); ++it){
                    if(it->getName() == splittedLine.at(0)){
                        (*it).addOperation(splittedLine.at(1),splittedLine.at(2));
                        regExists = true;
                    }
                }

                /* If the register is new, add it to
                the list and store its operation and value */
                if(!regExists){
                    Register R(0,splittedLine.at(0));
                    R.addOperation(splittedLine.at(1),splittedLine.at(2));
                    registers.push_back(R);
                }


            }
            else{ //the line contains print/quit or bad input

                    if(splittedLine.at(0) == "print"){
                        getRegister(registers, splittedLine.at(1)).print(registers);

                    }
                    else if(splittedLine.at(0) == "quit"){
                        cout << endl << "Closing application..." << endl;
                        break;
                    }
                    else{
                        cout << "Error: Invalid command!" << endl;
                        continue;
                    }
                }

        }
        inFile.close();
    }

}


//Get the register object with name "n",
Register getRegister(list<Register> regs, string n){

    //check first if the register exist
    list<Register> :: iterator it;
    for(it = regs.begin(); it != regs.end(); ++it){
        if(it->getName() == n){
            return *it;
        }
    }
    cout << "Error: no register available with name '" + n +"'." << endl;
}


//Check if string is only numerical
bool isInt(string str){

    return regex_match(str, regex("[+-]?[0-9]+"));

}


//Static text information
void printWelcomeText(){

    cout << endl << "________________________________________" << endl;
    cout << endl << "Hello, welcome to the simple calculator!";
    cout << endl << "________________________________________" << endl << endl;
    cout << endl << "Result: " << endl << endl;

}
