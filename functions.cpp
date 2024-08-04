#include <iostream>
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#include <vector>
#include <random>
#include <algorithm>
#include <fstream>
#include <string>
#include <cmath>
#include "functions.h"
#include <typeinfo>


using namespace std;



Staff::Staff(){

    //The initial values??? 

    // come back to this

}

std::vector<int> Staff::can_work(){
    //std::vector<int> totalHours;
    for(int i = 0; i < StaffNames.size(); i++){
        int hours = 40;
        //cout << "How many hours can " << StaffNames.at(i) << " work? (max is 42): ";
        //cin >> hours;
        
        totalHours.push_back(hours);
    }
    return totalHours;

}

void Staff::makeStaff(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int NumOfStaff;
    SetConsoleTextAttribute(hConsole, 10);

    std::cout << "################################################################################################################################################################################################################################" << endl;
    std::cout << "To start out we will begin by asking you a few questions regrading your staff, once answered this program will build a rough scheudle for you to follow." <<std::endl;
    std::cout << "How many staff members will be working this weekly period? " <<std::endl;
    std::cout << "Number of staff this week (minimum is 8, can handle more than 14 but do not reccomend): ";
    std::cin >> NumOfStaff;
    while(NumOfStaff < 8){
         
        cout << "The minimun amount of staff is 8 not " << NumOfStaff << endl << " Try again: ";
        cin >> NumOfStaff;
      

       }
       std::string names;
       int staffLevel;


       for(int i = 0; i < NumOfStaff; i++){
            SetConsoleTextAttribute(hConsole, i+2);
            std::cout <<std::endl << "Enter the Name of the each staff member: ";
            std::cin >> names;
            StaffNames.push_back(names);
            
            std::cout << std::endl << "What level of mangement are they: " << std::endl;
            std::cout << std::endl << "Non- leadership position (1)" << std::endl;
            std::cout << std::endl <<  "Leadership Male (2) (this means they can take chemicals)" << std::endl;
            std::cout << std::endl << "Leadership Female (3) (Can set up the front desk and office)" << std::endl;
            std::cout << "Level: ";
            while(staffLevel != 1 && staffLevel != 2 && staffLevel != 3){
                cout << "Input 1 2 or 3." << staffLevel << endl;
                cout << "Input: ";
                std::cin >>  staffLevel;
                staffLevel = abs(staffLevel);
            
            }
            StafflevelList.push_back(staffLevel);
            staffLevel = 0;
        }

}


std::vector<std::string> Staff::GetNames(){

    return StaffNames;

}


std::vector<int> Staff::GetLevel(){

    return StafflevelList;
    
}

ofstream Staff::algorithm(std::vector<std::string> Staff_Names, std::vector<int> Staff_Level, std::vector<int> totalHours)

{
 
 /*
    This is the main heart of the code, needs to go through everyone and randomly assing a day they will be on and pick them 6 times so that they are off 2 times.
    For each group of people picked it checks if opening Jobs can be done and then write it to a file.
    until each person worked the amount they needed to and opening and closing jobs can be done.
 */

        int days = 0;
        int max = StaffNames.size();
        int counter =0;
        while(days != 7){
            bool conditions_passed = false;
            std::vector<std::string> picked;    
            int attempt = 1;
            
            while(!conditions_passed) // picks the amount of people needed to be off so that only 8 people work a day.
            {  
                int person_selected = (rand() % max); // randomly picks a person within the range of the indexs of the list  
                
                /*if (counter == 164)// since there is a poteitnal involved in chance, after 64 attempts simply end the program
                {
                    //cout << "The current algorithm couldn't create a schedule with your conditions.";
                    conditions_passed = true;
                    std::ofstream MyFile;
                    MyFile.open("AAC Schedule.txt");
                    MyFile << "Your staff cannot run the pool, there isn't enough mangement. " << endl;
                    MyFile.close();
                    days = 7;
                    //exit();
                    //return;
                    break;
                }
            */
                if( std::find(picked.begin(), picked.end(), StaffNames.at(person_selected)) == picked.end()) // they aren't in the list
                    {
                        //cout << picked.size();
                       // cout << " " << StaffNames.at(person_selected) << " " << endl;

                        picked.push_back(StaffNames.at(person_selected)); // add them to list

                    }
                if (picked.size() <= (8)){
                    counter +=1;
                    //cout << " not yet" << endl;

                }
                if (picked.size() >= (8)) // This means we have picked the schedule for one day. Now to ensure that it works and start the loop over
                    {
                    if(OpeningJobs(picked) == true && ClosingJobs(picked) == true){
                        //the schedule works
                        conditions_passed = true;
                        //Everyone who was picked for one day should have 8 hours subtracted.
                        std::ofstream MyFile;
                        MyFile.open("AAC Schedule.txt", std::ios_base::app);
                        MyFile << "Staff for the day ";
                        for (std::string i: picked){
                             MyFile << i << " ";
                        }
                        MyFile << endl;   

                         MyFile.close();
                         std::vector<std::string> picked;
                    }


                    else{
                        attempt +=1;
                        for(unsigned int i = 0; i < picked.size(); i++){
                            picked.erase(picked.begin());
                        }

                        if(attempt == 2){
                            std::ofstream MyFile;
                            MyFile.open("AAC Schedule.txt");
                            MyFile << "Your staff cannot run the pool, there isn't enough mangement. The rest of the code is the best effort of the system" << endl;
                            for (std::string i: picked){
                                MyFile << i << " ";
                                }   

                            MyFile.close();
                            std::vector<std::string> picked;
                            conditions_passed = true; // even though it's not true this breaks the loop because it's simply not possible to make the staff.
                        }     
                        }
                    }

                        
                    
                    
                    }
                    
                     // Create and open a text file
                  
                
            days+=1;
                
            
      
      
           

        }





}

    

