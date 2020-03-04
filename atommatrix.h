#ifndef atommatrix_h
#define atommatrix_h

#include "atom.h"

class AtomS
{
public:
	Atom* data;
	int64 count;
	AtomS(Atom* d, int64 l);
	virtual std::string tostring() = 0;
};

class AtomArray :public AtomS {
public :
	AtomArray(Atom* d, int64 l) :AtomS(d,l) {};
	std::string tostring();
};

#endif