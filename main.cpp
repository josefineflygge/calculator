#include <iostream>
//#include <string>
#include <list>
#include <iterator>
#include <fstream> //ifstream
#include <regex> //for splitting strings


#include "Register.h"

using namespace std;

/** SECTRA ARBETSPROV - SIMPLE CALCULATOR
 * by Josefine Flügge
 */


//Get the saved register object with name "n"
Register getRegister(list<Register> regs, string n);

void printWelcomeText();

int main() {

    string fileName;
    list<Register> registers;
    ifstream inFile;   //inreader from file
    string line;
    regex ws_re("\\s+"); //used to split by whitespaces
    bool regExists = false;

    printWelcomeText();

    //allow user to pick a file
    cin >> fileName;

    inFile.open(fileName+".txt");

    if (!inFile)
    {
        cout << "Text file not found! :(" << endl;
        return 0;
    }


    if (inFile.is_open())
    {
        //get all them lines
        while (getline(inFile,line))
        {
            //make input case insensitive
            for(int i = 0; i < (int)line.length(); ++i) {
            line[i] = tolower(line[i]);
            }

            //split words in line by whitespace into vector
            std::vector<std::string> splittedLine{
            std::sregex_token_iterator(line.begin(), line.end(), ws_re, -1), {}};


            int wordCount = (int)splittedLine.size();

            //if the line contains a mathematical operation
            if(wordCount == 3){

                regExists = false;

                list<Register> :: iterator it;
                for(it = registers.begin(); it != registers.end(); ++it){
                    if(it->getName() == splittedLine.at(0)){
                        (*it).addOperation(splittedLine.at(1),splittedLine.at(2));
                        regExists = true;
                    }
                }

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
                    }
                    else cout << "Wrong input!";
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
}

//Static text information
void printWelcomeText(){

    cout << endl << "Hello, welcome to the simple calculator!";
    cout << endl << "______________________________________" << endl << endl;
    cout << "Feel free to import a file with a set of operations on each line." << endl;
    cout << "The lines can consist of: <register> <operation> <value>, print <register>, quit." << endl;
    cout << "possible operations: add, subtract or mulitply. Value can be a register or an integer." << endl;
    cout << "A register can have any alphanumerical name." << endl << endl;
    cout << ">> Please enter filename: ";
}
