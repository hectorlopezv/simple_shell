# Simple - Shell

[![Everything Is AWESOME](https://i.imgur.com/YNXlg6A.png)](https://www.youtube.com/watch?v=Tw2dobf_rP0&feature=youtu.be "Indoor Delivery Robots")
### Description
Mini-Shell is a command line interpreter based on sh that brings to the table some of the basic features that sh offers.


### Usage
Works exactly like sh, does not support iteractive mode
### Example Commands
* `exit 100`
* * `cd directory`
* * `pwd`
* * `ls -l`
*
* ### Instalation
* Clone the repository, then change current directory to simple-shell, and last but not least run `gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`
*
* ### Files
*
* | File | Description|
* | ------ | ------ |
* |builtins.c |function for handling builtins|
* |errors.c| handle errors of the program|
* |exec.c| execve implementation for Simple Shell|
* |fork.c| creates a new process from the parent|
* |loop.c| function that loops until the procces gets terminated|
* |main.c|entry point|
* |prompt.c|function to get the line typed|
* |shell.h|header file with functions declarations |
* |signals.c| signal handler for signal as SIGINT|
* |stat.c|stat of a file.|
* |tokenizer.c|split a string into a single word|
* |utils.c|file containing various functions used for multipurpose|
* |which.c|function for finding the  directory needed|
*
*
* | Special Features | Purpose|
* | ------ | ------ |
* | Ctrl + C| To prevent the killing of the simple-shell  |
* | Ctrl + D|  exit the simple-shell |
*
* ### Builtins commands
*
* * `exit`
* * `cd`
* * `setenv`
* * `env`
*
* ### System Calls / Functions Implemented
* * `fork`,`execve`,`waitpid/wait`,`getline`,`strtok`,`exit`,`close`,`perror`
* * `stat`,`access`,`strcat`,`strcpy`,`strlen`,`getenv`,`getcwd`,`signal`
*
* ### WARNING
* Work still in progress, aliases and piping , redirection not available.
* ### AUTHORS
* *Samuel Gomez*   [Github](https://github.com/samgj18) :mortar_board:
* *Hector Lopez* [Github](https://github.com/hectorlopezv)
*
*
*
*
*