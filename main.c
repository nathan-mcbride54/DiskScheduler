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
















/** Lab Instructions:
 *
 * Write a C program to simulate disk scheduling for a disk with 800tracks (numbered 0 to 799).
 * You are required to simulate both first-come-first-served (FCFS) and shortest-seek-time-first(SSTF)disk scheduling algorithms.
 *
 * Your main function should contain a loop which begins by picking a random number between 0 and 5 to represent the number of track requests for the current file request.
 * (assume there are 10000 file requests). You then generate that number of track requests (each is a random number between 0 and799).
 * Each of these track requests are then added to a queue.This simulates the arrival of a file request to the disk consisting of some number of blocks of a file.
 *
 * The next step is to remove one of the track requests from the queue in either FCFS or SSTF fashion.
 * Removing a track request simply implies that the disk head will be moved to that track.
 * Each time the disk head is moved, keep count of the number of track head movements and when the simulation completes, print out the average head movement for FSFS (or SSTF).
 * Be sure to process any remaining track requests on the queue before printing the results.
 * Because we are using random numbers,it is best that the simulation is run 5 times with a different random number seed each time.
 * (be sure to use the same seeds for SSTF as you did for FCFS).
 * The average head movement for each disk scheduling algorithm, will be the average of the 5 runs.
 *
 * The logic for your main function should look something like:
 *
 * Initialize random number generator (give it a seed)
 * totalReqs = 0; numFileReqs = 0; totalHeadMove = 0; currTrack = 0;
 *
 * // starting position of the disk head
 * While(numFileReqs <= 10000) do
 *      numTrackReqs = random number between 0 and 5
 *      Loop numTrackReqs times
 *          trackNum = random number between 0 and 799;
 *          AddToList(trackNum);
 *      EndLoop
 *
 *      // serve the next request (using either FCFS or SSTF)
 *      nextTrack = RemoveFromList();
 *      diff = abs(nextTrack - currTrack);
 *      totalHeadMove += diff;
 *      totalReqs++;
 *      currTrack = nextTrack;
 *      numFileReqs++;
 * Endwhile
 *
 * average = totalHeadMove / (float) numReqs;
 * Print average;
 *
 *
 * Note:It is up to you as to how you build your queue to hold the track requests.
 * You may use an Array, Linked List, etc.
**/