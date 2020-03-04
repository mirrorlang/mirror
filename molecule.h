#pragma once
#include "atom.h"
class AtomArray {

};
class AtomMatrix:public AtomArray{

};
class Molecule
{
	std::string tostring();
	int64 sizeoff();
	int64 atomcount();
};
//1Ԫ���ʽ
//null����
//not����
//λ������
class Op1_0Molecule :public Molecule {
public:
	Atom* A;
	OpAtom Op;
	Op1_0Molecule(OpAtom op, Atom* a) :Op(op), A(a){};
};

//1Ԫ���ʽ
//not����
//λ������
class Op1_1Molecule :public Molecule {
public:
	Atom* A;
	Atom* Out;
	OpAtom Op;
	Op1_1Molecule(OpAtom op, Atom* a, Atom* out) :Op(op), A(a),Out(out) {};
};


//2Ԫ���ʽ
// == !=
// and or  xor
// + - * /
class Op2_1Molecule :public Molecule {
public:
	Atom* A;
	Atom* B;
	Atom* Out;
	OpAtom Op;
	Op2_1Molecule(OpAtom op, Atom* a,Atom* b, Atom* out) :Op(op), A(a), B(b), Out(out) {};
};

//������
//goto next
// call
// if else
// switch
// for
// while
// repeat break
class ControllFlow_Molecule :public Molecule {
	//public:
	//	Molecule 
};
