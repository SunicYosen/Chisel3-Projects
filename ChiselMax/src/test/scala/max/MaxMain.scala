package max2

import chisel3._

object MaxMain extends App {
  iotesters.Driver.execute(args, () => new Max2) {
    c => new MaxUnitTester(c)
  }
}

object MaxRepl extends App {
  iotesters.Driver.executeFirrtlRepl(args, () => new Max2)
}