#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
// Queue implementation
int queue[MAX], front = -1, rear = -1;
int isQueueEmpty() {
    return front == -1 || front > rear;
}
int isQueueFull() {
    return rear == MAX - 1;
}
void enqueue(int player) {
    if (isQueueFull()) {
        printf("Queue is full!\n");
    } else {
        if (front == -1) front = 0;
        queue[++rear] = player;
    }
}
int dequeue() {
    if (isQueueEmpty()) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        return queue[front++];
    }
}

int queueSize() {
    return rear - front + 1;
}
// Game Logic
void hotPotatoGame(int numPlayers) {
    srand(time(0)); // Seed for random number generation

    // Enqueue all players
    for (int i = 1; i <= numPlayers; i++) {
        enqueue(i);
    }
    // Game loop
    while (queueSize() > 1) {
        int passes = rand() % numPlayers + 1; // Random number of passes
        printf("\nPasses this round: %d\n", passes);

        // Pass the potato around by dequeuing and enqueuing
        for (int i = 0; i < passes; i++) {
            int player = dequeue();
            enqueue(player);
        }
        // Eliminate the player holding the potato
        int eliminatedPlayer = dequeue();
        printf("Player %d is eliminated!\n", eliminatedPlayer);
    }

    // The last remaining player is the winner
    int winner = dequeue();
    printf("\nPlayer %d is the winner!\n", winner);
}

int main() {
    int numPlayers;
    printf("Enter the number of players: ");
    scanf("%d", &numPlayers);
    if (numPlayers <= 1) {
        printf("There should be at least 2 players to play the game.\n");
        return 0;
    }
    hotPotatoGame(numPlayers);
    return 0;
}

