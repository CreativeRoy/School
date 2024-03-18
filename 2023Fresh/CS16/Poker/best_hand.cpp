#include <algorithm>
#include "Hand.h"
#include "Card.h"

using namespace std;

Hand* n_row(const Hand& cards, int n) {
	Hand* best = new Hand();
	int num = cards.count();
	for (int i = 0; i <= num-n; i++) {
		int stk = 0;
		Card c = cards.get(i);
		for (int j = 0; j < n; j++) {
			if (c.rank == cards.get(i+j).rank) {
				stk++;
			}
		}
		if (stk != n) {
			continue;
		}
		for (int j = 0; j < n; j++) {
			best->add(cards.get(i+j));
		}
		break;
	}
	return best;
}

Hand* double_pair(const Hand& cards) {
	Hand* best = new Hand();
	int pairs = 0;
	int num = cards.count();
	for (int i = 0; i <= num-2; i++) {
		int stk = 0;
		Card c = cards.get(i); 
		for (int j = 0; j < 2; j++) {
			if (c.rank == cards.get(i+j).rank) {
				stk++;
			}
		}
		if (stk != 2) {
			continue;
		}
		for (int j = 0; j < 2; j++) {
			best->add(cards.get(i+j));
		}
		pairs++;
		i+=1;
		if (pairs == 2) {
			break;
		}
	}
	return best;
}

Hand* straight(const Hand& cards) {	
	int num = cards.count();
	Hand* best = new Hand();
	int curr = 16;
	for (int i = 0; i < num; i++) {
		int i_rank = cards.get(i).rank;
		if (i_rank == curr-1) {
			best->add(cards.get(i));
			if (best->count() == 5) break;
		} else if (i_rank < curr-1) {
			delete best;
			best = new Hand();
			best->add(cards.get(i));
		}
		curr = i_rank;
	}
	if ((curr = 2) && (best->count() == 4) && (cards.get(0).rank == Rank::ACE)) {
		best->add(cards.get(0));	
	} 
	return best;
}

Hand* flush(const Hand& cards) {
	int num = cards.count();
	Hand* clubs = new Hand();	
	Hand* hearts = new Hand();
	Hand* diamonds = new Hand();
	Hand* spades = new Hand();
	for (int i = 0; i < num; i++) {
		Card c = cards.get(i);
		if (c.suit == Suit::CLUBS) {
			clubs->add(c);
			if (clubs->count() == 5) {
				delete hearts;
				delete diamonds;
				delete spades;

				return clubs;
			}
		} else if (c.suit == Suit::SPADES) {
			spades->add(c);
			if (spades->count() == 5) {
				delete clubs;
				delete hearts;
				delete diamonds;
				return spades;
			}
		} else if (c.suit == Suit::DIAMONDS) {
			diamonds->add(c);	
			if (diamonds->count() == 5) {
				delete clubs;
				delete hearts;
				delete spades;
				return diamonds;
			}
		} else if (c.suit == Suit::HEARTS) {
			hearts->add(c);
			if (hearts->count() == 5) {
				delete clubs;
				delete diamonds;
				delete spades;
				return hearts;
			}
		}
	}
	delete hearts;
	delete diamonds;
	delete spades;

	return clubs;
}

Hand* full_house(const Hand& cards) {
	int num = cards.count();
	Hand* best = new Hand();
	bool three = false;
	bool two = false;
	//try 3 then 2
	for (int i = 0; i < num; i++) {
		Card c = cards.get(i);
		int stk = 0;
		if (!three) {
			stk = 0;
			for (int j = 0; j < 3; j++) {
				if (i+j >= num) break;
				if (c.rank == cards.get(i+j).rank) {
					stk++;	
				}
			}
			if (stk == 3) {		
				for (int j = 0; j < 3; j++) {
					best->add(cards.get(i+j));
				}
				three = true;
				i += 2;
				continue;
			}
		} 
		if (!two) {
			stk = 0;
			for (int j = 0; j < 2; j++) {
				if (i+j >= num) break;
				if (c.rank == cards.get(i+j).rank) {
					stk++;	
				}
			}
			if (stk == 2) {						
				for (int j = 0; j < 2; j++) {
					best->add(cards.get(i+j));
				}
				two = true;
				i += 1;
				continue;
			}
		}
	}
	return best;
}

