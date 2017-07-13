#include "master.h"
#include "ram.h"
#include "bus_pv.h"
#include "debug_if.h"
#include <fstream>

int sc_main(int argc, char *argv[])
{
  Master master1("master1", 0, 17, 0);
  Ram    ram1("ram1", 0, 16);
  Master master2("master2", 20, 31, 1);
  Ram    ram2("ram2", 16,16);
  Bus_pv bus("bus");
  master1.initiator_port(bus.bus_export);
  master2.initiator_port(bus.bus_export);
  bus.bus_port(ram1.target_export);
  bus.bus_port(ram2.target_export);
  sc_start();

  std::filebuf fb;
  fb.open("test.txt", std::ios::out);
  std::ostream os(&fb);
  ram1.dump(os);
  ram2.dump(os);
  fb.close();
  return 0;
}
