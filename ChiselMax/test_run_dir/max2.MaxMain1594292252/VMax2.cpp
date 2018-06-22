// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VMax2.h for the primary calling header

#include "VMax2.h"             // For This
#include "VMax2__Syms.h"

//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(VMax2) {
    VMax2__Syms* __restrict vlSymsp = __VlSymsp = new VMax2__Syms(this, name());
    VMax2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VMax2::__Vconfigure(VMax2__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VMax2::~VMax2() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void VMax2::eval() {
    VMax2__Syms* __restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    VMax2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    VL_DEBUG_IF(VL_PRINTF("\n----TOP Evaluate VMax2::eval\n"); );
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

void VMax2::_eval_initial_loop(VMax2__Syms* __restrict vlSymsp) {
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

VL_INLINE_OPT void VMax2::_combo__TOP__1(VMax2__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VMax2::_combo__TOP__1\n"); );
    VMax2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_out = (((IData)(vlTOPp->io_in0) > (IData)(vlTOPp->io_in1))
		       ? (IData)(vlTOPp->io_in0) : (IData)(vlTOPp->io_in1));
}

void VMax2::_eval(VMax2__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VMax2::_eval\n"); );
    VMax2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void VMax2::_eval_initial(VMax2__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VMax2::_eval_initial\n"); );
    VMax2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VMax2::final() {
    VL_DEBUG_IF(VL_PRINTF("    VMax2::final\n"); );
    // Variables
    VMax2__Syms* __restrict vlSymsp = this->__VlSymsp;
    VMax2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VMax2::_eval_settle(VMax2__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VMax2::_eval_settle\n"); );
    VMax2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData VMax2::_change_request(VMax2__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VMax2::_change_request\n"); );
    VMax2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

void VMax2::_ctor_var_reset() {
    VL_DEBUG_IF(VL_PRINTF("    VMax2::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_in0 = VL_RAND_RESET_I(8);
    io_in1 = VL_RAND_RESET_I(8);
    io_out = VL_RAND_RESET_I(8);
    __Vm_traceActivity = VL_RAND_RESET_I(32);
}

void VMax2::_configure_coverage(VMax2__Syms* __restrict vlSymsp, bool first) {
    VL_DEBUG_IF(VL_PRINTF("    VMax2::_configure_coverage\n"); );
    // Body
    if (0 && vlSymsp && first) {} // Prevent unused
}
