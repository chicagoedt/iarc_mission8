# Example Makefile that wrappers snowboy c++ library (snowboy-detect.a) through
# JNI interface, using swig.

# When you extract Android toolchain from Android NDK, make sure you supply
# --stl=libc++ option. This Makefile is optimized for armv7-a architecture.

# Please use swig-3.0.10 or up.
SWIG := swig

# Please specify your NDK root directory here.
NDKDIR := /Users/guoguo/snowboy-release/swig/Android/
NDKINSTALLEDROOT := $(NDKDIR)/ndk_install
NDKROOT := $(NDKDIR)/android-ndk-r11c

SNOWBOYDETECTSWIGITF = snowboy-swig.i
SNOWBOYDETECTSWIGOBJ = snowboy-swig.o
SNOWBOYDETECTSWIGCC = snowboy-swig.cc
SNOWBOYDETECTJAVAPKG = ai.kitt.snowboydemo
SNOWBOYDETECTJAVAPKGDIR = java/ai/kitt/snowboydemo/
SNOWBOYDETECTSWIGLIBFILE = libsnowboy-android.so
OPENBLASLIBFILE = ../Android/OpenBLAS-Android/libopenblas.a

ARCH := arm
TOPDIR := ../../
LDFLAGS :=

CXXFLAGS := -O3 --sysroot=$(NDKINSTALLEDROOT)/sysroot
LDLIBS := -L$(NDKINSTALLEDROOT)/sysroot/usr/lib

ifeq ($(ARCH), arm)
  AR := $(NDKINSTALLEDROOT)/bin/arm-linux-androideabi-ar
  CC := $(NDKINSTALLEDROOT)/bin/arm-linux-androideabi-gcc
  CXX := $(NDKINSTALLEDROOT)/bin/arm-linux-androideabi-g++
  STRIP := $(NDKINSTALLEDROOT)/bin/arm-linux-androideabi-strip
  OPENBLASTARGET := ARMV7
  SNOWBOYDETECTLIBFILE = /Users/guoguo/snowboy-clean/src/lib/libsnowboy.a
  CXXFLAGS += -std=c++0x -rdynamic -I$(TOPDIR) -Werror -Wall \
      -fsigned-char -fpic -fPIC -mfloat-abi=softfp -march=armv7-a -mfpu=neon \
      -DNDEBUG -ffast-math -fomit-frame-pointer -O3 -pie -fPIE -DHAVE_NEON=1 \
      -fno-strict-aliasing -Wno-unused-function -shared
  LDLIBS += \
      -L$(NDKROOT)/sources/cxx-stl/gnu-libstdc++/4.9/libs/armeabi-v7a \
      -lgnustl_static -lsupc++ -lgcc -ldl -lc -lm -llog -pthread
  SNOWBOYDETECTSWIGLIBFILE := jniLibs/armeabi-v7a/$(SNOWBOYDETECTSWIGLIBFILE)
  SNOWBOYDETECTSWIGLIBNAME := $(shell basename $(SNOWBOYDETECTSWIGLIBFILE))
endif

all: $(SNOWBOYSWIGLIBFILE) $(SNOWBOYDETECTSWIGLIBFILE)

%.a:
	$(MAKE) -C ${@D} ${@F}

$(SNOWBOYDETECTSWIGCC): $(SNOWBOYDETECTSWIGITF)
	@-mkdir -p $(SNOWBOYDETECTJAVAPKGDIR)
	$(SWIG) -c++ -java -package $(SNOWBOYDETECTJAVAPKG) -outdir \
  $(SNOWBOYDETECTJAVAPKGDIR) -o $(SNOWBOYDETECTSWIGCC) $(SNOWBOYDETECTSWIGITF)

$(SNOWBOYDETECTSWIGOBJ): $(SNOWBOYDETECTSWIGCC)
	$(CXX) $(CXXFLAGS) -c $(SNOWBOYDETECTSWIGCC) -o $(SNOWBOYDETECTSWIGOBJ)

$(SNOWBOYDETECTSWIGLIBFILE): $(OPENBLASLIBFILE) $(SNOWBOYDETECTSWIGOBJ) $(SNOWBOYDETECTLIBFILE)
	@-mkdir -p `dirname $(SNOWBOYDETECTSWIGLIBFILE)`
	$(CXX) -Wl,-soname,$(SNOWBOYDETECTSWIGLIBNAME) $(CXXFLAGS) $(LDFLAGS) \
  $(SNOWBOYDETECTSWIGOBJ) $(SNOWBOYDETECTLIBFILE) $(OPENBLASLIBFILE) \
  $(LDLIBS) -o $(SNOWBOYDETECTSWIGLIBFILE)
	$(STRIP) --strip-unneeded $(SNOWBOYDETECTSWIGLIBFILE)

clean:
	-rm -rf *.o *.a *.so java jniLibs $(SNOWBOYDETECTSWIGCC)
