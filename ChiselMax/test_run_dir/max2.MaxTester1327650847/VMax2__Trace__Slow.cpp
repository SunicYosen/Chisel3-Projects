// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VMax2__Syms.h"


//======================

void VMax2::trace (VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback (&VMax2::traceInit, &VMax2::traceFull, &VMax2::traceChg, this);
}
void VMax2::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    VMax2* t=(VMax2*)userthis;
    VMax2__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) vl_fatal(__FILE__,__LINE__,__FILE__,"Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    vcdp->scopeEscape(' ');
    t->traceInitThis (vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void VMax2::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VMax2* t=(VMax2*)userthis;
    VMax2__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    t->traceFullThis (vlSymsp, vcdp, code);
}

//======================


void VMax2::traceInitThis(VMax2__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMax2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name()); // Setup signal names
    // Body
    {
	vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void VMax2::traceFullThis(VMax2__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMax2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VMax2::traceInitThis__1(VMax2__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMax2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->declBit  (c+1,"clock",-1);
	vcdp->declBit  (c+2,"reset",-1);
	vcdp->declBus  (c+3,"io_in0",-1,7,0);
	vcdp->declBus  (c+4,"io_in1",-1,7,0);
	vcdp->declBus  (c+5,"io_out",-1,7,0);
	vcdp->declBit  (c+1,"Max2 clock",-1);
	vcdp->declBit  (c+2,"Max2 reset",-1);
	vcdp->declBus  (c+3,"Max2 io_in0",-1,7,0);
	vcdp->declBus  (c+4,"Max2 io_in1",-1,7,0);
	vcdp->declBus  (c+5,"Max2 io_out",-1,7,0);
	// Tracing: Max2 _T_11 // Ignored: Inlined leading underscore at /home/sun/Desktop/Test/ChiselMax/test_run_dir/max2.MaxTester1327650847/Max2.v:8
	// Tracing: Max2 _T_12 // Ignored: Inlined leading underscore at /home/sun/Desktop/Test/ChiselMax/test_run_dir/max2.MaxTester1327650847/Max2.v:9
    }
}

void VMax2::traceFullThis__1(VMax2__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMax2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->fullBit  (c+1,(vlTOPp->clock));
	vcdp->fullBit  (c+2,(vlTOPp->reset));
	vcdp->fullBus  (c+3,(vlTOPp->io_in0),8);
	vcdp->fullBus  (c+4,(vlTOPp->io_in1),8);
	vcdp->fullBus  (c+5,(vlTOPp->io_out),8);
    }
}
