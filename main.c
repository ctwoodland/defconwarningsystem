#include <stdio.h>
// Required for millisecond timer (for our loading message)
#include <time.h>
// Required for 'strtol':
#include <stdlib.h>

FILE *level;
FILE *popen(const char *command, const char *mode);
int pclose(FILE *stream);

static void redrawPrompt(void);

// Initiate DEFCON level; default 0 indicates the level has not been retrieved 
int defLevel = 0;

int getCurrentLevel()
{
    // This will hold the DEFCON level to return as an integer
    int value;
    
    // Use 'popen' to pipe in a command to fetch the data from the URL. We will use 'wget' because why not?
	FILE *cmd = popen("wget -q -O - http://defconwarningsystem.com/code.dat", "r");
    
    // 'popen' requires a 'char' variable
    char result[1024];
    
    // Can only set a DEFCON level if there is one.
    while (fgets(result, sizeof(result), cmd) != NULL) {
        // Convert the fetched string to a long integer with 'strtol', from the 'stdlib' library
        value = strtol(result,NULL,0);
        
        if ( value != 1 && value != 2 && value != 3 && value != 4 && value != 5 ) {
                return 6;
        }
    }
    pclose(cmd);
    return value;
    
}

int main(void)
{
    const int trigger   = (CLOCKS_PER_SEC * 500) / 1000;  // 500 ms in clocks.
    clock_t   prevClock = clock() - trigger;
    
    int msec = 0, trigger2 = 30000; /* 30s */
    clock_t   before = clock();
    
    
    int q = 0;
    for ( ; ; ) {
        while (q < 10) {
            clock_t curClock = clock();
            // If 500 milliseconds have passed...
            if (curClock - prevClock >= trigger) {
                // Reset clock
                prevClock = curClock;
                // Draw another loading dot
                redrawPrompt();
                q++;
            }
        } 
        defLevel = getCurrentLevel();
        
        q = 0;
        
        if ( defLevel == 1 || defLevel == 2 || defLevel == 3 || defLevel == 4 || defLevel == 5 ) {
                break;
        }
        clock_t difference = clock() - before;
        msec = difference * 1000 / CLOCKS_PER_SEC;
        if (msec >= trigger2) {
                printf(" Timed out after 30 seconds.");
                break;
        }
    }
    
    
    
    // Boolean to check whether any DEFCON level has been determined
	int b = 1;
	
	// Sound three tones and begin transmission
	printf("\a\a\a\n\n");

	// Distinguish transmission from CLI history
	printf("######## BEGIN MESSAGE ########\n\n\n\n");
	printf("This is the ");

	// Set output to blue
	printf("\033[1;36m");	
	printf("☢ DEFCON Warning System");

	// Reset output color
	printf("\033[0m");
	printf(".\n\n");

	printf("Condition \033");

	// Variable to store search index
	int a;

	// Search through the possible DEFCON levels
	for( a = 1; a <= 5; a = a + 1 ){

		// If the DEFCON level is found...
		if( a == defLevel ){

			// CONDITION RED
			if( a == 1 ){
				printf("[0;31m");
				printf("RED");
			}

			// CONDITION ORANGE
			else if( a == 2 ){
				printf("[0;33m");
				printf("ORANGE");
			}

			// CONDITION YELLOW
			else if( a == 3 ){
				printf("[01;33m");
				printf("YELLOW");
			}

			// CONDITION BLUE
			else if( a == 4 ){
				printf("[0;34m");
				printf("BLUE");
			}

			// CONDITION GREEN
			else if( a == 5 ){
				printf("[0;32m");
				printf("GREEN");
			}

			// Reset output color
			printf("\033[0m");

			// Declare the current DEFCON level
			printf(". DEFCON ");
			printf("%d.\n\n", a);
            
            switch(a) {
                case 1 :
                    printf("A nuclear attack against the United States is in progress or is considered to be highly likely.\n\nIf you do not have a fallout shelter, you must begin making one immediately.\n\nDo not travel far from your shelter. If you are in a city or near another nuclear target, you may not have time to evacuate and it may no longer be possible due to jammed roadways or travel restrictions.\n\nFill all plastic bottles with water. Fill your bathtub and sinks with water as well. If you can fill it with water, do so. You can never have too much water. Repeat: You can never have too much water! Remember that the water in your hot water tank is also another source of clean water.\n\nIf there is anything you need in your shelter that you do not have there already, move it there. Disconnect all power sources to prevent damage from any EMP. (Note that the EMP effect is only theoretical.)\n\nKeep your family together.\n\n\n\nAt your own discretion, ");
                    break;
                case 2 :
                    printf("Hostilities have or are about to break out. There is the possibility of a nuclear strike against the United States.\n\n");
                    break;
                case 3 :
                    printf("There is no known immediate nuclear threat against the United States, however the situation is considered fluid.\n\n");
                    break;
                case 4 :
                    printf("There are no known imminent nuclear threats against the United States, though there are some events which warrant observation.\n\n");
                    break;
                case 5 :
                    printf("There are no known imminent nuclear threats against the United States.\n\n");
                    break;
            }
            printf("Visit http://www.defconwarningsystem.com for details.\n\n\033[1;36mTwitter\033[0m updates: @DEFCONWSAlerts\n\n\n\n######### END MESSAGE #########\n\n");

			// The level has been found. Set boolean.
			b = 0;
		}

		// If all the possible DEFCON levels have been searched...
		else if ( a == 5 ){

			// ... and none have matched...
			if( b == 1 ){

				// ... we clearly have a problem. The DEFCON level was not retrieved properly. Guide user to troubleshoot.
				printf("[0m");
				printf("unknown. Failed to retrieve DEFCON level. Please check connection.\n\n");
                
                // Print the data for debugging purposes
                // printf("Received data: %d\n\n", defLevel);
                
			}
		}
	}
	// Good etiquette :^)
	return 0;
}

static void redrawPrompt(void)
{
    static int  numDots;
    const  int  maxDots = 4;
    const  char prompt[] = "Retrieving data from server";

    // Return and clear with spaces, then return and print prompt.
    printf("\r%*s\r%s", sizeof(prompt) - 1 + maxDots, "", prompt);
    for (int i = 0; i < numDots; i++)
        fputc('.', stdout);
    fflush(stdout);
    if (++numDots > maxDots)
        numDots = 0;
}


