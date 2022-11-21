#include <iostream> 

#include <iomanip> 

#include "team.h" 

#include <unistd.h>

#include <iostream>
#include <cmath>

//turning on Floating Point (large double math functions used for time incluing rounding modulus multiplication division)
//https://cplusplus.com/reference/cfenv/FENV_ACCESS/
#pragma STDC FENV_ACCESS ON


using namespace std;



class Scoreboard

{

private:

    int half;

    Team home; //object that is a member of another object 

    Team visitor;

    int currentQuarter = 1;
    double remainingTime = 15;
    double totalGameTime = 0;


public:

    Scoreboard()
    {
        half = 0;
    }

    void setHalf(int h) { half = h; }

    void setHome(Team hSet) { home = hSet; }

    void setVisitor(Team vSet) { visitor = vSet; }

    int getHalf() const { return half; }

    Team getHome() const { return home; }

    Team getVisitor() const { return visitor; }


    void setQuarter(int quarter) { currentQuarter = quarter; }

    void setRemainingTime(double minutes) { remainingTime = minutes; }
    void setTotalGameTime(double minutes) { totalGameTime = minutes; }


    double mod(double x, double y) {
        return x - (int)(x / y) * y;
    }

    void ShowMenu()
    {
        cout << "A = Update Home Team Name" << endl;

        cout << "B = Update Home Team Score" << endl;

        cout << "C = Update Home Team Coach" << endl;

        cout << "D = Update Home Team Place" << endl;

        cout << "E = Update Visitor Team Name" << endl;

        cout << "F = Update Visitor Team Score" << endl;

        cout << "G = Update Visitor Team Coach" << endl;

        cout << "H = Update Visitor Team Place" << endl;

        cout << "R = Refresh Scoreboard (manual)" << endl;

        cout << "U = Update Home Team Status" << endl;

        cout << "V = Game Clock Set" << endl;
        cout << "W = Game Clock Start" << endl;
        cout << "X = Game Clock Stop" << endl;
        cout << "Y = Game Clock Reset" << endl;


        cout << "Z = Exit" << endl;

        cout << ">";
    }

    void showScoreboard()

    {

        string color = "";

        string reset = "\x1b[0m";

        color = "\x1b[37;7m"; //green  

        string colorHomeTeam = "\x1b[95;4m";

        string colorVisitorTeam = "\x1b[96;4m";

        string score = "\x1b[97;0m"; //score color  

        cout << color << "Football Scoreboard Dr_T Sytle" << reset << endl;

        double timeRemainSeconds = std::round(mod(remainingTime,1) * 60.0); //Modulus (Remainder)
        double timeRemainMinutes = std::floor(remainingTime);

        cout << setfill(' ') << setw(15) << "QUARTER " << currentQuarter << reset << endl;
        cout << setfill(' ') << setw(0) << "----QUARTER REMAINING--------\n";
        cout << setfill('0') << setw(0) << "--  " << timeRemainMinutes << " min | ";
        cout << setfill('0') << setw(2) << timeRemainSeconds << " sec" << " --" << endl;
        cout << setfill(' ') << setw(0) << "-----------------------------\n";

        if (currentQuarter > 4)
            cout << setfill(' ') << setw(0) << "-------[OVERTIME ACTIVATED]------------\n";

        double totalGameTimeSeconds = std::round(mod(totalGameTime, 1) * 60.0); //Modulus (Remainder)
        double totalGameTimeMinutes = std::floor(totalGameTime);
        cout << setfill(' ') << setw(0) << "----TOTAL GAME TIME----------\n";
        cout << setfill('0') << setw(0) << "--  " << totalGameTimeMinutes << " min | ";
        cout << setfill('0') << setw(2) << totalGameTimeSeconds << " sec" << " --" << endl;
        cout << setfill(' ') << setw(0) << "-----------------------------\n";

        cout << colorHomeTeam << home.getName() << "\t" << colorVisitorTeam << visitor.getName() << "\t" << endl;



        cout << colorHomeTeam << home.getPlaceName() << "\t" << colorVisitorTeam << visitor.getPlaceName() << "\t" << endl;

        cout << score << home.getScore() << "\t\t\t\t\t" << score << visitor.getScore() << "\t\t\t\t\t" << reset << endl;



        cout << colorHomeTeam << home.getCoachName() << "\t" << colorVisitorTeam << visitor.getCoachName() << "\t" << endl;



        for (int i = 0; i < 47; i++) { cout << reset << "*"; } cout << endl;



        //proces to show the home team status 

        cout << "Home> \t";

        if (home.getHomeStatus() == true)

        {

            cout << "Team 1: " << home.getName() << "*";

        }

        else if (visitor.getHomeStatus() == true)

        {

            cout << "Team 2: " << visitor.getName() << "*";

        }

        else

        {

            cout << "Error: ";

        }



        cout << endl;

    }

};









