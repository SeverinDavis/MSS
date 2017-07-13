#include "testbench.h"
void Testbench::stim()  // SC_THREAD
{
  wait(10, SC_NS);
  ch_x.write(3); ch_y.write(4);   // first stimulus
  wait(10, SC_NS);      // wait for 10 ns
  ch_x.write(7); ch_y.write(0);   // second stimulus
  wait(10, SC_NS);      // wait (no sensitivity!)
                        // further stimuli
  ch_x.write(8); ch_y.write(-4);
  wait(10, SC_NS);
  ch_x.write(8); ch_y.write(-4);
  wait(10, SC_NS);
}
void Testbench::check() // SC_METHOD
{
	for (;;)
	{
		cout << "added" << ch_s.read() << endl;
	
	}

}
