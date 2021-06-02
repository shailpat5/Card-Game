#include <vector>
#include "CardFactory.h"
#include "Card.h"

class IllegalType : public exception
{
	virtual const char* what() const throw()
	{
		return "The type does not match this chain.";
	}
};

class Chain_Base {
public:
	virtual int sell() = 0;
	virtual int getSize() = 0;
	virtual string getCardID() = 0;
	virtual bool legal(Card*) = 0;

	friend ostream& operator << (ostream& output, const Chain_Base& base) {
		base.print(output);
		return output;
	};
	Chain_Base& operator+= (Card* card) {
		this->addCard(card);
		return *this;
	};

protected:
	virtual void addCard(Card*) = 0;
	virtual void print(ostream&) const = 0;
};

template <class T> class Chain : public Chain_Base, public vector<T*> {
public:
	// default constructor
	Chain();
	Chain(istream&, CardFactory*);

	Chain<T>& operator+= (Card* card);
	int sell();
	bool legal(Card*);

	friend ostream& operator << (ostream& output, Chain<T> chain) {
		output << chain.getCardID() << '\t';

		if (chain.getSize() > 0) {
			for (int i = 0; i < chain.getSize(); i++)
				output << chain.getCardID().at(0);
		}

		return output;
	};

	void addCard(Card*);
	int getSize();
	string getCardID();

protected:
	string cardID;
	void print(ostream& output) const {
		output << (*this);
	};
};


template<class T>
Chain<T>::Chain(istream& input, CardFactory* cardFactory)
{
	string chain;
	getline(input, chain, '\t');
	char cardID[64];
	Card* card;

	input.getline(cardID, 64);

	int i = 0;
	while (cardID[i] != NULL && cardID[i] != ' ') {
		card = (*cardFactory).generateCard(cardID);
		(*this).push_back(card);
		i++;
	}
}


template<class T>
Chain<T>& Chain<T>::operator+=(Card* card)
{
	try {
		if (cardID.compare((*card).getName()) == 0) {
			T* card = new T();
			this->push_back(card);
		}
	}
	catch(T* type){
		throw IllegalType();
	}

	return *this;
}

template<class T>
bool Chain<T>::legal(Card* card)
{
	return (cardID.compare((*card).getName()) == 0);
}

template<class T>
int Chain<T>::sell()
{
	T card;
	for (int cns = 4; cns > 0; cns--) {
		if (this->getSize() >= card.getCardsPerCoin(cns)) {
			return cns;

		}
	}

	return 0;
}

template<class T>
void Chain<T>::addCard(Card* card)
{
	(*this) += card;
}


//inline function definitions

template<class T>
inline Chain<T>::Chain()
{
	T card;
	cardID = card.getName();
}


template<class T>
inline int Chain<T>::getSize()
{
	return this->size();
}


template<class T>
inline string Chain<T>::getCardID()
{
	return cardID;
}