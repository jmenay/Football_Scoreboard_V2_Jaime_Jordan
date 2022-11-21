//Origin = Dr. Tyson McMillan a Soccer Scoreboard using *Updates 4-21-2021, 04-07-2022 - Dr_T
//Dr_T teaching Object Oriented Scoreboard in C++ 

//First Modification created by Jaime Jordan and Kirsten Jordan in class pair partner Soccer Scoreboard project 

// Second Modification such as (color modifications, seperating classes into header files, including timeclock for scoreboard, additional user input changes and functionality, and various code edits) created by Jaime Jordan for COSC 1437 taught by Dr_T

// CMakeProject1.cpp : Defines the entry point for the application.

#include <unistd.h>

#include "main.h"

#include <iostream>

#include <string>

#include "Input_Validation_Extended.h"

#include "scoreboard.h"
#include "team.h"

#include <chrono>
#include <thread>

#include <iomanip>
#include <stdlib.h>

#include <pthread.h>
#include <stdio.h>

using namespace std;

static double currentMinutes = 0;
static double previousMinutes = 0;

static double clockCountdownMinutes = 15;

static int currentQuarter = 1;
static Scoreboard s;
static int refreshDisplay = 0;

static bool gameClockRunning = false;
// using chrono to obtain accurate time for scoreboard See https://www.geeksforgeeks.org/chrono-in-c/

static auto appStartTime = std::chrono::high_resolution_clock::now();
static bool GameClockStarted = false;
static int INT_MAX = 2147483647;

double mod(double x, double y) { return x - (int)(x / y) * y; }

void SleepX(int value) {
#if defined _WIN32
  Sleep(value);
#elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
  sleep(value / 1000); //conv to seconds
#endif
}

void Clear() {
#if defined _WIN32
  system("cls");
#elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
  system("clear");
#endif
}

void DoRefresh() {

  int qtr = std::floor(currentMinutes / clockCountdownMinutes);
  currentQuarter = qtr + 1;

  s.setQuarter(currentQuarter);

  if (currentQuarter > 4) {
    cout << "Football Game has FINISHED application will now terminate."
         << endl;
    exit(0); // exit application
  }

  // Example:
  // 15 clock count down minutes - ~9 minutes current minutes
  //= 6 remaining time as minutes
  s.setRemainingTime(((double)clockCountdownMinutes * (double)currentQuarter) -
                     (double)currentMinutes);
  s.setTotalGameTime(currentMinutes);

  Clear();

  s.showScoreboard();

  // menu choices
  s.ShowMenu();
}

// created a thread to run the clock See https://cplusplus.com/reference/thread/thread/
void monitorClock() {
  while (true) {
    // Sleep does NOT IMPACT actual game clock time (since we are using
    // [chrono::high_resolution_clock] for time tracking)
    SleepX(1000); // sleep for 1 second only impacts UI refreshing not game time
                  // timer/counter

    if (!gameClockRunning) {
      if (GameClockStarted) {
        auto appCurrentTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> ts = appCurrentTime - appStartTime;
        previousMinutes += ((double)ts.count() / (double)60);
        GameClockStarted = false;
      }
      continue;
    } else {
      if (!GameClockStarted) {
        appStartTime = std::chrono::high_resolution_clock::now();
        GameClockStarted = true;
      }
    }
    auto appCurrentTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> ts = appCurrentTime - appStartTime;
    // std::cout << ts.count() << "s\n";

    // Update seconds by seconds
    // Time is measured by 100th scale 1.5 = 90 seconds
    // Include any "previous minutes" that accumulated due start/stopping of the
    // clock.
    currentMinutes =
        ((double)ts.count() / (double)60) + (double)previousMinutes;

    refreshDisplay++;
    // Set this value from 1, 2, to 3, to 4, to 10 to "slow" down refresh rate.
    if (refreshDisplay >= 1) {
      DoRefresh();
      refreshDisplay = 0;
    }
  }
}

