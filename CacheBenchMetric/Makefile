#cacheBenchMetric MULTIPLE PROCESSOR/PLATFORM MAKEFILE

SHELL = /bin/sh

ECHO 		= echo
FLAGS 		= -fopenmp
DEBUGFLAGS 	= -g -p -pg -fprofile-arcs  -lrt

METRIC_TARGET_ARM 	= cacheBenchMetricARM.exe
METRIC_TARGET_RISCV = cacheBenchMetricRISCV.exe
METRIC_TARGET_INTEL = cacheBenchMetricINTEL.exe
METRICSOURCES	= $(shell echo ./src/*.c)
METRIC_OBJECTS	= $(METRICSOURCES:.c=.o)
LIBS	= -lm

intel:	CC	= /usr/bin/gcc
intel:	CC_LINKER	= /usr/bin/gcc
intel:	CC_LINKER_FLAGS = --sysroot=/ -lstdc++ -lm -o
intel:	MISCOPTS	= -c -pipe --sysroot=/
intel:	RELEASEFLAGS	= -O3
intel:	INCLUDES	= -I/usr/include -I ./src
intel: $(METRIC_TARGET_INTEL)
	@echo Built METRIC_TARGET_INTEL

$(METRIC_TARGET_INTEL): $(METRIC_OBJECTS)
	@echo Building CacheBenchMetric for INTEL
	$(CC_LINKER) $(CC_LINKER_FLAGS) $(METRIC_TARGET_INTEL) $(METRIC_OBJECTS) $(LIBS)

arm:	CC	= /opt/iSpaceOS/2018.1/sysroots/x86_64-ispaceossdk-linux/usr/bin/aarch64-ispace-linux/aarch64-ispace-linux-gcc
arm:	CC_LINKER	= /opt/iSpaceOS/2018.1/sysroots/x86_64-ispaceossdk-linux/usr/bin/aarch64-ispace-linux/aarch64-ispace-linux-gcc
arm:	CC_LINKER_FLAGS = --sysroot=/opt/iSpaceOS/2018.1/sysroots/aarch64-ispace-linux  -fprofile-arcs -lstdc++ -lm -o
arm:	MISCOPTS	= -c -pipe -g -march=armv8-a+lse+crc -mtune=cortex-a53 --sysroot=/opt/iSpaceOS/2018.1/sysroots/aarch64-ispace-linux
arm:	RELEASEFLAGS	= -O2 -lrt -ffat-lto-objects -flto -mstrict-align -mcmodel=large
arm:	INCLUDES	= -I/opt/iSpaceOS/2018.1/sysroots/aarch64-ispace-linux/usr/include/c++/7.3.0 -I/opt/iSpaceOS/2018.1/sysroots/aarch64-ispace-linux/usr/include/c++/7.3.0/aarch64-ispace-linux -I/opt/iSpaceOS/2018.1/sysroots/aarch64-ispace-linux/usr/include -I ./src
arm: $(METRIC_TARGET_ARM)
	@echo Built METRIC_TARGET_ARM

$(METRIC_TARGET_ARM): $(METRIC_OBJECTS)
	@echo Building CacheBenchMetric for ARM
	$(CC_LINKER) $(CC_LINKER_FLAGS) $(METRIC_TARGET_ARM) $(METRIC_OBJECTS) $(LIBS)

riscv:	CC	= /opt/iSpaceOS/2018.1/sysroots/x86_64-ispaceossdk-linux/usr/bin/riscv64-ispace-linux/riscv64-ispace-linux-gcc
riscv:	CC_LINKER	= /opt/iSpaceOS/2018.1/sysroots/x86_64-ispaceossdk-linux/usr/bin/riscv64-ispace-linux/riscv64-ispace-linux-gcc
riscv:	CC_LINKER_FLAGS	= --sysroot=/opt/iSpaceOS/2018.1/sysroots/riscv64-ispace-linux -lstdc++ -lm -o
riscv:	MISCOPTS	= -c -pipe -g --sysroot=/opt/iSpaceOS/2018.1/sysroots/riscv64-ispace-linux
riscv:	RELEASEFLAGS	= -O3 -lrt -ffat-lto-objects -flto -mstrict-align -mcmodel=medany
riscv:	INCLUDES	= -I/opt/iSpaceOS/2018.1/sysroots/riscv64-ispace-linux/usr/include/c++/7.3.0 -I/opt/iSpaceOS/2018.1/sysroots/riscv64-ispace-linux/usr/include/c++/7.3.0/riscv64-ispace-linux -I/opt/iSpaceOS/2018.1/sysroots/riscv64-ispace-linux/usr/include -I ./src
riscv:	$(METRIC_TARGET_RISCV)
	@echo Built METRIC_TARGET_RISCV

$(METRIC_TARGET_RISCV): $(METRIC_OBJECTS)
	@echo Building CacheBenchMetric for RISCV
	$(CC_LINKER) $(CC_LINKER_FLAGS) $(METRIC_TARGET_RISCV) $(METRIC_OBJECTS) $(LIBS)

%.o: %.c $(HEADERS)
	@echo Building $<
	$(CC) $(INCLUDES) -o $@ -c $< $(FLAGS) $(RELEASEFLAGS) $(MISCOPTS)

clean:
	-rm -f $(METRIC_OBJECTS) ./src/*~

mv_riscv:
	-scp cacheBenchMetricRISCV.exe root@192.168.1.2:/tmp

mv_arm:
	-scp cacheBenchMetricARM.exe root@192.168.1.102:/tmp
