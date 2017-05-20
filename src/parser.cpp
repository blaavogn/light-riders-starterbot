#include "parser.h"

using namespace std;

Parser::Parser() {
  bot = Bot();
}

string Parser::NextCmd() {
  string k;
  getline(cmdLine, k, ' ');
  return k;
}

void Parser::Parse() {
  string line;
  for(string line; getline(cin, line); ){
    cmdLine.clear();
    cmdLine.str(line);
    // Process command
    string cmd = NextCmd();
    if      (cmd == "action")   ProcessAction();
    else if (cmd == "update")   ProcessUpdate();
    else if (cmd == "settings") ProcessSettings();
  }
}

void Parser::ProcessAction() {
  string cmd = NextCmd();
  if (cmd == "move") bot.Move(stoi(NextCmd()));
}

void Parser::ProcessUpdate() {
  NextCmd();
  string cmd = NextCmd();
  if      (cmd == "round") { bot.Round(stoi(NextCmd())); }
  else if (cmd == "field") { // Potentially replace with your own boardstate parser
    NextCmd();
    bool board[width*height];
    stringstream boardString(NextCmd());
    uint i = 0;
    uint pl1Pos = 0, pl2Pos = 0;
    for(string line; getline(cin, line); i++){
      board[i] = line != ".";
      if(line == "0") pl1Pos = i;
      if(line == "1") pl2Pos = i;
    }
    bot.Update(board, pl1Pos, pl2Pos);
  }
}

void Parser::ProcessSettings() {
  string cmd = NextCmd();
  if      (cmd == "timebank")      bot.Timebank(stoi(NextCmd()));
  else if (cmd == "time_per_move") bot.TimePerMove(stoi(NextCmd()));
  else if (cmd == "your_bot")      bot.YourBot(NextCmd());
  else if (cmd == "field_width")   { width  = stoi(NextCmd()); bot.FieldWidth(width);}
  else if (cmd == "field_height")  { height = stoi(NextCmd()); bot.FieldHeight(height);}
  else if (cmd == "player_names") {
    stringstream args(NextCmd());
    string player1, player2;
    getline(args, player1, ',');
    getline(args, player2, ',');
    bot.PlayerNames(player1,player1);}
}
