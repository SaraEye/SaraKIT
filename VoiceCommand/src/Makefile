SHELL = /bin/sh


OBJDIR := .obj
DEPDIR := .dep
SRCDIR := 

CPP_SOURCES = voiceCommand.cpp \
	Audio.cpp \
	GoogleSpeech.cpp \
	CJSONPost.cpp \
	base64.cpp \
	KeywordActionManager.cpp \
	
C_SOURCES =	


#CFLAGS = -Wl,--no-as-needed -fexceptions -fopenmp -pthread -O3 -Wno-psabi -DQPU_MODE -mfpu=neon-fp-armv8 google_cloud_cpp_cloud_speech_protos
CFLAGS = -Wl,--no-as-needed -fexceptions -fpermissive -fopenmp -pthread -O3 -mcpu=cortex-a72 -mtune=cortex-a72 -Wno-psabi `pkg-config --cflags opencv4` `pkg-config --cflags google_cloud_cpp_cloud_speech_protos` 
# -march=native -mtune=cortex-a72 -DNDEBUG -s
# -march=armv7 -mtune=cortex-a72 -mfpu=neon -mfloat-abi=hard -mfpu=vfp
CC = g++
INCLUDES =
LIBS =-lpthread \
	-lrt \
	-latomic \
	-lm \
	-lcurl \
	-lpulse \
	-lpulse-simple \
	-lcrypt 

SLIBS= `pkg-config --libs google_cloud_cpp_cloud_speech_protos` `pkg-config --libs google_cloud_cpp_type_latlng_protos`

DEPFLAGS = -MT $@ -MMD -MP -MF  $(DEPDIR)/$*.d 

SOURCES=$(CPP_SOURCES) $(C_SOURCES)
OBJECTS=$(CPP_SOURCES:.cpp=.o) $(C_SOURCES:.c=.o)

mkdirs = $(shell mkdir -p   $(DEPDIR)/$(dir $(path)) $(OBJDIR)/$(dir $(path)))
$(foreach path,$(SOURCES),$(mkdirs))

POBJECTS= $(addprefix $(OBJDIR)/, $(OBJECTS))

PRG=voiceCommand

all: $(PRG)
$(PRG):$(POBJECTS)
	$(CC)  -Wl,--no-as-needed -o $@ $(POBJECTS) $(LIBS)  $(SLIBS)  /home/pi/vcpkg_libs/lib/libgrpc_upbdefs.a /home/pi/vcpkg_libs/lib/libprotobuf.a
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