SHELL = /bin/sh


OBJDIR := .obj
DEPDIR := .dep
SRCDIR := 

CPP_SOURCES = facedetector.cpp  \
	MNN_UltraFace.cpp
	

	
C_SOURCES =	


#CFLAGS = -Wl,--no-as-needed -fexceptions -fopenmp -pthread -O3 -Wno-psabi -DQPU_MODE -mfpu=neon-fp-armv8 google_cloud_cpp_cloud_speech_protos
CFLAGS = -Wl,--no-as-needed -fexceptions -fpermissive -fopenmp -pthread -O3 -mcpu=cortex-a72 -mtune=cortex-a72 -Wno-psabi `pkg-config --cflags opencv4` 
# -march=native -mtune=cortex-a72 -DNDEBUG -s
# -march=armv7 -mtune=cortex-a72 -mfpu=neon -mfloat-abi=hard -mfpu=vfp
CC = g++
INCLUDES = -I/usr/local/include/MNN 

LIBS =-lpthread \
	-lrt \
	-latomic \
	-lm \
	-lMNN \
	`pkg-config --libs opencv4` 

SLIBS= 

DEPFLAGS = -MT $@ -MMD -MP -MF  $(DEPDIR)/$*.d 

SOURCES=$(CPP_SOURCES) $(C_SOURCES)
OBJECTS=$(CPP_SOURCES:.cpp=.o) $(C_SOURCES:.c=.o)

mkdirs = $(shell mkdir -p   $(DEPDIR)/$(dir $(path)) $(OBJDIR)/$(dir $(path)))
$(foreach path,$(SOURCES),$(mkdirs))

POBJECTS= $(addprefix $(OBJDIR)/, $(OBJECTS))

PRG=facedetector

all: $(PRG)
$(PRG):$(POBJECTS)
	$(CC)  -Wl,--no-as-needed -o $@ $(POBJECTS) $(LIBS)  $(SLIBS)
$(OBJDIR)/%.o: %.c $(DEPDIR)/%.d
	$(CC)  $(DEPFLAGS) $(CFLAGS) $(INCLUDES) -c -o $@ $< 
$(OBJDIR)/%.o: %.cpp $(DEPDIR)/%.d 
	$(CC)  $(DEPFLAGS) $(CFLAGS) $(INCLUDES) -c -o $@ $< 

DEPFILES =  $(C_SOURCES:%.c=%.d)
DEPFILES +=  $(CPP_SOURCES:%.cpp=%.d)
PDEPFILES= $(addprefix $(DEPDIR)/, $(DEPFILES))
$(PDEPFILES):
include $(wildcard $(PDEPFILES))

clean:
	-rm -f $(POBJECTS) $(PDEPFILES) $(PRG) $(OBJDIR)/*.o $(DEPDIR)/*.d