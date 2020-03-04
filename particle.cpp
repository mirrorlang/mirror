#include "particle.h";
#include <string>
#include <iostream>;

 
std::string  particle_tostring(particle c) {
	switch (c) {
	case particle::null:return "null"; break;

	case particle::truee:return "true"; break;
	case particle::falsee:return "false"; break;

	case particle::equal:return "=="; break;
	case particle::notequal:return "!="; break;

	case particle::andd:return "&"; break;
	case particle::xorr:return "^"; break;
	case particle::orr:return "|"; break;
	case particle::nott:return "~"; break;

	case particle::leftshift:return "<<"; break;
	case particle::rightshift:return ">>"; break;
	};
	return "?";
}




void particle_op::computerewrite(particle op, byte  a[], int64 sa) {
	switch (op)
	{
	case particle::null:
		for (int i = 0; i < sizeof(a); i++) {
			a[i] = 0;
		}

		break;
	case particle::nott:
		for (int i = 0; i < sizeof(a); i++) {
			a[i] = ~a[i];
		}

		break;
	case particle::leftshift:

		break;
	case particle::rightshift:

		break;

	default:
		break;
	}
}


byte* particle_op::compute(particle op, byte  a[], int64 sa) {
	byte* output=NULL;
	switch (op)
	{
	case particle::nott:
			output = new byte[sizeof(a)]{ };
			for (int i = 0; i < sizeof(a); i++) {
				output[i] = ~a[i];
			}
		break;
	case particle::leftshift:
		 
		break;
	case particle::rightshift:
		 
		break;

	default:
		break;
	}
	return output;
}

byte* particle_op::compute(particle op, byte  a[], int64 sa, byte  b[], int64 sb) {
	byte* output = NULL;
	int64 maxl = (sa> sb ? sa :sb);
	int64 minl = (sa < sb ? sa : sb);
	switch (op)
	{
	case particle::equal:
		if (sizeof(a) == sizeof(b)) {
			for (int i = 0; i < sizeof(a); i++) {
				if (a[i] != b[i]) {
					output = new byte[1]{ (byte)particle::falsee };
					return output;
				}
			}
			output = new byte[1]{ (byte)particle::truee };
		}
		break;
	case particle::notequal:
		if (sizeof(a) == sizeof(b)) {
			for (int i = 0; i < sizeof(a); i++) {
				if (a[i] != b[i]) {
					output = new byte[1]{ (byte)particle::truee };
					return output;
				}
			}
			output = new byte[1]{ (byte)particle::falsee };
		}
		break;
	case particle::orr:
			output = new byte[maxl]{ };
			for (int i = 0; i < minl; i++) {
				output[i] = a[i] | b[i];
			}
		 
		break;
	case particle::xorr:
			output = new byte[maxl]{ };
			for (int i = 0; i < minl; i++) {
				output[i] = a[i] ^ b[i];
			}
		break;
	case particle::andd:
			output = new byte[maxl]{ };
			for (int i = 0; i < minl; i++) {
				output[i] = a[i] & b[i];
			}
		 
		break;
	default:
		break;
	}
	return output;
}