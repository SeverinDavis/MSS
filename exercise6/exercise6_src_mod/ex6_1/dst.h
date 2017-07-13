#ifndef _DST_H_
#define _DST_H_

#define SC_INCLUDE_DYNAMIC_PROCESSES
#include <systemc>
#include <tlm.h>


#define TRANS tlm::tlm_base_protocol_types::tlm_payload_type
#define PHASE tlm::tlm_base_protocol_types::tlm_phase_type

class dst_unit : sc_core::sc_module, tlm::tlm_fw_transport_if<> {
public:
	SC_CTOR(dst_unit) {
		tgt_socket.bind(*this);
	}


	tlm::tlm_target_socket<> tgt_socket;
	void b_transport(tlm::tlm_generic_payload&, sc_core::sc_time&);

	tlm::tlm_sync_enum tlm::tlm_fw_nonblocking_transport_if<TRANS, PHASE>::nb_transport_fw(TRANS&, PHASE&, sc_core::sc_time &)
	{
		return tlm::tlm_sync_enum::TLM_COMPLETED;
	}
	bool tlm::tlm_fw_direct_mem_if<TRANS>::get_direct_mem_ptr(TRANS &, tlm::tlm_dmi &)
	{
		return false;
	}
	unsigned int tlm::tlm_transport_dbg_if<TRANS>::transport_dbg(TRANS &)
	{
		return 0;
	}
}; // END SC_MODULE "dst_unit"

#endif // _DST_H_

