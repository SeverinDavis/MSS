#ifndef _ADDER_H_
#define _ADDER_H_

#include "systemc.h"
SC_MODULE(Adder)
{
  sc_fifo_in<int> x;
  sc_fifo_in<int> y;
  sc_fifo_out<int> s;

  void add();
  SC_CTOR(Adder)
  {
    SC_THREAD(add);
	sensitive << x.data_written() << y.data_written();
  }
};
#endif
