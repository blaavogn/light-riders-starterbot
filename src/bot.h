#pragma once

#include <stdio.h>

using namespace std;

class Bot {
  public:
    // Action
    virtual void Move(uint time) { printf("move: %d\n", time); };

    // Update
    virtual void Round(uint time) { printf("round: %d\n", time); };
    virtual void Update(bool *board, uint pl1pos, uint pl2pos) {
      printf("Update: %d\n", pl1pos);
    };

    // Settings
    virtual void Timebank(uint time) { printf("timebank: %d\n", time); };
    virtual void TimePerMove(uint time) { printf("time_per_move: %d\n", time); };
    virtual void YourBot(string name) { printf("your name: %s\n", name.c_str()); };
    virtual void FieldWidth(uint width) { printf("Field Width: %d\n", width); };
    virtual void FieldHeight(uint height) { printf("Field Height: %d\n", height); };
    virtual void PlayerNames(string player1, string player2) {
      printf("player: %s,%s\n", player1.c_str(), player2.c_str());
    }
};
