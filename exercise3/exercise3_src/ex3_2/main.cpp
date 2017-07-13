#include "systemc.h"
#include "src.h"
#include "dst.h"

int sc_main(int argc, char *argv[])  // cf. C++ main()
{
	/*	Here the source is simply connected to destination */

	sc_fifo<int> a_fifo_channel;

	src	data_source("data_source");
	dst	data_destination("data_destination");

	data_destination.input(a_fifo_channel);
	data_source.output(a_fifo_channel);
	
	sc_start();

	cout << endl <<"simulation finished" << endl;
	return 0;
}



