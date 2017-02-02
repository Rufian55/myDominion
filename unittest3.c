/******************************************************************************
* Unittest 3: function testDiscardCard() tests dominion.c::discardCard().
* unittest3.c is a unit testing program for the above function contained within
* dominion.c, compiled via MakeFile.
* Chris Kearns, kearnsc@oregonstate.edu, CS325-400-W17, Assign_3, 5 Feb 2017
******************************************************************************/
#include <stdio.h>
#include <string.h>
#include "dominion.h"

// Prototypes.
void chrisAssert(_Bool result, int testNum);
int testDiscardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag);

int main() {
	struct gameState G1;	// Our gameState to be tested.
	struct gameState G2;	// Our gameState used to reset G1.

	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };

	// Bypasses CLI input with randomseed = 66 (totally random pick by tester...)
	initializeGame(2, k, 66, &G1);

	// Set gameState G2 to the initial settings following initialization of G1.
	memcpy(&G2, &G1, sizeof(struct gameState));

	// Player 0 discards village card (enum CARD 14), trashflag is 0.
	int result = testDiscardCard(14, 0, &G1, 0);

	printf("playedCard = %d\n", G1.playedCards[G1.playedCardCount]);
	printf("playedCardCount = %d\n", G1.playedCardCount);

	// Reset gameState G1.
	memcpy(&G1, &G2, sizeof(struct gameState));

	result = testDiscardCard(14, 0, &G1, 1);

	printf("playedCard = %d\n", G1.playedCards[G1.playedCardCount]);
	printf("playedCardCount = %d\n", G1.playedCardCount);

	return 0;
}

/* "Roll your own" less intrusive assert function. NOTE: When the expectation
is result should be false, call chrisAssert with "!result" as argument. */
void chrisAssert(_Bool result, int testNum) {
	printf("Function getWinners() - ");
	if (result)
		printf("TEST %d SUCCESFULLY COMPLETED\n", testNum);
	else
		printf("TEST %d FAILED\n", testNum);
}


int testDiscardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag) {
	// If card is not trashed, added to Played pile.
	if (trashFlag < 1) {
		// Add card to played pile.
		state->playedCards[state->playedCardCount] = state->hand[currentPlayer][handPos];
		state->playedCardCount++;
	}
	// Set played card to -1.
	state->hand[currentPlayer][handPos] = -1;
	// Remove card from player's hand.
	if (handPos == (state->handCount[currentPlayer] - 1)) { // Last card in hand array is played.
												 // Reduce number of cards in hand.
		state->handCount[currentPlayer]--;
	}
	else if (state->handCount[currentPlayer] == 1) { // Only one card in hand.
										    // Reduce number of cards in hand
		state->handCount[currentPlayer]--;
	}
	else {
		// Replace discarded card with last card in hand.
		state->hand[currentPlayer][handPos] = state->hand[currentPlayer][(state->handCount[currentPlayer] - 1)];
		// Set last card to -1.
		state->hand[currentPlayer][state->handCount[currentPlayer] - 1] = -1;
		// Reduce number of cards in hand.
		state->handCount[currentPlayer]--;
	}
	return 0;
}