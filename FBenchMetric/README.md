# FBench Metric Benchmark

This  is  a  complete  optical	design	raytracing  algorithm, stripped of its
user interface and recast into portable C.  It not only determines execution
speed on an extremely floating point	(including   trig   function)	intensive
real-world application, it  checks  accuracy  on  an  algorithm  that  is
exquisitely  sensitive	to  errors.   The  performance of this program is
typically far more  sensitive  to  changes  in  the efficiency  of	the  
trigonometric  library  routines than the average floating point program.

This code can be compiled/linked for three different platforms: INTEL, ARM, RISCV.

To build the various platform versions, make the following:

make intel

make arm

make riscv

Note: before making, do a "make clean"
