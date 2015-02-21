/* File: commands.cpp
 * Author: Charles Parsons
 * Date: 2/21/2015
 * 
 * Description: This file holds all of the functions for interpreting commands
 * and executing commands.
 *
 */ 
#include "commands.h"
/*takes in the raw command string from the command line and calls the appropriate
 * function. If no functions are matched then it is passed to the error message
 * function.*/
void interpretCommand(std::string cmd)
{
    int pid;
    
    //try parsing cmd using strtok function to get command and arguments
    //separated.
    
    pid = fork();
    //fork returns 0 in the child process and the pid of the child process
    //in the parent process.
    if(pid == 0)
    {
        //have child process perform command using cmd string
        //redirect child process's I/O to parent process
        
    }
    /*
    std::string command = "";
    std::size_t index;
    bool is_single_command = false;
    int pid = 0;
    
    //parse command
    index = cmd.find_first_of(" \t");
    
    if(index != std::string::npos)
    {
        command = cmd.substr(0, index);
        cmd = cmd.substr(index + 1);
    }
    else
    {
        command = cmd;
        is_single_command = true;
    }
    
    //check for cmdnm <pid> command
    if(is_single_command == false && command == "cmdnm")
    {
        index = cmd.find_first_of(" \t");
        if(index == std::string::npos && isdigit(cmd[0]))
        {
            //get pid number
            pid = atoi(cmd.c_str());
        }
        else
        {
            cmd = cmd.substr(0, index);
            if(isdigit(cmd[0]))
            {
                //get pid number
                pid = atoi(cmd.c_str());
            }
            else
            {
                //invalid command
                errorMessage();
                return;
            }
        }
        
        commandName(pid);
    }
    //check for pid <command>
    else if(is_single_command == false && command == "pid")
    {
        
    }
    //check for systat
    else if(is_single_command == true && command == "systat")
    {
        systemStats();
    }
    //handle all other errors
    else
    {
        errorMessage();
    }
    */
    
}

/* Deals with the cmdnm <pid> command by printing the name of the
 * command that created that process.*/
void commandName(int pid)
{
    std::string location = "/proc/" + itoa(pid) + "/cmdline";
    std::string temp = "";
    std::ifstream fin(location);
    
    fin >> temp;
    
    std::cout << temp << std::endl;
    
    fin.close();
}

/*Deals with the pid <command> command*/
void procIds(std::string cmd)
{
    
}

/*Deals with the systat command. Prints cpu info, memory info, uptime,
  and version info.*/
void systemStats()
{
    std::ifstream fin;
    int i;
    std::string location = "";
    std::string line = "";
    
    //start with cpuinfo
    location = "/proc/cpuinfo";
    fin.open(location);
    for(i = 0; i < 9; ++i)
    {
        getline(fin, line);
        if(i != 0)
        {
            std::cout << line << std::endl;
        }
    }
    fin.close();
    
    //now show meminfo
    location = "/proc/meminfo";
    fin.open(location);
    for(i = 0; i < 2; ++i)
    {
        getline(fin, line);
        std::cout << line << std::endl;
    }
    fin.close();
    
    //now show uptime
    location = "/proc/uptime";
    fin.open(location);
    getline(fin, line);
    std::cout << "uptime: \t " << line << std::endl;
    fin.close();
    
    //now show version info
    location = "/proc/version";
    fin.open(location);
    getline(fin, line);
    std::cout << line << std::endl;
    fin.close();
    
}

/*Print error message*/
void errorMessage()
{
    std::cout << "Invalid command.\nValid commands are: \ncmdnm <pid>\n"
              << "pid <command>\nsystat\nexit" << std::endl;
}

/*Converts integer into string.
 * idea came from:
 * http://stackoverflow.com/questions/228005/
 * alternative-to-itoa-for-converting-integer-to-string-c
 */
std::string itoa(int num)
{
    std::string temp = "";
    std::stringstream ss;
    
    //put num into string stream
    ss << num;
    temp = ss.str();
    
    return temp;
}

