/* termi.c - termi
 * Brief description:
 *  Termi is a simple terminal companion! You can use it to send commands to
 *  the terminal and get the output. You can also chat with termi, and it can
 *  produce a chat-like interface.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * Author: Owen Boreham
 * Email: owenkadeboreham@gmail.com
 */

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Const 2 dimensional array of commands */
char *commands[][2] = {
    {"help",        "Display this help message"},
    {"exit",        "Exit the program"},
    {"clear",       "Clear the screen"},
    {"echo",        "Echo the given string"},
    {"cmd",         "Send a command to the terminal"},
    {"chat",        "Start a chat with termi"},
    {"", ""}
};

/* Function prototypes */
void help(void);
void man(char *);

int main(int argc, char *argv[])
{
    while (1) {
        /* Get user input */
        char *input = malloc(sizeof(char) * 1024);
        printf("termi> ");
        fgets(input, 1024, stdin);

        if (strcmp(input, "/help\n") == 0) {
            help();
        } else if (strcmp(input, "/exit\n") == 0) {
            exit(0);
        } else if (strcmp(input, "/clear\n") == 0) {
            system("clear");
        } else if (strncmp(input, "/echo ", 5) == 0) {
            printf("%s\n", input + 5);
        } else if (strncmp(input, "/cmd ", 4) == 0) {
            system(input + 4);
        } else {
            system(input);
        }

        /* free the memory */
        free(input);
    }

    return 0;
}

void help(void)
{
    printf("\n");
    printf("Commands:\n");
    printf("\n");

    int i = 0;
    while(strcmp(commands[i][0], "") != 0)
    {
        printf("%s      %s\n", commands[i][0], commands[i][1]);
        i++;
    }

    printf("\n");
}