Hand* straight_flush(const Hand& cards) {
	int num = cards.count();
	Hand* clubs = new Hand();	
	Hand* hearts = new Hand();
	Hand* diamonds = new Hand();
	Hand* spades = new Hand();
	for (int i = 0; i < num; i++) {
		if (cards.get(i).suit == Suit::CLUBS) {
			clubs->add(cards.get(i));
		} else if (cards.get(i).suit == Suit::SPADES) {
			spades->add(cards.get(i));
		} else if (cards.get(i).suit == Suit::DIAMONDS) {
			diamonds->add(cards.get(i));	
		} else if (cards.get(i).suit == Suit::HEARTS) {
			hearts->add(cards.get(i));
		}
	}
	Hand* clubs_straight = straight(*clubs); 
	Hand* diamonds_straight = straight(*diamonds); 
	Hand* hearts_straight = straight(*hearts); 
	Hand* spades_straight = straight(*spades);
	delete clubs;
	delete hearts;
	delete diamonds;
	delete spades;
	int top_clubs = -1;
	int top_diamonds = -1;
	int top_hearts = -1;
	int top_spades = -1;
	if (clubs_straight->count() == 5) {
		top_clubs = clubs_straight->get(0).rank;
		if ((clubs_straight->get(0).rank == 14) && 
			(clubs_straight->get(1).rank == 5)) {
			top_clubs = 5;
		}
	} 
	if (diamonds_straight->count() == 5) {
		top_diamonds = diamonds_straight->get(0).rank;
		if ((diamonds_straight->get(0).rank == 14) && 
			(diamonds_straight->get(1).rank == 5)) {
			top_diamonds = 5;
		}

	} 
	if (hearts_straight->count() == 5) {
		top_hearts = hearts_straight->get(0).rank;
		if ((hearts_straight->get(0).rank == 14) && 
			(hearts_straight->get(1).rank == 5)) {
			top_hearts = 5;
		}
	} 
	if (spades_straight->count() == 5) {
		top_spades = spades_straight->get(0).rank;
		if ((spades_straight->get(0).rank == 14) && 
			(spades_straight->get(1).rank == 5)) {
			top_spades = 5;
		}
	} 
	int top = std::max(std::max(top_clubs, top_diamonds), std::max(top_hearts, top_spades));
	if (top == -1) {
		delete hearts_straight;
		delete diamonds_straight;
		delete spades_straight;

		return clubs_straight;
	} else if (top == top_clubs) {
		delete hearts_straight;
		delete diamonds_straight;
		delete spades_straight;

		return clubs_straight;
	} else if (top == top_diamonds) {
		delete hearts_straight;
		delete clubs_straight;
		delete spades_straight;

		return diamonds_straight;
	} else if (top == top_hearts) {
		delete clubs_straight;
		delete diamonds_straight;
		delete spades_straight;

		return hearts_straight;
	} else if (top == top_spades) {
		delete hearts_straight;
		delete diamonds_straight;
		delete clubs_straight;

		return spades_straight;
	}
	delete hearts_straight;
	delete diamonds_straight;
	delete spades_straight;
	return clubs_straight;
}


//ace can be 1 or 14

Hand* best_hand(const Hand& cards) {
	Hand* best = new Hand();
	
	//check empty
	if (cards.count() == 0) return best;
	
	//check straight flush
	//cout << "Check straight_flush" << endl;
	delete best;
	best = straight_flush(cards);
	if (best->count() == 5) return best;

	//check four of kind
	
	//cout << "Check four kind" << endl;
	
	delete best;
	best = n_row(cards, 4); 
	if (best->count() == 4) return best;

	//check full house
	//cout << "Check full house" << endl;
	
	delete best;
	best = full_house(cards);	
	if (best->count() == 5) return best;
	
	//check flush
	//cout << "Check flush" << endl;
	
	delete best;
	best = flush(cards);
	if (best->count() == 5) return best;

	//straight aces are 1s and 14s	
	//cout << "Check straight" << endl;
	
	delete best;
	best = straight(cards);
	if (best->count() == 5) return best;

	//three of a kind
	
	//cout << "Check THREE" << endl;
	
	delete best;
	best = n_row(cards, 3); 
	if (best->count() == 3) return best;
	
	//two pairs
	
	//cout << "Check TWO" << endl;
	
	delete best;
	best = double_pair(cards);
	if (best->count() == 4) return best;

	//pairs
	
	//cout << "Check PAIR" << endl;
	
	delete best;
	best = n_row(cards, 2); 
	if (best->count() == 2) return best;
	
	//high card
	
	//cout << "Check single" << endl;
	
	delete best;
	best = n_row(cards, 1); 
	if (best->count() == 1) return best;

	return best;
}

