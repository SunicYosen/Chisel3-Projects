package max2

import chisel3._
import chisel3.iotesters.{PeekPokeTester, Driver}

class Max2 extends Module {
  val io = IO(new Bundle {
    val in0 = Input(UInt(8.W));
    val in1 = Input(UInt(8.W));
    val out = Output(UInt(8.W));
  })
  io.out := Mux(io.in0 > io.in1,io.in0,io.in1);
}

/*
object Max2 {
  def main(args: Array[String]): UInt = {
    iotesters.Driver.execute(args, () => new Max2) {
      c => new MaxUnitTester(c)
    }
  }
}

*/