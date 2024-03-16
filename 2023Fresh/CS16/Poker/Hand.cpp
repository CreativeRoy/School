#include "Hand.h"
#include "Card.h"

using namespace std;

//Default initialize
Hand::Hand() {
	card_list = new Card[1];
}


//initialize as a copy of another hand
Hand::Hand(const Hand& other) {
	int new_len = other.count(); 
	card_list = new Card[new_len + 1];
	for (int i = 1; i <= new_len; i++) {
		card_list[i] = other.get(i-1);
	}	
}


//Dump everything in the hand
Hand::~Hand() {
	delete[] card_list;	
}


//Add a card to hand
void Hand::add(Card card) {
	Card* new_list = new Card[1 + (1 + count())];
	size_t inserted = 0;
	for (size_t i = 0; i < count()+1; i++) {
		if (i < count() && get(i) <= card && 
				inserted == 0) {
			new_list[i+1] = card;	
			inserted = 1;
		} else {
			new_list[i+1+inserted] = get(i);
		}
	}
	delete[] card_list;
	card_list = new Card[2 + count()];
	for (size_t i = 1; i < count()+1; i++) {
		card_list[i] = new_list[i];
	}
	delete[] new_list;
}


//Clear the hand
void Hand::clear() 	{
	delete[] card_list;
	card_list = new Card[1];
}


//Get number of cards in hand
size_t Hand::count() const {
	return sizeof(card_list)-1;
}

//get the index
Card Hand::get(size_t index) const {
	return card_list[index-1];
}

//print
void Hand::print() const {
	for (size_t i = 1; i <= count(); i++) {
		card_list[i].print();
		if (i <= count()-1) {
			cout << " ";
		}
	}
}


Hand* make_hand() {
	return new Hand();
}


//best hand
Hand* best_hand(const Hand& cards);


