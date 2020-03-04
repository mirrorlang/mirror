
#ifndef particle_h
#define particle_h

#include <string>
#include <map>

typedef unsigned char byte;
typedef long long int64;
// 粒子 运算
enum class particle:byte{
	null=0,
	//逻辑运算
	truee=1,
	falsee=2,

	equal = 3,// ==
	notequal = 4, // !=

	//基本类型
	atom=5,
	molecule=6,

	//位运算
	andd = 38,// &
	xorr = 94, //^
	orr= 124,// | 
	nott = 126, // 
	leftshift=171,//<<
	rightshift=197, //>>

};

std::string  particle_tostring(particle c);

class particle_op {
public:
	static byte*  compute(particle p, byte  a[],int64 sa, byte  b[], int64 sb );
	static byte* compute(particle p, byte  a[],int64 sa );
	static void computerewrite(particle p, byte  a[],int64 sa);
};

#endif // !particle_op_h;


