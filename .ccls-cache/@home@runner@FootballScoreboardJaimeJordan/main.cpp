//Dr. Tyson McMillan a Soccer Scoreboard using 
//This was created by: Jaime Jordan and Kirsten Jordan in class pair partner project 
//Object Oriented Programming in C++
//Updates 4-21-2021, 04-07-2022 - Dr_T
//Dr_T teaching Object Oriented Scoreboard in C++ 
//This was created by: Jaime Jordan and Kirsten Jordan
// Expanded by: Jaime Jordan for COSC 1437 taught by Dr_T

#include <iostream>
#include <string> 
#include <unistd.h>
#include "Input_Validation_Extended.h"
#include "Team.h" 
#include "Scoreboard.h"

using namespace std; 

int main() 
{
  Scoreboard s;
  Team tOne;
  Team tTwo; 

  string newName = ""; 
  string userChoice = ""; 
  string newCoachName = "";
  string newPlaceName = "";
  int homeTeamQuestion = 0; 
  int newScore = 0; 

  //Set the home team 
  tOne.setHomeStatus(true); //tOne is the Home Team now   

  //add some initial data to s
  s.setHome(tOne); 
  s.setVisitor(tTwo); 
  
  
  //Loop this to make it an interactive menu

  do 
  {
    system("clear"); //clear the screen of previous content 
    s.showScoreboard(); //show the current scoreboard data
    //menu choices 
    cout << "A = Update Home Team Name" << endl; 
    cout << "B = Update Home Team Score" << endl;
    cout << "C = Update Home Team Coach" << endl; 
    cout << "D = Update Home Team Place" << endl;
    
    cout << "E = Update Visitor Team Name" << endl;
    cout << "F = Update Visitor Team Score" << endl;
    cout << "G = Update Visitor Team Coach" << endl;
    cout << "H = Update Visitor Team Place" << endl;
    
    cout << "U = Update Home Team Status" << endl;
  
    cout << "Z = Exit" << endl;
    cout << ">"; 
    cin >> userChoice; 

    if(userChoice == "A" || userChoice == "a")
    {
      cout << "\nUpdate Home Name Module****" << endl;
      
      cout << "\nPlease enter a new name of the home team: ";
      cin >> newName; //change that home team's default name
      tOne.setName(newName); //set tOne's data to the new desired name
    }
    else if(userChoice == "B" || userChoice == "b")
    {
      cout << "\nUpdate Home Score Module****" << endl; 
      
      cout << "\nPlease enter a new score for the home team: "; 
      cin >> newScore; 
      tOne.setScore(newScore);  //set the new score for tOne        
    }

    else if(userChoice == "C" || userChoice == "c")
    {
      cout << "\nUpdate Home Team Coach Module****" << endl; 
        
      cout << "\nPlease enter the name of the home team coach: "; 
      cin >> newCoachName; 
      tOne.setCoachName(newCoachName); 
    }
  
    else if(userChoice == "D" || userChoice == "d")
    {
      cout << "\nUpdate Home Team Place Module****" << endl; 
          
      cout << "\nPlease enter the city of the home team: ";//place Name
      cin >> newPlaceName; 
      tOne.setPlaceName(newPlaceName); 
    }
    
    else if(userChoice == "E" || userChoice == "e")
    {
      cout << "\nUpdate Vistor Team Name Module****" << endl;
        
      cout << "\nPlease enter a new name for the visitor team: ";
      cin >> newName; //change the visiting team's default name
      tTwo.setName(newName); //set tTwo's data to the new desired name   
    }
    
    else if(userChoice == "F" || userChoice == "f")
    {
      cout << "****Update Visitor Team Score module*** " << endl; 
    
      cout << "\nPlease enter a new score for the visitor team: "; 
      cin >> newScore; 
      tTwo.setScore(newScore);  //set the new score for tTwo
    }    
   
    else if(userChoice == "G" || userChoice == "g")
    {
      cout << "\nUpdate Visitor Coach Module****" << endl; 
          
      cout << "\nPlease enter the name of the visitor team's coach: "; 
      cin >> newCoachName; 
      tTwo.setCoachName(newCoachName); 
    }  
      
    else if(userChoice == "H" || userChoice == "h")
    {
      cout << "\nUpdate Visiting Place Module****" << endl; 
      
      cout << "\nPlease enter the Visiting place Name: "; 
      cin >> newPlaceName; 
      tTwo.setPlaceName(newPlaceName); 
    }
    else if(userChoice == "U" || userChoice == "u")
    {
      cout << "\nUpdate Home Team Status Module****" << endl; 
      cout << "\nWho is the home team: 1 = T1, 2 = T2"; 
      homeTeamQuestion = validateInt(homeTeamQuestion); 
      cin >> homeTeamQuestion; 
      
      if(homeTeamQuestion == 1)
      {
        tOne.setHomeStatus(true); 
        tTwo.setHomeStatus(false);
      }
        
      if(homeTeamQuestion == 2)
      {
        tOne.setHomeStatus(false); 
        tTwo.setHomeStatus(true);
      }

      else
      {
        cout << "\nInvalid Input!" << endl;
        sleep(2); 
      }    
    }      
    
    else if(userChoice == "Z" || userChoice == "z")
    {
      cout << "Exit chosen." << endl; 
    }
    
    else //invalid input: default clause
    {
      cout << "\nInvalid input." << endl; 
      sleep(2); //wait two seconds, go to the next process 
    }

    s.setHome(tOne); //refresh the data in s to the new updates...
    s.setVisitor(tTwo); //refresh the data
      
  
  }
    while(userChoice != "Z" && userChoice != "z");


  return 0; 
}
