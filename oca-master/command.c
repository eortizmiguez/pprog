/** 
 * @brief It implements the command interpreter
 * 
 * @file command.c
 * @author David Ramirez
 * @version 1.1 
 * @date 12/02/2019 
 */

#include <stdio.h>
#include <strings.h>
#include "command.h"

#define CMD_LENGHT 30
#define N_CMD 7

char *cmd_to_str[N_CMD] = {"No command", "Unknown", "Exit", "Next", "Back", "Take", "Drop"};
char *short_cmd_to_str[N_CMD] = {"","","e","n","b","t","d"};


T_Command get_user_input(){
	T_Command cmd = NO_CMD;
	char input[CMD_LENGHT] = "";
	int i=UNKNOWN - NO_CMD + 1;
	  
	if (scanf("%s", input) > 0){    
		cmd = UNKNOWN;
		while(cmd == UNKNOWN && i < N_CMD){
			if (!strcasecmp(input,short_cmd_to_str[i]) || !strcasecmp(input,cmd_to_str[i])){
				cmd = i + NO_CMD;
			}else{
				i++;
			}
		}
	}
	return cmd;
}

