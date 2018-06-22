// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VMax2__Syms.h"


//======================

void VMax2::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VMax2* t=(VMax2*)userthis;
    VMax2__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
	t->traceChgThis (vlSymsp, vcdp, code);
    }
}

//======================


void VMax2::traceChgThis(VMax2__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMax2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VMax2::traceChgThis__2(VMax2__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMax2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+1,(vlTOPp->clock));
	vcdp->chgBit  (c+2,(vlTOPp->reset));
	vcdp->chgBus  (c+3,(vlTOPp->io_in0),8);
	vcdp->chgBus  (c+4,(vlTOPp->io_in1),8);
	vcdp->chgBus  (c+5,(vlTOPp->io_out),8);
    }
}
