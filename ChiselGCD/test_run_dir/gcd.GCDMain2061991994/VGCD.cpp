// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VGCD.h for the primary calling header

#include "VGCD.h"              // For This
#include "VGCD__Syms.h"

//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(VGCD) {
    VGCD__Syms* __restrict vlSymsp = __VlSymsp = new VGCD__Syms(this, name());
    VGCD* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VGCD::__Vconfigure(VGCD__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VGCD::~VGCD() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void VGCD::eval() {
    VGCD__Syms* __restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    VGCD* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    VL_DEBUG_IF(VL_PRINTF("\n----TOP Evaluate VGCD::eval\n"); );
    int __VclockLoop = 0;
    QData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	VL_DEBUG_IF(VL_PRINTF(" Clock loop\n"););
	vlSymsp->__Vm_activity = true;
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
    }
}

void VGCD::_eval_initial_loop(VGCD__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    int __VclockLoop = 0;
    QData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
    }
}

//--------------------
// Internal Methods

VL_INLINE_OPT void VGCD::_sequent__TOP__1(VGCD__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VGCD::_sequent__TOP__1\n"); );
    VGCD* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at /home/sun/Desktop/Test/ChiselGCD/test_run_dir/gcd.GCDMain2061991994/GCD.v:68
    if (vlTOPp->io_loadingValues) {
	vlTOPp->GCD__DOT__x = vlTOPp->io_value1;
    } else {
	if (vlTOPp->GCD__DOT___T_17) {
	    vlTOPp->GCD__DOT__x = (0xffffU & vlTOPp->GCD__DOT___T_18);
	}
    }
    if (vlTOPp->io_loadingValues) {
	vlTOPp->GCD__DOT__y = vlTOPp->io_value2;
    } else {
	if ((1U & (~ (IData)(vlTOPp->GCD__DOT___T_17)))) {
	    vlTOPp->GCD__DOT__y = (0xffffU & vlTOPp->GCD__DOT___T_21);
	}
    }
    vlTOPp->io_outputGCD = vlTOPp->GCD__DOT__x;
    vlTOPp->io_outputValid = (0U == (IData)(vlTOPp->GCD__DOT__y));
    vlTOPp->GCD__DOT___T_17 = ((IData)(vlTOPp->GCD__DOT__x) 
			       > (IData)(vlTOPp->GCD__DOT__y));
    vlTOPp->GCD__DOT___T_18 = (0x1ffffU & ((IData)(vlTOPp->GCD__DOT__x) 
					   - (IData)(vlTOPp->GCD__DOT__y)));
    vlTOPp->GCD__DOT___T_21 = (0x1ffffU & ((IData)(vlTOPp->GCD__DOT__y) 
					   - (IData)(vlTOPp->GCD__DOT__x)));
}

void VGCD::_settle__TOP__2(VGCD__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VGCD::_settle__TOP__2\n"); );
    VGCD* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_outputGCD = vlTOPp->GCD__DOT__x;
    vlTOPp->io_outputValid = (0U == (IData)(vlTOPp->GCD__DOT__y));
    vlTOPp->GCD__DOT___T_17 = ((IData)(vlTOPp->GCD__DOT__x) 
			       > (IData)(vlTOPp->GCD__DOT__y));
    vlTOPp->GCD__DOT___T_18 = (0x1ffffU & ((IData)(vlTOPp->GCD__DOT__x) 
					   - (IData)(vlTOPp->GCD__DOT__y)));
    vlTOPp->GCD__DOT___T_21 = (0x1ffffU & ((IData)(vlTOPp->GCD__DOT__y) 
					   - (IData)(vlTOPp->GCD__DOT__x)));
}

void VGCD::_eval(VGCD__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VGCD::_eval\n"); );
    VGCD* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
	vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void VGCD::_eval_initial(VGCD__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VGCD::_eval_initial\n"); );
    VGCD* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VGCD::final() {
    VL_DEBUG_IF(VL_PRINTF("    VGCD::final\n"); );
    // Variables
    VGCD__Syms* __restrict vlSymsp = this->__VlSymsp;
    VGCD* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VGCD::_eval_settle(VGCD__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VGCD::_eval_settle\n"); );
    VGCD* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

VL_INLINE_OPT QData VGCD::_change_request(VGCD__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VGCD::_change_request\n"); );
    VGCD* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

void VGCD::_ctor_var_reset() {
    VL_DEBUG_IF(VL_PRINTF("    VGCD::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_value1 = VL_RAND_RESET_I(16);
    io_value2 = VL_RAND_RESET_I(16);
    io_loadingValues = VL_RAND_RESET_I(1);
    io_outputGCD = VL_RAND_RESET_I(16);
    io_outputValid = VL_RAND_RESET_I(1);
    GCD__DOT__x = VL_RAND_RESET_I(16);
    GCD__DOT__y = VL_RAND_RESET_I(16);
    GCD__DOT___T_17 = VL_RAND_RESET_I(1);
    GCD__DOT___T_18 = VL_RAND_RESET_I(17);
    GCD__DOT___T_21 = VL_RAND_RESET_I(17);
    __Vclklast__TOP__clock = VL_RAND_RESET_I(1);
    __Vm_traceActivity = VL_RAND_RESET_I(32);
}

void VGCD::_configure_coverage(VGCD__Syms* __restrict vlSymsp, bool first) {
    VL_DEBUG_IF(VL_PRINTF("    VGCD::_configure_coverage\n"); );
    // Body
    if (0 && vlSymsp && first) {} // Prevent unused
}
