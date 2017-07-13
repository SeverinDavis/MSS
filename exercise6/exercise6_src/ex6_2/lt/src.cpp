#include "src.h"

#define SC_INCLUDE_DYNAMIC_PROCESSES
#include <systemc>
#include <tlm.h>


using namespace sc_core;
using namespace tlm;
void src_unit::generate() {

  tlm_generic_payload trans;
  sc_time t;

  unsigned char* pData;

  // prepare data to read the number of words to be processed
    int data;
    pData = reinterpret_cast<unsigned char*>(&data);
    trans.set_data_ptr(pData);
    trans.set_data_length(4);
    trans.set_address(0);
    trans.set_read();
    trans.set_response_status(TLM_INCOMPLETE_RESPONSE);
    t = SC_ZERO_TIME;
// <-- enter your implementation here
    
    pData = trans.get_data_ptr(); 
    int mem_size = *(reinterpret_cast<int*>(pData)); 


// <-- enter your implementation here
// loop to read word from MEM and forward it to T 

    std::cout << "end of the simulation @" << sc_time_stamp()<< std::endl;
} 
// <-- enter your implementation here

