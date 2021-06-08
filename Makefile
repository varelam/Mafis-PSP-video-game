TARGET = PRENDAAA

SRC_DIR := src
SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRC:.cpp=.o)

CFLAGS   =              
CXXFLAGS = $(CFLAGS) -std=c++14 -fno-rtti 
ASFLAGS =  $(CFLAGS) 

# PSP Stuff
BUILD_PRX = 1
PSP_FW_VERSION = 500
PSP_LARGE_MEMORY = 1

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = PRENDAAA

PSP_EBOOT_ICON= "media/icon0.png" # 144x80 image!
PSP_EBOOT_PIC1= "media/background0.png" # 480 x 270
# PSP_EBOOT_SND0= "media/intro.at3"

PSPSDK=$(shell psp-config --pspsdk-path)

include $(PSPSDK)/lib/build.mak