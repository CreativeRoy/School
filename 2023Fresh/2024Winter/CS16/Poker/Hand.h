#include "Card.h"
#include <cstddef>

#ifndef HAND_H
#define HAND_H

class Hand {
	Card* card_list;	
	size_t num;
	size_t capacity;
	public:
		Hand();
		
		Hand(const Hand& other);
		
		~Hand();
	
		void add(Card card);
	
		void clear();
	
		size_t count() const;
	
		Card get(size_t index) const;
	
		void print() const;

};

Hand* make_hand();

Hand* best_hand(const Hand& cards);

#endif

