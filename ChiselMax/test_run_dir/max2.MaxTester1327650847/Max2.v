module Max2(
  input        clock,
  input        reset,
  input  [7:0] io_in0,
  input  [7:0] io_in1,
  output [7:0] io_out
);
  wire  _T_11; // @[max2.scala 11:24]
  wire [7:0] _T_12; // @[max2.scala 11:16]
  assign _T_11 = io_in0 > io_in1; // @[max2.scala 11:24]
  assign _T_12 = _T_11 ? io_in0 : io_in1; // @[max2.scala 11:16]
  assign io_out = _T_12;
endmodule
