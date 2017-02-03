/******************************************************************************
* cardtest 1: function testGetWinners() tests dominion.c::getWinners().
* cardtest1.c is a unit testing program for the above function contained within
* dominion.c, compiled via MakeFile.
* Chris Kearns, kearnsc@oregonstate.edu, CS325-400-W17, Assign_3, 5 Feb 2017
* Reveal cards from your deck until 2 Treasure cards are revealed.
* Add those cards to your hand.
* Discard the other revealed cards.
******************************************************************************/
#include <stdio.h>
#include <string.h>
#include "dominion.h"

// Prototypes.
void softAssert(_Bool result, int testNum);
void runAdventurer(struct gameState *state, int currentPlayer, int *temphand);

int main() {
	int temphand[MAX_HAND];
	struct gameState G1;	// Our gameState to be tested.
	struct gameState G2;	// Our gameState used to reset G1.

	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };

	// Bypasses CLI input with randomseed = 66 (totally random pick by tester...)
	initializeGame(2, k, 66, &G1);

	// Set gameState G2 to the initial settings following initialization of G1.
	memcpy(&G2, &G1, sizeof(struct gameState));

	int T1pre = G1.handCount[0];
	int T2pre = G1.deckCount[0];
	int T3pre = G1.discardCount[0];
	int T4pre = G1.playedCardCount;

	runAdventurer(&G1, 0, temphand);

	int T1post = G1.handCount[0];
	int T2post = G1.deckCount[0];
	int T3post = G1.discardCount[0];
	int T4post = G1.playedCardCount;

	printf("Pre = %d %d %d %d\n", T1pre, T2pre, T3pre, T4pre);
	printf("Pst = %d %d %d %d\n", T1post, T2post, T3post, T4post);






	// discardcount went up by discard count
	return 0;
}

/* "Roll your own" less intrusive assert function. NOTE: When the expectation
is result should be false, call softAssert with "!result" as argument. */
void softAssert(_Bool result, int testNum) {
	printf("Function gainCard() - ");
	if (result)
		printf("TEST %d SUCCESFULLY COMPLETED\n", testNum);
	else
		printf("TEST %d FAILED - Potential bug!\n", testNum);
}


/* // For reference only.
void runAdventurer(struct gameState *state, int currentPlayer, int *temphand) {
	int drawntreasure = 0;
	int z = 0;
	int cardDrawn;

	while (drawntreasure < 2) {
		if (state->deckCount[currentPlayer] < 1) { // If the deck is empty we need to shuffle discard and add to deck.
			shuffle(currentPlayer, state);
		}
		drawCard(currentPlayer, state);
		cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer] - 1]; // Top card of hand is most recently drawn card.
		cardDrawn++;
		if (cardDrawn == copper - 1 || cardDrawn == silver || cardDrawn == gold)
			drawntreasure++;
		else {
			if (cardDrawn > treasure_map) cardDrawn--;
			temphand[z] = cardDrawn;
			state->handCount[currentPlayer]--; // This should just remove the top card (the most recently drawn one).
			z++;
		}
	}
	while (z - 1 >= 0) {
		state->discard[currentPlayer][state->discardCount[currentPlayer]++] = temphand[z - 1]; // Discard all cards in play that have been drawn.
		z = z - 1;
	}
}
*/