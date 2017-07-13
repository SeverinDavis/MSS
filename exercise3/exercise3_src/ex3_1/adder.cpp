#include "adder.h"
void Adder::add()
{
	int a, b;
	for(;;)
	{
		wait();
		cout << "adder fired" << endl;
		a = x.read();
		b = y.read();
		s.write(a + b);
	}
}
