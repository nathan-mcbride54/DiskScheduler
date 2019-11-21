#include <stdio.h>
#include <stdlib.h>

int randomNumber(void); // Used to generate a random number for track location
void initialize(void);
void readParams(void);
void addToList(int trackNumber);
int removeFromList(void);

unsigned seed;
int totalRequests;
int numberFileRequests;
int totalHeadMove;
int currentTrack;

void main()
{

    readParams();
    initialize();

    while(numberFileRequests <= 10000)
    {
        int numberTrackRequests = 5; // Change to random int 0-5
        for(int i = 0; i <= numberTrackRequests; i++ )
        {
            int trackNumber = 650; // Change to random int 0-799
            addToList(trackNumber);
        }

        int nextTrack = removeFromList(); // Serve the next request

        int difference = abs(nextTrack - currentTrack);

        totalHeadMove += difference;

        totalRequests ++;

        currentTrack = nextTrack;

        numberFileRequests ++;
    }
    float average = totalHeadMove / totalRequests;
    printf("Average: %f", average);
}

void initialize()
{
    srand(seed);
    totalRequests = 0;
    numberFileRequests = 0;
    totalHeadMove = 0;
    currentTrack = 0;
}

void readParams()
{
    printf("Enter seed for random number generator");
    scanf("%d", &seed);
    printf("Enter seed for random number generator");
}

int randomNumber()
{
    for(int i = 0; i < 5; i++)
    {
        printf(" %d", rand());
    }
}