int main() {

  // created a thread to run the clock See https://cplusplus.com/reference/thread/thread/
  thread thClockMonitor(monitorClock);

  Team tOne;

  Team tTwo;

  string newName = "";

  string userChoice = "";

  string newCoachName = "";

  string newPlaceName = "";

  int homeTeamQuestion = 0;

  int newScore = 0;

  // Set the home team

  tOne.setHomeStatus(true); // tOne is the Home Team now

  // add some initial data to s

  s.setHome(tOne);

  s.setVisitor(tTwo);

  // Loop this to make it an interactive menu

  do {
    Clear();

    s.showScoreboard(); // show the current scoreboard data

    // menu choices
    s.ShowMenu();

    cin >> userChoice;

    if (userChoice == "A" || userChoice == "a")

    {

      cout << "\nUpdate Home Name Module****" << endl;

      cout << "\nPlease enter a new name of the home team: ";

      cin >> newName; // change that home team's default name

      tOne.setName(newName); // set tOne's data to the new desired name

    }

    else if (userChoice == "B" || userChoice == "b")

    {

      cout << "\nUpdate Home Score Module****" << endl;

      cout << "\nPlease enter a new score for the home team: ";

      cin >> newScore;
      if (cin.fail()) // to validate integer
      {
        cout << "ERROR - numeric required: Example 20, 5, 45" << endl;
        cin.clear(); 
        cin.ignore(INT_MAX, '\n');
        SleepX(5000);
        continue;
      }
      tOne.setScore(newScore); // set the new score for tOne

    }

    else if (userChoice == "C" || userChoice == "c")

    {

      cout << "\nUpdate Home Team Coach Module****" << endl;

      cout << "\nPlease enter the name of the home team coach: ";

      cin >> newCoachName;

      tOne.setCoachName(newCoachName);

    }

    else if (userChoice == "D" || userChoice == "d")

    {

      cout << "\nUpdate Home Team Place Module****" << endl;

      cout << "\nPlease enter the city of the home team: "; // place Name

      cin >> newPlaceName;

      tOne.setPlaceName(newPlaceName);

    }

    else if (userChoice == "E" || userChoice == "e")

    {

      cout << "\nUpdate Vistor Team Name Module****" << endl;

      cout << "\nPlease enter a new name for the visitor team: ";

      cin >> newName; // change the visiting team's default name

      tTwo.setName(newName); // set tTwo's data to the new desired name

    }

    else if (userChoice == "F" || userChoice == "f")

    {

      cout << "****Update Visitor Team Score module*** " << endl;

      cout << "\nPlease enter a new score for the visitor team: ";

      cin >> newScore;
      if (cin.fail()) // to validate integer
      {
        cout << "ERROR - numeric required: Example 20, 5, 45" << endl;
        cin.clear(); 
        cin.ignore(INT_MAX, '\n');
        SleepX(5000);
        continue;
      }
      tTwo.setScore(newScore); // set the new score for tTwo

    }

    else if (userChoice == "G" || userChoice == "g")

    {

      cout << "\nUpdate Visitor Coach Module****" << endl;

      cout << "\nPlease enter the name of the visitor team's coach: ";

      cin >> newCoachName;

      tTwo.setCoachName(newCoachName);

    }

    else if (userChoice == "H" || userChoice == "h")

    {

      cout << "\nUpdate Visiting Place Module****" << endl;

      cout << "\nPlease enter the Visiting place Name: ";

      cin >> newPlaceName;

      tTwo.setPlaceName(newPlaceName);

    }

    else if (userChoice == "U" || userChoice == "u") {

      cout << "\nUpdate Home Team Status Module****" << endl;

      cout << "\nWho is the home team: 1 = T1, 2 = T2";

      // homeTeamQuestion = validateInt(homeTeamQuestion);

      cin >> homeTeamQuestion;

      if (homeTeamQuestion == 1)

      {

        tOne.setHomeStatus(true);

        tTwo.setHomeStatus(false);
      }

      if (homeTeamQuestion == 2) {

        tOne.setHomeStatus(false);

        tTwo.setHomeStatus(true);
      } else {
        cout << "\nInvalid Input!" << endl;
        SleepX(2);
      }
    }
    // Refresh Scoreboard
    else if (userChoice == "R" || userChoice == "r") {
      cout << "Refresh Scoreboard chosen." << endl;
      DoRefresh();
    }

      
#pragma region GameTimer //pragma region is used for code grouping to make the code look pretty
    else if (userChoice == "V" || userChoice == "v") 
    {
      cout << "Set Game Clock chosen." << endl;
      cout << "Example High School Game Clock = [12] minutes" << endl;
      cout << "Example College Game Clock = [15] minutes" << endl;
      cout << "Decimal place supported [5.5] (represents 5 1/2 minutes)"
           << endl;
      cout << "\nPlease enter the Game Clock [quarter] as minutes:";

      cin >> clockCountdownMinutes;
      if (cin.fail()) // to validate integer
      {
        cout << "ERROR - numeric/decimal required: Example 20, 5.5, 45" << endl;
        cin.clear(); 
        cin.ignore(INT_MAX, '\n');
        SleepX(5000);
        continue;
      }

      // TODO: {Consideration} We could instead offer another entry type
      //[5.5] (represents 5 1/2 minutes)
      //--OR POTENTIALLY--
      //[05:30] (represents 5 1/2 minutes) notice the ':' this would indicate a
      // TIME FORMAT based entry This would involve a more elborate cin
      // validation routine and converting from 'time' to 'decimal' At the
      // moment we will just settle for decimal input such as 5.5 for 5 and 1/2
      // minutes.

      // MAKING AN ASSUMATION TO ALSO RESET CLOCK TOO WHEN CLOCK TIMER CHANGED.
      currentMinutes = 0;
      // set back to original assigned clockMinutes value (aka 15/12)
      s.setRemainingTime(clockCountdownMinutes);
      s.setTotalGameTime(currentMinutes);

      // Should we set the quarter back to 1 upon resetting of the clock?
      // Or should we keep the current quarter active (I'm assuming reset
      // quarter too).
      s.setQuarter(1);

    } else if (userChoice == "W" || userChoice == "w") {
      cout << "Start Game Clock chosen." << endl;
      cout << "\nGame Clock has been started";

      gameClockRunning = true;
    } else if (userChoice == "X" || userChoice == "x") {
      cout << "Stop Game Clock chosen." << endl;
      cout << "\nGame Clock has been stopped";

      gameClockRunning = false;
    } else if (userChoice == "Y" || userChoice == "y") {
      currentMinutes = 0;

      // set back to original assigned clockMinutes value (aka 15/12)
      s.setRemainingTime(clockCountdownMinutes);
      s.setTotalGameTime(currentMinutes);

      // Should we set the quarter back to 1 upon resetting of the clock?
      // Or should we keep the current quarter active (I'm assuming reset
      // quarter too).
      s.setQuarter(1);

      cout << "Reset Game Clock chosen." << endl;
      cout << "\nGame Clock has been reset";
    }
#pragma endregion GameTimer
    else if (userChoice == "Z" || userChoice == "z") {

      cout << "Exit chosen." << endl;

    }

    else // invalid input: default clause

    {

      cout << "\nInvalid input." << endl;

      SleepX(2); // wait two seconds, go to the next process
    }

    s.setHome(tOne); // refresh the data in s to the new updates...

    s.setVisitor(tTwo); // refresh the data
  } while (userChoice != "Z" && userChoice != "z");

  return 0;
}

