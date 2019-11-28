#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define QueueSize 50000

int RandomNumber(int randMax); // Used to generate a random number for track location
void FillQueue(int schedule_type, int seed, int max_requests);
void AddToQueue(int trackRequest, int schedule_type);
float ProcessQueue(void);
void ShowResults(float result, int seed_used, int test_value, int schedule_type);
int RemoveFromQueue(void);
void AutoSimulation(void);
char GetUserInput(void);
char Prompt(void);

int seeds[5] = {57, 123, 654, 23, 74};
int test_values[4] = {10, 100, 1000, 10000};
long Queue[QueueSize];
int requestsInQueue;
int totalRequests;
int numberFileRequests;
int totalHeadMove;
int currentTrack;


void main() {
    bool quit = false;
    while(!quit) {
        printf("Disk Scheduling Simulator\n");
        printf("=========================\n");
        printf("Enter 'A' to test all\n");
        printf("Enter 'Q' to quit\n");
        char userChoice = GetUserInput();
        switch(userChoice) {
            case 'A' :
                printf("Testing FCFS and SSTF with the following values...\n");
                printf("Seeds: 57, 123, 654, 23, 74\n");
                printf("File Requests: 10, 100, 1000, 10000\n");
                AutoSimulation();
            break;
            case 'Q' :
                quit = true;
            break;
        }
    }
}

char GetUserInput()
{
    char Prompt() {
        char input[100];
        printf("-> ");
        scanf("%s", &input);
        return toupper(input[0]);
    }

    // Input errors are caught by matching to only the specific characters that are valid in this program.
    while(1) {
        char input = Prompt();
        if(input == 'A' || input == 'Q') { return input; }
        else { printf("Invalid Input\n"); }
    }
}

void AutoSimulation() {
//    for(int schedule = 1; schedule > 3; schedule++) {
        for(int i = 0; i <= 4; i++ ) {
            for(int j = 0; j <= 3; j++) {
                FillQueue(2, seeds[i], test_values[j]);
                float result = ProcessQueue();
                ShowResults(result, seeds[i], test_values[j], 2);
            }
        }
//    }
}

void ShowResults(float result, int seed_used, int test_value, int schedule_type) {
    printf("===================================\n");
    if(schedule_type == 1) { printf("Schedule Type: FCFS\n"); }
    if(schedule_type == 2) { printf("Schedule Type: SSTF\n"); }
    printf("File Requests Simulated: %d\n", test_value);
    printf("Seed Used: %d\n", seed_used);
    printf("Result: %f\n", result);
    printf("===================================\n");
}

float ProcessQueue() {
    while(requestsInQueue > 0) {
        int nextTrack = RemoveFromQueue(); // Serve the next request
        int difference = abs(nextTrack - currentTrack); // Calculate the distance for the read head to travel
        totalHeadMove += difference; // Add the distance traveled to the total
        totalRequests ++; // Increment the number of total requests
        currentTrack = nextTrack;
        requestsInQueue --;
    }
    return totalHeadMove / (float) numberFileRequests;
}

void Initialize(int queue_size) {
    for(int index = queue_size; index >=0; index--) {
        Queue[index] = 0;
    }
    totalRequests = 0;
    requestsInQueue = 0;
    numberFileRequests = 0;
    totalHeadMove = 0;
    currentTrack = 0;
}

int RandomNumber(int randMax) {
    return rand() % randMax;
}

bool IsFull() {
    return QueueSize == requestsInQueue;
}

void AddToQueue( int trackRequest, int schedule_type) {
    int index;
    int insertDistance;
    int indexDistance;

    if(!IsFull()) {
        // if queue is empty, insert the data
        if(requestsInQueue == 0) {
            Queue[requestsInQueue++] = trackRequest;
        }
        else {
            switch(schedule_type) {
                case 1 : // FCFS
                    Queue[requestsInQueue+1] = trackRequest; // insert at the end of the queue
                    requestsInQueue++; // Increment the number of requests currently in queue
                break;

                case 2 : //SSTF
                    for(index = requestsInQueue - 1; index >= 0; index-- ) { // Start at the tail of the queue, working towards the head
                        insertDistance = trackRequest - Queue[0];
                        indexDistance = Queue[index] - Queue[0];
                        if(insertDistance > indexDistance) {
                            Queue[index+1] = Queue[index]; // Copy the current value of index to index + 1
                        }
                        else { break; } // Track request belongs at index
                    }
                    Queue[index] = trackRequest; // Put the track request in the queue
                    requestsInQueue++; // Increment the number of requests currently in queue
                break;
            }
        }
    }
}

int RemoveFromQueue() {
    if(requestsInQueue > 0) {
        int front = Queue[0]; // Grab the current front of the queue
        for(int i = 0; i <= requestsInQueue -1; i++) {
            Queue[i] = Queue[i + 1]; // Shuffle the elements of the queue to make a new front
        }
        -- requestsInQueue; // Update number of requests in queue
        return front;
    }
    else { return 0; }
}

void FillQueue(int schedule_type, int seed, int max_requests) {
    Initialize(max_requests);
    srand(seed);

    while(numberFileRequests <= max_requests) {

        int numberTrackRequests = RandomNumber(5);

        for(int i = 0; i <= numberTrackRequests; i++ ) {

            int trackNumber = RandomNumber(799);
            AddToQueue(trackNumber, schedule_type);
        }
        numberFileRequests ++; // move to next file
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