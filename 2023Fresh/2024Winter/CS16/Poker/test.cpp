#include "Card.h"
#include "Hand.h"
#include <bits/stdc++.h>

using namespace std;

int main() {
	Hand test_hand;
	Card TwoC(Rank::TWO, Suit::CLUBS);
	Card TwoD(Rank::TWO, Suit::DIAMONDS);
	Card TwoS(Rank::TWO, Suit::SPADES);
	Card TwoH(Rank::TWO, Suit::HEARTS);
	
	Card ThreeD(Rank::THREE, Suit::DIAMONDS);
	Card ThreeC(Rank::THREE, Suit::CLUBS);
	Card FourC(Rank::FOUR, Suit::CLUBS);
	Card FiveC(Rank::FIVE, Suit::CLUBS);
	Card SixC(Rank::SIX, Suit::CLUBS);
	Card SevenC(Rank::SEVEN, Suit::CLUBS);
	Card EightC(Rank::EIGHT, Suit::CLUBS);
	Card NineC(Rank::NINE, Suit::CLUBS);
	Card TenC(Rank::TEN, Suit::CLUBS);
	Card JackC(Rank::JACK, Suit::CLUBS);
	Card QueenC(Rank::QUEEN, Suit::CLUBS);
	Card KingC(Rank::KING, Suit::CLUBS);
	Card AceC(Rank::ACE, Suit::CLUBS);
	
	//test_hand.add(TwoC);	
	//test_hand.add(TwoD);
	//test_hand.add(TwoS);
	//test_hand.add(TwoH);
	//test_hand.add(ThreeC);
	//test_hand.add(ThreeD);
	//test_hand.add(FourC);
	//test_hand.add(FiveC);
	//test_hand.add(SixC);
	/*
	test_hand.add(SevenC);
	test_hand.add(EightC);
	test_hand.add(NineC);
	test_hand.add(TenC);
	test_hand.add(JackC);
	test_hand.add(QueenC);
	test_hand.add(KingC);
	*/
	//test_hand.add(AceC);
	
	test_hand.print(); cout << endl;

	Hand* best = best_hand(test_hand);
	best->print(); cout << endl;

	return 0;
}
