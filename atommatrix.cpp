#include "atommatrix.h"
#include <string>

AtomS::AtomS(Atom* d, int64 l) {
	data = d;
	count = l;
}

std::string AtomArray::tostring() {
	std::string  values;
	values += "[";
	for (int i = 0; i < count; i++) {
		values += data[i].tostring()+",";
	}
	values=values.substr(0, values.length() - 1);
	values += "]";
	return values;
}