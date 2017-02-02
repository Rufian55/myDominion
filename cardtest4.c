/******************************************************************************
* cardtest 1: function testGetWinners() tests dominion.c::getWinners().
* cardtest1.c is a unit testing program for the above function contained within
* dominion.c, compiled via MakeFile.
* Chris Kearns, kearnsc@oregonstate.edu, CS325-400-W17, Assign_3, 5 Feb 2017
******************************************************************************/
#include <stdio.h>
#include <string.h>
#include "dominion.h"

// Prototypes.
void chrisAssert(_Bool result, int testNum);

int main() {

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