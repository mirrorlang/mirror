// ex.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>;

#include "atom.h"
#include "atommatrix.h"
#include "particle.h"
#include "console.h"
#include "codedriver.h"
 

void test_particle_op() {
	println("测试 particle");
	byte a[4] = { byte{11},byte{3},byte{2},byte{4} };
	byte b[4] = { byte{11},byte{2},byte{2},byte{4} };

	auto c=particle_op::compute(particle::equal,a,4, b,4);
	print(Atom::tobytestring(a,4)+" == "+ Atom::tobytestring(b, 4));
	std::cout << particle_tostring(particle(c[0])) << "\n";

	auto nc=particle_op::compute(particle::notequal,a,4, b,4);
	print(Atom::tobytestring(a, 4) + " != " + Atom::tobytestring(b, 4));
	std::cout << particle_tostring(particle(*nc)) << "\n";


}

void test_atom() {
	//
	println("测试int atom");
	byte int4t[4] = { byte{1},byte{1},byte{1},byte{1} };
	IntAtom intvar(int4t,4);
	println( intvar.bytestring()+" "+intvar.tostring());
	//atom int 测试
	 
	IntAtom intvar2=IntAtom(1);
	println(intvar2.bytestring() + ":" + intvar2.tostring());
		 
	intvar2= IntAtom(8);
	println(intvar2.bytestring() + ":" + intvar2.tostring());
		 
	intvar2 = IntAtom(new byte[4]{ byte{255},byte{255},byte{255},byte{127} },4);
	println(intvar2.bytestring() + ":" + intvar2.tostring());	 

	intvar2 = IntAtom(new byte[4]{ byte{255},byte{255},byte{255},byte{128} },4);
	println(intvar2.bytestring() + ":" + intvar2.tostring());
		
	intvar2 = IntAtom(-2147483647);
	println(intvar2.bytestring() + ":" + intvar2.tostring());
		 
	intvar2 = IntAtom(1024);
	println(intvar2.bytestring() + ":" + intvar2.tostring());

	byte int8t[8] = { byte{1},byte{1},byte{1},byte{1},byte{1},byte{1},byte{1},byte{1} };
	IntAtom inta(int8t, 8);
	println(inta.bytestring()+":"+ inta.tostring());

	println("测试string atom");
	byte s[12] = { 
		byte{1},byte{20},byte{35},byte{47},
		byte{54},byte{62},byte{77},byte{89},
		byte{93},byte{107},byte{119},byte{122} };
	StringAtom ss = StringAtom(s, 12);
	println( ss.bytestring()+""+ ss.tostring());

	StringAtom s2 = StringAtom("[1+1234]");
	println( s2.bytestring()+""+ s2.tostring());
}
void test_molecule() {

}
void test() {
	test_particle_op();
	test_atom();
	test_molecule();
}

int main() {
	test();
	getchar();
	//Mainloop();
};
