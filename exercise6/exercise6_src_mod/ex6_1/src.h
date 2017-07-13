#ifndef _SRC_H_
#define _SRC_H_

#define SC_INCLUDE_DYNAMIC_PROCESSES
#include <systemc>
#include <tlm.h>

#define TRANS tlm::tlm_base_protocol_types::tlm_payload_type
#define PHASE tlm::tlm_base_protocol_types::tlm_phase_type

class src_unit : sc_core::sc_module, tlm::tlm_bw_transport_if<> {
public:
  SC_CTOR(src_unit) {
    // register SystemC threads
    SC_THREAD(generate);
    init_socket.bind(*this);
  }


  tlm::tlm_initiator_socket<> init_socket;

  virtual tlm::tlm_sync_enum tlm::tlm_bw_nonblocking_transport_if<TRANS, PHASE>::nb_transport_bw(TRANS &, PHASE &, sc_core::sc_time &)
  {
	  return tlm::tlm_sync_enum::TLM_COMPLETED;
  }
  
  virtual void tlm::tlm_bw_direct_mem_if::invalidate_direct_mem_ptr(sc_dt::uint64, sc_dt::uint64)
  {
	  return;
  }

  void generate();

}; // END SC_MODULE "src_unit"

#endif

