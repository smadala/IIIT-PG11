#ifndef YSHELL_H
#define YSHELL_H
#include<vector>
#include<string>
using namespace::std;
extern vector<string> history;
vector<char**> parseCommand(string cmd);// parses include pipe
void parsecmd(string cmd, char** argv);// removes spaces and tabs from command argv
int loadHistory();
void dumpHistory(int numHistory);
int inBuiltCmd(char *cmd);
int handleBuiltIn(char **argv,int inBuilt);
int processCmd(string input);
void importRC();
int cd(char **a);
int echo(char **a);
int exp(char **a);
int execHistory(int num);
int displayHistory();
#endif