ifstream Staff::LoadOld(int choice){
    std::ifstream Infile;
    Infile.open("AAC Schedule.txt");
    std::string Names;
    std::string ProperName;
    
        if (choice == 1) // This means someone got fired and must be removed 
        {
            std::vector<std::string> notFired;
            cout << "Type the name of the person who got fired." << endl;
            cin >> ProperName;// fired person :(
            std::ofstream MyFile;
            MyFile.open("AAC Schedule New.txt");
            while(!Infile.eof()){
                Infile >> Names;
               
                if (Names != ProperName) // if they weren't fired then add them again.
                {
                
               
                    if(Names == "Staff"){
                        MyFile << endl;
                    }
                     MyFile << Names << " ";
                //cout <<  Names << " ";
                //notFired.push_back(Names);
                }
            }
            MyFile.close();
            
        }



}

bool Staff::OpeningJobs(std::vector<std::string> StaffPicked)  // ensure that closing jobs can be done
{
    // ensure that of the people picked there is at least 1 girl who can set up front desk and one guy who can broom
    bool guy_hoser = false;
    bool girl_Hoser = false;
    for(unsigned int i =0; i < StaffPicked.size(); i++){

        //find what index they exist at in Staff Name
        auto it = find(StaffNames.begin(), StaffNames.end(), StaffPicked.at(i));
        if(it != StaffNames.end()){
            int index = it -StaffNames.begin();
            if(StafflevelList.at(index) == 2){
                //This means there is a guy hoser
                guy_hoser = true;
            }
            if (StafflevelList.at(index) == 3){
                girl_Hoser = true;
                // this means there is a girl who Can Hose
            }
            
        }

        if (guy_hoser && girl_Hoser){
            return true;
        }


    }

    return false;

}


bool Staff::ClosingJobs(std::vector<std::string> StaffPicked){
    // ensure that of the people picked there is at least 1 girl who can set up front desk and one guy who can broom
    int condition = 0;
    int conditionTwo = false;


    for(unsigned int i = 0; i < StaffPicked.size(); i++){

        //find what index they exist at in Staff Name
        auto it = find(StaffNames.begin(), StaffNames.end(), StaffPicked.at(i));
        
        if(it != StaffNames.end()){
            int index = it -StaffNames.begin();
            if(StafflevelList.at(index) == 2){
                //This means there is a guy hoser
                condition +=1;
                //guy_hoser = true;
            }
            if (StafflevelList.at(index) == 3){
                conditionTwo = true;
                //girl_Hoser = true;
                // this means there is a girl who Can Hose
            }
            
        }

        if (condition >1 && conditionTwo == true) {
            //This means theres enough staff to close that is in mangement
            //This is because two guys are needed to hose so one can hose the deck and someone with hosing ablity
            // can also clean grills so this is saftey net to ensure that the pool can close down.
            return true;
        }

       

    }


    return false;

}


ifstream LoadOld(){

}
