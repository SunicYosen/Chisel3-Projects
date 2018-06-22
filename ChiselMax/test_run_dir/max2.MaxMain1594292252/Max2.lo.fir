circuit Max2 : @[:@2.0]
  module Max2 : @[:@3.2]
    input clock : Clock @[:@4.4]
    input reset : UInt<1> @[:@5.4]
    input io_in0 : UInt<8> @[:@6.4]
    input io_in1 : UInt<8> @[:@6.4]
    output io_out : UInt<8> @[:@6.4]
  
    node _T_11 = gt(io_in0, io_in1) @[max2.scala 12:24:@8.4]
    node _T_12 = mux(_T_11, io_in0, io_in1) @[max2.scala 12:16:@9.4]
    io_out <= _T_12
