#include <stdio.h>
#include <time.h>

static void redrawPrompt(void);
static void fetchDEFCON(void);
int defLevel;
int x;

int main() {
	
	// Variable to store the level fetched from the internet
	
	const int trigger = (CLOCKS_PER_SEC * 500) / 1000; // 500 ms in clocks
	clock_t	prevClock = clock() - trigger;
	
	while (defLevel != 1 || defLevel != 2 || defLevel != 3 || defLevel != 4 || defLevel != 5) {
		clock_t curClock = clock();

		if (curClock - prevClock >= trigger) {
			prevClock = curClock;
			redrawPrompt();
		}
		fetchDEFCON();
	}
	/* int x;
	printf("Waiting for connection");
	do {
		printf(". ");
		scanf("%d", &x);
		fetch = x;
		defLevel = fetch;
	} while( x != 1 || x != 2 || x != 3 || x !=4 || x != 5 );
*/
	
	/*
		#######################
		TODO:
		- Figure out a way to retrieve level from data available on
		defconwarningsystem.com
		- Retrieve the level and store it in the 'fetch' variable
		- Assign defLevel the value of 'fetch'
		#######################
	*/

	// Boolean to check whether any DEFCON level has been determined
	int b = 1;
	
	// Sound three tones and begin transmission
	printf("\a\a\a\n\n");

	// Distinguish transmission from CLI history
	printf("########################################\n\n");
	printf("This is the ");

	// Set output to blue
	printf("\033[0;34m");	
	printf("DEFCON Warning System");

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
			}
		}
	}
	// Good etiquette :^)
	return 0;
}

static void redrawPrompt(void){
        static int numDots;
        const int maxDots = 4;
        const char prompt[] = "Waiting for connection";

        printf("\r%*s\r%s", sizeof(prompt) - 1 + maxDots, "", prompt);
        for (int i = 0; i < numDots; i++)
                fputc('.', stdout);
        fflush(stdout);
        if (++numDots > maxDots)
                numDots = 0;
}

static void fetchDEFCON(void) {

        scanf("%d", &x);
        defLevel = x;
}

