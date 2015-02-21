/* File: dash.cpp
 * Program: dash - a specialized shell prompt
 * Author: Charles Parsons
 * Date: 2/6/2015
 * Professor: Dr. Karlsson
 * Course: CSC 456 - Operating Systems
 * Location: M306
 * Time: MWThF 2:00pm - 2:50pm
 * 
 * Description: This program emulates a shell prompt and allows for a limited
 * command set. The allowed commands are: cmdnm <pid>, pid <command>, systat,
 * and exit. The cmdnm <pid> command prints to the console the name of the
 * command that created the process with the id of pid. The pid <command>
 * prints to the console the pid's of all processes started by the named
 * command. The systat command prints cpu info, memory info, uptime, and
 * version info specific to the current computer on which it has been run.
 * The exit command exits the shell.
 * 
 * To do: Implement pid <command> command. This command currently does
 * nothing.
 */
#include "commands.h"

/* This function prints the dash prompt to the console, reads in the user
 * input, handles the exit command and <return> entries. When the command
 * entered is not empty or exit then it calls the interpretCommand function
 * and sends the command and arguments to be processed.
 * 
 */
int main(int argc, char* argv[])
{
    std::string command = "";
    
    //print dash prompt and read in user input
    std::cout << "dash> ";
    getline(std::cin, command);

    //while user input is not "exit", interpret commands
    while(command != "exit") 
    {
        if(command != "")
            interpretCommand(command);
        
        std::cout << "dash> ";
        getline(std::cin, command);    
    }
    
    return 0;
}