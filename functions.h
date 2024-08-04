#ifndef  FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;


class Staff { 
    public:
        Staff();

        std::vector<int> can_work();
        
        std::vector<std::string> GetNames();
        
        std::ifstream LoadOld(int choice);

        ofstream algorithm(std::vector<std::string> StaffNames, std::vector<int> StaffLevel, std::vector<int> totalhours); // creates a randomly assinged schedule based on constraints

            // says the days staff can work
            // default is everyday but can later be modifed
        
        void makeStaff(); // need to trim this down can break it up into multiple functions

        bool OpeningJobs(std::vector<std::string> StaffPicked); // ensure that closing jobs can be done
        bool ClosingJobs(std::vector<std::string> StaffPicked);
        std::vector<int> GetLevel();


    private:
        std::vector<std::string> StaffNames;
        std::vector<int> StafflevelList;
        std::vector<int> totalHours;



};





#endif