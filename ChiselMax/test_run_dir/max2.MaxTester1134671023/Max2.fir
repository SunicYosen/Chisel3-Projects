;buildInfoPackage: chisel3, version: 3.1.0, scalaVersion: 2.11.12, sbtVersion: 1.1.1, builtAtString: 2018-04-17 19:22:56.455, builtAtMillis: 1523992976455
circuit Max2 : 
  module Max2 : 
    input clock : Clock
    input reset : UInt<1>
    output io : {flip in0 : UInt<8>, flip in1 : UInt<8>, out : UInt<8>}
    
    node _T_11 = gt(io.in0, io.in1) @[max2.scala 11:24]
    node _T_12 = mux(_T_11, io.in0, io.in1) @[max2.scala 11:16]
    io.out <= _T_12 @[max2.scala 11:10]
    
