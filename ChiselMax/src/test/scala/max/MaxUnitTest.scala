package max2

import chisel3.iotesters
import chisel3.iotesters.{ChiselFlatSpec, Driver, PeekPokeTester}

class MaxUnitTester(c: Max2) extends PeekPokeTester(c) {
    
}

class MaxTester extends ChiselFlatSpec {
    private val backendNames = if(firrtl.FileUtils.isCommandAvailable("verilator")) {
        Array("firrtl", "verilator")
    }
    else {
        Array("firrtl")
    }

    for ( backendName <- backendNames ) {
        "Max2" should s"calculate proper greatest common denominator (with $backendName)" in {
            Driver(() => new Max2, backendName) {
                c => new MaxUnitTester(c)
            } should be (true)
        }
    }

    "Basic test using Driver.execute" should "be used as an alternative way to run specification" in {
        iotesters.Driver.execute(Array(), () => new Max2) {
            c => new MaxUnitTester(c)
        } should be (true)
    }

    "using --backend-name verilator" should "be an alternative way to run using verilator" in {
        if(backendNames.contains("verilator")) {
            iotesters.Driver.execute(Array("--backend-name", "verilator"), () => new Max2) {
                c => new MaxUnitTester(c)
            } should be(true)
        }
    }

    "running with --is-verbose" should "show more about what's going on in your tester" in {
        iotesters.Driver.execute(Array("--is-verbose"), () => new Max2) {
            c => new MaxUnitTester(c)
        } should be(true)
    }

    "running with --fint-write-vcd" should "create a vcd file from your test" in {
        iotesters.Driver.execute(Array("--fint-write-vcd"), () => new Max2) {
            c => new MaxUnitTester(c)
        } should be(true)
    }

    "using --help" should s"show the many options available" in {
        iotesters.Driver.execute(Array("--help"), () => new Max2) {
            c => new MaxUnitTester(c)
        } should be (true)
    }

}