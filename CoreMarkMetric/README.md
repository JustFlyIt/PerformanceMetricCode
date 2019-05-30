# Dhrystone Metric Benchmark

CoreMark is a synthetic benchmark that measures the performance
of central processing units (CPU) used in embedded systems. It was developed in
2009 by Shay Gal-On at EEMBC and is intended to become an industry standard,
replacing the antiquated Dhrystone benchmark. The code is written in C and
contains implementations of the following algorithms: list processing
(find and sort), matrix manipulation (common matrix operations), state machine
(determine if an input stream contains valid numbers), and CRC.

See this link for additional information:  https://en.wikipedia.org/wiki/Coremark

This code can be compiled/linked for three different platforms: INTEL, ARM, RISCV.

To build the various platform versions, make the following:

make intel

make arm

make riscv

Note: before making, do a "make clean"
