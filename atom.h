#ifndef atom_h
#define atom_h

#include <string>  
#include "particle.h"
 
class Atom {
protected:
	int64 size;
public :
	byte* data;

	Atom(){};
	Atom(byte d);
	Atom(byte* d,int64 size);
	virtual std::string tostring() = 0;
	static std::string tobytestring(byte* d, int64 s);
	std::string bytestring();
	virtual int64 sizeoff() = 0;
};

class BoolAtom:public Atom {
public:

	BoolAtom(byte d);
	std::string tostring();
	int64 sizeoff();
};

class IntAtom :public Atom {


public:
	static  byte* long2bytes(int64 i);
	static  byte* int2bytes(int i);
	//byte转int
	static int64 bytes2int64(byte* bytes);
	static int bytes2int(byte* bytes);

	IntAtom(byte d) :Atom(d) {};
	IntAtom(byte* d,int64 s) :Atom(d,s) {};
	IntAtom(int d) ;
	IntAtom(int64 d) ;

	std::string tostring();
	int64 sizeoff();
};

class StringAtom :public Atom {
public:
	StringAtom(byte d) :Atom(d) {};
	StringAtom(byte* d, int64  size) :Atom(d, size) {};
	StringAtom(std::string str) ;
	std::string tostring();
	int64 sizeoff();
};



class OpAtom :public Atom {
public:
	OpAtom(particle d) :Atom((byte)d) {};

	std::string tostring();
	int64 sizeoff();
};




class PointerAtom :public Atom {
public:
	PointerAtom(byte d) :Atom(d) {};
	std::string tostring();
	int64 sizeoff();
};

#endif
