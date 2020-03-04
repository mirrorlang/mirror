
#include "atom.h"
 
#include <string>
#include <sstream>

Atom::Atom(byte d) {
	data = new byte[1]{ d };
	size = 1;
}
Atom::Atom(byte* d, int64 s)
{
	data = d;
	size = s;
}
std::string Atom::tobytestring(byte* d, int64 s)
{
	std::stringstream r;
	r<<"bytes["<<s<<"]=[";
	if (d) {
		//todo
		r << IntAtom::bytes2int(new byte[8]{ d[0] });
		for (int i = 1; i < s; i++) {
			int x = IntAtom::bytes2int(new byte[8]{ d[i] });
			r <<  " "<<x;
		}

	}


	r << "]";
	return r.str();
	;
}
std::string Atom::bytestring()
{
	return Atom::tobytestring(data,size);
}
BoolAtom::BoolAtom(byte d)
{
	data = new byte[1]{ d };

	if ((data[0] != (byte)particle::truee) && (data[0] != (byte)particle::falsee)) {
		throw* data;
	}
}
std::string BoolAtom::tostring()
{
	return particle_tostring((particle)data[0]);
}
int64 BoolAtom::sizeoff()
{
	return 1;
}



byte* IntAtom::long2bytes(int64 i)
{
	byte* bytes = new byte[8];
	*(int*)bytes = i;
	return bytes;
}
byte* IntAtom::int2bytes(int i)
{
	byte* bytes = new byte[4];
	*(int*)bytes = i;
	return bytes;
}
int IntAtom::bytes2int(byte* bytes)
{
	int64 addr = *(int64*)bytes;
	return addr;
}

int64 IntAtom::bytes2int64(byte* bytes)
{
	int64 addr = *(int64*)bytes;
	return addr;
}
IntAtom::IntAtom(int d)
{
	size = 4;
	data = int2bytes(d);
}
IntAtom::IntAtom(int64 d)
{
	size = 8;
	data = long2bytes(d);
}
std::string IntAtom::tostring() {
	switch (size) {
	case 4:return std::to_string(bytes2int(data));
	case 8:return std::to_string(bytes2int64(data));
	}
	
}
int64 IntAtom::sizeoff() {
	return size;
}




StringAtom::StringAtom(std::string str)
{
	size = str.length();
	data = new byte[size];
	byte* p = (byte*)str.data();
	memcpy(data,p, size);

}

std::string StringAtom::tostring()
{
	char* p = new char[size];
	memcpy(p, data, size);
	p[size] = 0;
	return std::string(p);
}
int64 StringAtom::sizeoff()
{
	return size;
}



std::string OpAtom::tostring()
{
	return particle_tostring((particle)data[0]);
}
int64 OpAtom::sizeoff()
{
	return 1;
}




std::string PointerAtom::tostring() {
	return std::string();
}

int64 PointerAtom::sizeoff()
{
	return 1;
}

 