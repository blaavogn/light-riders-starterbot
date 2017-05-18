#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

class Parser
{
  public:
    void Parse();
  private:
    void ProcessCommand(queue<string> &cmd);
    void ProcessSettings(queue<string> &cmd);
};
