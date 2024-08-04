#include <iostream>
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#include <vector>
#include <random>
#include <algorithm>
#include <fstream>
#include "functions.h"

using namespace std;


int main () {
    std::cout << "This is the schedule maker " << std::endl;
    std::cout << "Would you like to create a new schedule or modify an old existing schedule?" <<std::endl;
    std::cout<< "1: Make the schedule" <<std::endl << "2: No, modify old schedule" <<std::endl << "3: quit" <<std::endl;
    std::cout << "(select the number you want then hit enter):  ";
    int input;
    std::cin >> input;
    
    if (input == 1 ){
        Staff NewStaff;
        NewStaff.makeStaff();
        NewStaff.algorithm(NewStaff.GetNames(), NewStaff.GetLevel(), NewStaff.can_work());
            // if there is people and people can work then what we need to do is run the algorithm
                /*
                    What I neeed to do:
                        Make this include ifstream and call upon on all the other functions so the main program is relativly cleaned up
                        create the schedule in a seperate text file and ideally read the values into an SFML default template
                        OR create the schedule in a seperate text file that will be organized to have everyone who is working along with how long they will work
                */
    
    
    }

    else if (input == 2){
        Staff NewStaff;
        std::ifstream FileIn;
        FileIn.open("AAC Schedule.txt");

        if(FileIn.fail()){
            cout << "You have not made a schedule yet so it cannot be ammended.";
            //break;
        }
        else{
            int choice;
            cout << "here is your current schedule, what would you like to change?" << endl;
            cout << "SOMEONE GOT FIRED (1)" << endl;
            cout << "Choice: ";
            cin >> choice;
            NewStaff.LoadOld(choice);
        }
            
        


    }
    else if (input == 3){
        cout << "Thank you for using the AAC schedule maker!" << endl;
        cout << "See yeah!" << endl;

    }
    else{
        cout<< "Input was wrong. Try running the program again." << endl;
    }
    
 return 0;


}

