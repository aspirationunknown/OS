/* File: commands.h
 * Author: Charles Parsons
 * Date: 2/21/2015
 * 
 * Description: This header file is for commands.cpp.
 * 
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>

void commandName(int pid);
void errorMessage();
void interpretCommand(std::string cmd);
std::string itoa(int num);
void procIds(std::string cmd);
void systemStats();

