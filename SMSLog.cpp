//Header files
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Function prototype
bool senderFilter(char* logFileName, char* resultFileName, const char* sender);

int main() {

        char logFileName[80]; //Create char array for logFileName
        char resultFileName[80]; ///Create char array for resultFileName
        char sender[12]; //Create char array for senders number
        bool ok = true; //Boolean variable to check if files are created without issues 

        //Copy texts and sender phone number to char array
        strcpy(logFileName, "smslog_eng.txt");
        strcpy(resultFileName, "result.txt");
        strcpy(sender, "0703-124566");

        //Check if files are created with issues
        ok = senderFilter(logFileName, resultFileName, sender);

        //Error message if files arent created 
        if (!ok) {
                cout << "File could not be created.";
        }

        return 0;
}

//Function filters out all message from senders phone number
bool senderFilter(char* logFileName, char* resultFileName, const char* sender) {

        //Variables 
        char ch;
        string line;
        string process;

        //Create log file
        ifstream infile(logFileName);
        if (!infile.is_open()) {
                return false;
        }

        //Create result file 
        ofstream outfile(resultFileName);
        if (!outfile.is_open()) {
                return false;
        }

        //Loop and go through log file 
        while (getline(infile, line)) {

                char* ch = const_cast<char*>(line.c_str()); //Convert string of numbers to char 

                //Check if next number is senders number, if it is loop to sent message and add to outfile
                //Otherwsie loop to next phone number and compare again 
                if (strcmp(ch, sender) == 0) {
                        for (int i = 0; i < 3; i++) {
                                getline(infile, process);
                        }
                        outfile << process;
                        outfile << endl;
                }
                else {
                        for (int i = 0; i < 3; i++) {
                                getline(infile, process);
                        }
                }
        }
        infile.close();
        outfile.close();
        return true;
}




