# Simple - Shell

[![Everything Is AWESOME](https://i.imgur.com/YNXlg6A.png)]()
### Description
Mini-Shell is a command line interpreter based on sh that brings to the table some of the basic features that sh offers.


### Usage
Works exactly like sh, does not support iteractive mode
### Example Commands
* `exit 100`
 * `cd directory`
 * `pwd`
 * `ls -l`

 ### Instalation
 Clone the repository, then change current directory to simple-shell, and last but not least run `gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`

 ### Files

 | File | Description|
 | ------ | ------ |
 |parsing.c |function for parsing the path|
 |errors.c| handle errors of the program|
 |fork.c| creates a new process from the parent|
 |signal_prompt.c| functions related to signal handling and prompt|
 |runner.c|entry point|
 |shell.h|header file with functions declarations |
 |path.c| funcntions for handling the path|
 |utils.c|utility functions for various operations|
 |strings_utils.c|functions for handling strings|
 |strings.c|functions for handling strings|
 |validation.c|functions for validating a path|

 | Special Features | Purpose|
 | ------ | ------ |
 | Ctrl + C| To prevent the killing of the simple-shell  |
 | Ctrl + D|  exit the simple-shell |

 ### Builtins commands

 * `exit`
 * `cd`
 * `setenv`
 * `env`

 ### System Calls / Functions Implemented
 * `fork`,`execve`,`waitpid/wait`,`getline`,`strtok`,`exit`,`close`,`perror`
 * `stat`,`access`,`strcat`,`strcpy`,`strlen`,`getenv`,`getcwd`,`signal`

 ### WARNING
 Work still in progress, aliases and piping , redirection not available.
 ### AUTHORS
 *Samuel Gomez*   [Github](https://github.com/samgj18) :mortar_board:
 *Hector Lopez* [Github](https://github.com/hectorlopezv)
