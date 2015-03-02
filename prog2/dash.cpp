/* File: dash.cpp
 * Program: dash - a specialized shell prompt, improved edition
 * Author: Charles Parsons
 * Date: 3/1/2015
 * Professor: Dr. Karlsson
 * Course: CSC 456 - Operating Systems
 * Location: M306
 * Time: MWThF 2:00pm - 2:50pm
 * 
 * Description: This program emulates a shell prompt. It allows for most of the
 * common shell commands, including but not limited to: cndnm, systat, cd, 
 * gcc/g++, ls, and piping. These commands perform as they are expected to 
 * perform in a normal shell prompt. This program uses fork to created child 
 * processes and execvp to call the functions to be run in those child 
 * processes. 
 * 
 * To do: redirects, signals, pid
 * 
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