#include "parser.h"

using namespace std;

void Parser::Parse() {
  for(string line; getline(cin, line); ){
    std::stringstream lineStream(line);
    queue<string> cmds;
    for(string word; getline(lineStream, word, ' ');)
      cmds.push(word);
    // Process command
    if(cmds.empty()) continue;

    string cmd = cmds.front();
    cmds.pop();
    if (cmd == "settings") ProcessSettings(cmds);
    else cout << "Unkown Command" << endl;
  }
}

void Parser::ProcessSettings(queue<string> &cmds){
  if(cmds.empty())
    return;
  string cmd = cmds.front();
  cmds.pop();
  if (cmd == "settings")
    ProcessSettings(cmds);
  else
    cout << "Unkown Command" << endl;
}


