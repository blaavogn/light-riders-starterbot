#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <queue>

#include "bot.h"

using namespace std;

class Parser {
  public:
    Parser();
    void Parse();
  private:
    uint width = 0;
    uint height = 0;
    Bot bot;
    void ProcessCommand();
    void ProcessAction();
    void ProcessUpdate();
    void ProcessSettings();
    string NextCmd();
    stringstream cmdLine;
};
