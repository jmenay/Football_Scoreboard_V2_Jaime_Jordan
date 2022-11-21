
#pragma once 

#include <iostream> 

#include <string>  

//#include <unistd.h> 

//#include "Input_Validation_Extended.h" 

using namespace std;



class Team

{

private:

    int score;

    bool homeStatus;

    string name;

    int shotsOnGoal;

    string coachName;

    string placeName;

    //string teamCityName; 

public:

    Team() //default constructor  

    {

        score = 0;

        homeStatus = false; //visitor = false, home = true 

        name = "Default Team Name";

        shotsOnGoal = 0;

        coachName = "Default Coach Name";

        placeName = "Default Place Name";

        //teamCityName = "DefaultCityName"; 

    }

    void setScore(int s) { score = s; }

    void setHomeStatus(bool hs) { homeStatus = hs; }

    void setName(string n) { name = n; }

    void setShotsOnGoal(int sog) { shotsOnGoal = sog; }

    void setCoachName(string sCN) { coachName = sCN; }

    void setPlaceName(string sPN) { placeName = sPN; }

    int getScore() const { return score; }

    bool getHomeStatus() const { return homeStatus; }

    string getName() const { return name; }

    int getShotsOnGoal() const { return shotsOnGoal; }

    string getCoachName() const { return coachName; }

    string getPlaceName() const { return placeName; }

};



