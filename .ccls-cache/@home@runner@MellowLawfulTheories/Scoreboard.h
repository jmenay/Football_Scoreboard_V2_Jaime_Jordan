#include <iostream>
#include <iomanip>
#include "Team.h"
using namespace std;

class Scoreboard
{
  private:
    int half; 
    Team home; //object that is a member of another object
    Team visitor; 
  
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
    
    void showScoreboard()
    {
      string color = ""; 
      string reset = "\x1b[0m";
      color = "\x1b[37;7m"; //green 
      string colorHomeTeam = "\x1b[95;4m";
      string colorVisitorTeam = "\x1b[96;4m";
      string score = "\x1b[97;0m"; //score color 
      cout << color << "Soccer Scoreboard Dr_T Sytle" << reset << endl; 
      cout << colorHomeTeam << home.getName() << "\t" <<                colorVisitorTeam << visitor.getName() <<"\t"<<endl; 

cout << colorHomeTeam << home.getPlaceName() << "\t" <<                colorVisitorTeam << visitor.getPlaceName() <<"\t"<<endl;      
      cout<< score << home.getScore()<< "\t\t\t\t\t" << score << visitor.getScore() << "\t\t\t\t\t" << reset << endl; 
      
      cout << colorHomeTeam << home.getCoachName() << "\t" << colorVisitorTeam << visitor.getCoachName() << "\t" << endl; 
      
      for(int i = 0; i < 47; i++) { cout << reset << "*"; } cout << endl;
       
       //proces to show the home team status
       cout << "Home> \t"; 
       if(home.getHomeStatus() == true)
       {
         cout << "Team 1: " << home.getName() << "*"; 
       }
       else if(visitor.getHomeStatus() == true)
       {
         cout << "Team 2: " << visitor.getName() << "*"; 
       }
       else
       {
         cout << "Error: "; 
       }
       
       cout  << endl; 
    }
};
