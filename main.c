#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QueueSize 50000

int randomNumber(int randMax); // Used to generate a random number for track location
void fillQueue(int schedule_type, int seed, int max_requests);
void addToQueue(int trackRequest, int schedule_type);
float processQueue(void);
void showResults(float result, int seed_used, int test_value);
int removeFromQueue(void);

int seeds[5] = {57, 123, 654, 23, 74};
int test_values[4] = {10, 100, 1000, 10000};
long Queue[QueueSize];
int requestsInQueue;
int totalRequests;
int numberFileRequests;
int totalHeadMove;
int currentTrack;


void main() {
    for(int i = 0; i <= 4; i++ ) {
        for(int j = 0; j <= 3; j++) {
            fillQueue(1, seeds[i], test_values[j]);
            float result = processQueue();
            showResults(result, i, j);
        }
    }
}

void showResults(float result, int seed_used, int test_value) {
    printf("\n===================================\n");
    printf("File Requests Simulated: %d\n", test_value);
    printf("Seed Used: %d\n", seed_used);
    printf("Result: %f\n", result);
    printf("===================================\n");
}

float processQueue() {
    while(requestsInQueue > 0) {
        int nextTrack = removeFromQueue(); // Serve the next request
        int difference = abs(nextTrack - currentTrack); // Calculate the distance for the read head to travel
        totalHeadMove += difference; // Add the distance traveled to the total
        totalRequests ++; // Increment the number of total requests
        currentTrack = nextTrack;
        requestsInQueue --;
    }
    return totalHeadMove / (float) numberFileRequests;
}

void initialize(int queue_size) {
    // Clear out irrelevent values...
    // Build Queue
    // Can I make this function return a new queue?
    Queue[]
    totalRequests = 0;
    requestsInQueue = 0;
    numberFileRequests = 0;
    totalHeadMove = 0;
    currentTrack = 0;
}

int randomNumber(int randMax) {
    return rand() % randMax;
}

bool isFull() {
    return QueueSize == requestsInQueue;
}

void addToQueue(int trackRequest, int schedule_type) {
    int index;

    if(!isFull()) {
        // if queue is empty, insert the data
        if(requestsInQueue == 0) {
            Queue[requestsInQueue++] = trackRequest;
        }
        else {
            switch(schedule_type) {
                case 1 : // FCFS
                    // insert at the end of the queue
                    Queue[requestsInQueue+1] = trackRequest;
                    requestsInQueue++;
                break;

                case 2 : //SSTF
                    // start from the right end of the queue
                    for(index = requestsInQueue - 1; index >= 0; index-- ) {
                        // if data is larger, shift existing item to the right
                        if(trackRequest > Queue[index]) {
                            Queue[index+1] = Queue[index];
                        }
                        else { break; } // Break if at the proper location
                    }
                    // insert the data Passenger checks onto flight
                    Queue[index+1] = trackRequest;
                    requestsInQueue++;
                break;
            }
        }
    }
}

int removeFromQueue() {
    if(requestsInQueue > 0) {
        int next = Queue[0];
        for(int i = 0; i <= requestsInQueue -1; i++) {
            Queue[i] = Queue[i + 1];
        }
        -- requestsInQueue;
        return next;
    }
    else {
        return Queue[0];
    }
}

void fillQueue(int schedule_type, int seed, int max_requests) {
    initialize(max_requests);
    srand(seed);

    while(numberFileRequests <= max_requests) {

        int numberTrackRequests = randomNumber(5);

        for(int i = 0; i <= numberTrackRequests; i++ ) {

            int trackNumber = randomNumber(799);
            addToQueue(trackNumber, schedule_type);
        }
        // move to next file
        numberFileRequests ++;
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