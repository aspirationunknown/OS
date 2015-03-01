/* File: commands.h
 * Author: Charles Parsons
 * Date: 2/21/2015
 * 
 * Description: This header file is for commands.cpp.
 * 
 */

#include <cstdlib>
#include <cstring>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>

void commandName(int pid);
void errorMessage();
void interpretCommand(std::string cmd);
std::string itoa(int num);
//void parseCommand(std::string source, char* destination[100]);
void parsePipedCommand(std::string cmd, std::string &input, std::string &output);
void pipedCommand(std::string cmd);
void procIds(std::string cmd);
void systemStats();

