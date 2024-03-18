#include "Hand.h"
#include "Card.h"

using namespace std;

//Default initialize
Hand::Hand() {
	num = 0;
	capacity = 2;
	card_list = new Card[2];
}


//initialize as a copy of another hand
Hand::Hand(const Hand& other) {
	num = other.num; 
	capacity = other.capacity;

	card_list = new Card[capacity];
	for (size_t i = 0; i < num; i++) {
		card_list[i] = other.card_list[i];
	}	
}


//Dump everything in the hand
Hand::~Hand() {
	delete[] card_list;	
}


//Add a card to hand
void Hand::add(Card card) {
	num++;
	if (num > capacity) {
		Card* temp_list = new Card[capacity*2];
		bool in = false;
		int k = 0;
		for (size_t i = 0; i < capacity+1; i++) {
			if (i == capacity && !in) {
				temp_list[i] = card;
				break;
			}
			if (card > card_list[k] && !in) {
				temp_list[i] = card;
				in = true;
				k--;
			} else {
				temp_list[i] = card_list[k];
			}
			k++;
		}
		delete[] card_list;
		card_list = temp_list;
		capacity *= 2;
	} else {
		Card* temp_list = new Card[capacity];
		bool in = false;
		int k = 0;
		for (size_t i = 0; i < num; i++) {
			if (i == num-1 && !in) {
				temp_list[i] = card;
				continue;
			}
			if (card > card_list[k] && !in) {
				temp_list[i] = card;
				in = true;
				k--;
			} else {
				temp_list[i] = card_list[k];
			}
			k++;
		}
		delete[] card_list;
		card_list = temp_list;
	}
}


//Clear the hand
void Hand::clear() 	{
	delete[] card_list;
	card_list = new Card[2];
	num = 0;
	capacity = 2;
}


//Get number of cards in hand
size_t Hand::count() const {
	return num;
}

//get the index
Card Hand::get(size_t index) const {
	return card_list[index];
}

//print
void Hand::print() const {
	for (size_t i = 0; i < num; i++) {
		card_list[i].print();
		if (i < num-1) {
			cout << " ";
		}
	}
}

Hand* make_hand() {
	return new Hand();
}

