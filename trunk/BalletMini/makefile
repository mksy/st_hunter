#------------------------------------------------------------------------------#
# This makefile was generated by 'cbp2make' tool rev.127                       #
#------------------------------------------------------------------------------#


WORKDIR = `pwd`

CC = arm-eabi-gcc
CXX = arm-eabi-g++
AR = arm-eabi-ar
LD = arm-eabi-ld
WINDRES = arm-eabi-windres

INC =  -I/home/vova7890/compilers/include -Iinclude
CFLAGS =  -mlittle-endian -msoft-float -mcpu=arm926ej-s -nostdlib -fshort-wchar -fdata-sections -ffunction-sections -fno-exceptions  -marm -O2 -Wextra -std=gnu99 -D__NO_LIBC
RESINC = 
LIBDIR =  -L/home/vova7890/compilers/libs
LIB =  -lcrt_helper -lcrt -lc -lgcc -ljpeg -lpng -lz -lm
LDFLAGS =  -marmelf -z max-page-size=1 -nostdlib  -s --defsym __ex=0 --gc-section

INC_NSG =  $(INC)
CFLAGS_NSG =  $(CFLAGS) -DNEWSGOLD
RESINC_NSG =  $(RESINC)
RCFLAGS_NSG =  $(RCFLAGS)
LIBDIR_NSG =  $(LIBDIR)
LIB_NSG = $(LIB)
LDFLAGS_NSG =  $(LDFLAGS)
OBJDIR_NSG = objects/nsg
DEP_NSG = 
OUT_NSG = exe/BalletMini_NSG.elf

INC_SG =  $(INC)
CFLAGS_SG =  $(CFLAGS) -DSGOLD
RESINC_SG =  $(RESINC)
RCFLAGS_SG =  $(RCFLAGS)
LIBDIR_SG =  $(LIBDIR)
LIB_SG = $(LIB)
LDFLAGS_SG =  $(LDFLAGS)
OBJDIR_SG = objects/sg
DEP_SG = 
OUT_SG = exe/BalletMini_sg.elf

INC_ELKA =  $(INC)
CFLAGS_ELKA =  $(CFLAGS) -DNEWSGOLD -DELKA
RESINC_ELKA =  $(RESINC)
RCFLAGS_ELKA =  $(RCFLAGS)
LIBDIR_ELKA =  $(LIBDIR)
LIB_ELKA = $(LIB)
LDFLAGS_ELKA =  $(LDFLAGS)
OBJDIR_ELKA = objects/elka
DEP_ELKA = 
OUT_ELKA = exe/BalletMini_el.elf

OBJ_NSG = $(OBJDIR_NSG)/main.o $(OBJDIR_NSG)/mainmenu.o $(OBJDIR_NSG)/parse_oms.o $(OBJDIR_NSG)/readimg.o $(OBJDIR_NSG)/string_works.o $(OBJDIR_NSG)/upload.o $(OBJDIR_NSG)/url_utils.o $(OBJDIR_NSG)/urlstack.o $(OBJDIR_NSG)/file_works.o $(OBJDIR_NSG)/conf_loader.o $(OBJDIR_NSG)/config_data.o $(OBJDIR_NSG)/debug.o $(OBJDIR_NSG)/destructors.o $(OBJDIR_NSG)/display_utils.o $(OBJDIR_NSG)/additems.o $(OBJDIR_NSG)/fileman.o $(OBJDIR_NSG)/history.o $(OBJDIR_NSG)/inet.o $(OBJDIR_NSG)/lang.o

OBJ_SG = $(OBJDIR_SG)/main.o $(OBJDIR_SG)/mainmenu.o $(OBJDIR_SG)/parse_oms.o $(OBJDIR_SG)/readimg.o $(OBJDIR_SG)/string_works.o $(OBJDIR_SG)/upload.o $(OBJDIR_SG)/url_utils.o $(OBJDIR_SG)/urlstack.o $(OBJDIR_SG)/file_works.o $(OBJDIR_SG)/conf_loader.o $(OBJDIR_SG)/config_data.o $(OBJDIR_SG)/debug.o $(OBJDIR_SG)/destructors.o $(OBJDIR_SG)/display_utils.o $(OBJDIR_SG)/additems.o $(OBJDIR_SG)/fileman.o $(OBJDIR_SG)/history.o $(OBJDIR_SG)/inet.o $(OBJDIR_SG)/lang.o

OBJ_ELKA = $(OBJDIR_ELKA)/main.o $(OBJDIR_ELKA)/mainmenu.o $(OBJDIR_ELKA)/parse_oms.o $(OBJDIR_ELKA)/readimg.o $(OBJDIR_ELKA)/string_works.o $(OBJDIR_ELKA)/upload.o $(OBJDIR_ELKA)/url_utils.o $(OBJDIR_ELKA)/urlstack.o $(OBJDIR_ELKA)/file_works.o $(OBJDIR_ELKA)/conf_loader.o $(OBJDIR_ELKA)/config_data.o $(OBJDIR_ELKA)/debug.o $(OBJDIR_ELKA)/destructors.o $(OBJDIR_ELKA)/display_utils.o $(OBJDIR_ELKA)/additems.o $(OBJDIR_ELKA)/fileman.o $(OBJDIR_ELKA)/history.o $(OBJDIR_ELKA)/inet.o $(OBJDIR_ELKA)/lang.o

all: nsg sg elka

clean: clean_nsg clean_sg clean_elka

before_nsg: 
	test -d exe || mkdir -p exe
	test -d $(OBJDIR_NSG) || mkdir -p $(OBJDIR_NSG)

after_nsg: 

nsg: before_nsg out_nsg after_nsg

out_nsg: $(OBJ_NSG) $(DEP_NSG)
	$(LD) -pie $(LIBDIR_NSG) -o $(OUT_NSG) $(OBJ_NSG)  $(LDFLAGS_NSG) $(LIB_NSG)

$(OBJDIR_NSG)/main.o: main.c
	$(CC) $(CFLAGS_NSG) $(INC_NSG) -c main.c -o $(OBJDIR_NSG)/main.o

$(OBJDIR_NSG)/mainmenu.o: mainmenu.c
	$(CC) $(CFLAGS_NSG) $(INC_NSG) -c mainmenu.c -o $(OBJDIR_NSG)/mainmenu.o

$(OBJDIR_NSG)/parse_oms.o: parse_oms.c
	$(CC) $(CFLAGS_NSG) $(INC_NSG) -c parse_oms.c -o $(OBJDIR_NSG)/parse_oms.o

$(OBJDIR_NSG)/readimg.o: readimg.c
	$(CC) $(CFLAGS_NSG) $(INC_NSG) -c readimg.c -o $(OBJDIR_NSG)/readimg.o

$(OBJDIR_NSG)/string_works.o: string_works.c
	$(CC) $(CFLAGS_NSG) $(INC_NSG) -c string_works.c -o $(OBJDIR_NSG)/string_works.o

$(OBJDIR_NSG)/upload.o: upload.c
	$(CC) $(CFLAGS_NSG) $(INC_NSG) -c upload.c -o $(OBJDIR_NSG)/upload.o

$(OBJDIR_NSG)/url_utils.o: url_utils.c
	$(CC) $(CFLAGS_NSG) $(INC_NSG) -c url_utils.c -o $(OBJDIR_NSG)/url_utils.o

$(OBJDIR_NSG)/urlstack.o: urlstack.c
	$(CC) $(CFLAGS_NSG) $(INC_NSG) -c urlstack.c -o $(OBJDIR_NSG)/urlstack.o

$(OBJDIR_NSG)/file_works.o: file_works.c
	$(CC) $(CFLAGS_NSG) $(INC_NSG) -c file_works.c -o $(OBJDIR_NSG)/file_works.o

$(OBJDIR_NSG)/conf_loader.o: conf_loader.c
	$(CC) $(CFLAGS_NSG) $(INC_NSG) -c conf_loader.c -o $(OBJDIR_NSG)/conf_loader.o

$(OBJDIR_NSG)/config_data.o: config_data.c
	$(CC) $(CFLAGS_NSG) $(INC_NSG) -c config_data.c -o $(OBJDIR_NSG)/config_data.o

$(OBJDIR_NSG)/debug.o: debug.c
	$(CC) $(CFLAGS_NSG) $(INC_NSG) -c debug.c -o $(OBJDIR_NSG)/debug.o

$(OBJDIR_NSG)/destructors.o: destructors.c
	$(CC) $(CFLAGS_NSG) $(INC_NSG) -c destructors.c -o $(OBJDIR_NSG)/destructors.o

$(OBJDIR_NSG)/display_utils.o: display_utils.c
	$(CC) $(CFLAGS_NSG) $(INC_NSG) -c display_utils.c -o $(OBJDIR_NSG)/display_utils.o

$(OBJDIR_NSG)/additems.o: additems.c
	$(CC) $(CFLAGS_NSG) $(INC_NSG) -c additems.c -o $(OBJDIR_NSG)/additems.o

$(OBJDIR_NSG)/fileman.o: fileman.c
	$(CC) $(CFLAGS_NSG) $(INC_NSG) -c fileman.c -o $(OBJDIR_NSG)/fileman.o

$(OBJDIR_NSG)/history.o: history.c
	$(CC) $(CFLAGS_NSG) $(INC_NSG) -c history.c -o $(OBJDIR_NSG)/history.o

$(OBJDIR_NSG)/inet.o: inet.c
	$(CC) $(CFLAGS_NSG) $(INC_NSG) -c inet.c -o $(OBJDIR_NSG)/inet.o

$(OBJDIR_NSG)/lang.o: lang.c
	$(CC) $(CFLAGS_NSG) $(INC_NSG) -c lang.c -o $(OBJDIR_NSG)/lang.o

clean_nsg: 
	rm -f $(OBJ_NSG) $(OUT_NSG)
	rm -rf exe
	rm -rf $(OBJDIR_NSG)

before_sg: 
	test -d exe || mkdir -p exe
	test -d $(OBJDIR_SG) || mkdir -p $(OBJDIR_SG)

after_sg: 

sg: before_sg out_sg after_sg

out_sg: $(OBJ_SG) $(DEP_SG)
	$(LD) -pie $(LIBDIR_SG) -o $(OUT_SG) $(OBJ_SG)  $(LDFLAGS_SG) $(LIB_SG)

$(OBJDIR_SG)/main.o: main.c
	$(CC) $(CFLAGS_SG) $(INC_SG) -c main.c -o $(OBJDIR_SG)/main.o

$(OBJDIR_SG)/mainmenu.o: mainmenu.c
	$(CC) $(CFLAGS_SG) $(INC_SG) -c mainmenu.c -o $(OBJDIR_SG)/mainmenu.o

$(OBJDIR_SG)/parse_oms.o: parse_oms.c
	$(CC) $(CFLAGS_SG) $(INC_SG) -c parse_oms.c -o $(OBJDIR_SG)/parse_oms.o

$(OBJDIR_SG)/readimg.o: readimg.c
	$(CC) $(CFLAGS_SG) $(INC_SG) -c readimg.c -o $(OBJDIR_SG)/readimg.o

$(OBJDIR_SG)/string_works.o: string_works.c
	$(CC) $(CFLAGS_SG) $(INC_SG) -c string_works.c -o $(OBJDIR_SG)/string_works.o

$(OBJDIR_SG)/upload.o: upload.c
	$(CC) $(CFLAGS_SG) $(INC_SG) -c upload.c -o $(OBJDIR_SG)/upload.o

$(OBJDIR_SG)/url_utils.o: url_utils.c
	$(CC) $(CFLAGS_SG) $(INC_SG) -c url_utils.c -o $(OBJDIR_SG)/url_utils.o

$(OBJDIR_SG)/urlstack.o: urlstack.c
	$(CC) $(CFLAGS_SG) $(INC_SG) -c urlstack.c -o $(OBJDIR_SG)/urlstack.o

$(OBJDIR_SG)/file_works.o: file_works.c
	$(CC) $(CFLAGS_SG) $(INC_SG) -c file_works.c -o $(OBJDIR_SG)/file_works.o

$(OBJDIR_SG)/conf_loader.o: conf_loader.c
	$(CC) $(CFLAGS_SG) $(INC_SG) -c conf_loader.c -o $(OBJDIR_SG)/conf_loader.o

$(OBJDIR_SG)/config_data.o: config_data.c
	$(CC) $(CFLAGS_SG) $(INC_SG) -c config_data.c -o $(OBJDIR_SG)/config_data.o

$(OBJDIR_SG)/debug.o: debug.c
	$(CC) $(CFLAGS_SG) $(INC_SG) -c debug.c -o $(OBJDIR_SG)/debug.o

$(OBJDIR_SG)/destructors.o: destructors.c
	$(CC) $(CFLAGS_SG) $(INC_SG) -c destructors.c -o $(OBJDIR_SG)/destructors.o

$(OBJDIR_SG)/display_utils.o: display_utils.c
	$(CC) $(CFLAGS_SG) $(INC_SG) -c display_utils.c -o $(OBJDIR_SG)/display_utils.o

$(OBJDIR_SG)/additems.o: additems.c
	$(CC) $(CFLAGS_SG) $(INC_SG) -c additems.c -o $(OBJDIR_SG)/additems.o

$(OBJDIR_SG)/fileman.o: fileman.c
	$(CC) $(CFLAGS_SG) $(INC_SG) -c fileman.c -o $(OBJDIR_SG)/fileman.o

$(OBJDIR_SG)/history.o: history.c
	$(CC) $(CFLAGS_SG) $(INC_SG) -c history.c -o $(OBJDIR_SG)/history.o

$(OBJDIR_SG)/inet.o: inet.c
	$(CC) $(CFLAGS_SG) $(INC_SG) -c inet.c -o $(OBJDIR_SG)/inet.o

$(OBJDIR_SG)/lang.o: lang.c
	$(CC) $(CFLAGS_SG) $(INC_SG) -c lang.c -o $(OBJDIR_SG)/lang.o

clean_sg: 
	rm -f $(OBJ_SG) $(OUT_SG)
	rm -rf exe
	rm -rf $(OBJDIR_SG)

before_elka: 
	test -d exe || mkdir -p exe
	test -d $(OBJDIR_ELKA) || mkdir -p $(OBJDIR_ELKA)

after_elka: 

elka: before_elka out_elka after_elka

out_elka: $(OBJ_ELKA) $(DEP_ELKA)
	$(LD) -pie $(LIBDIR_ELKA) -o $(OUT_ELKA) $(OBJ_ELKA)  $(LDFLAGS_ELKA) $(LIB_ELKA)

$(OBJDIR_ELKA)/main.o: main.c
	$(CC) $(CFLAGS_ELKA) $(INC_ELKA) -c main.c -o $(OBJDIR_ELKA)/main.o

$(OBJDIR_ELKA)/mainmenu.o: mainmenu.c
	$(CC) $(CFLAGS_ELKA) $(INC_ELKA) -c mainmenu.c -o $(OBJDIR_ELKA)/mainmenu.o

$(OBJDIR_ELKA)/parse_oms.o: parse_oms.c
	$(CC) $(CFLAGS_ELKA) $(INC_ELKA) -c parse_oms.c -o $(OBJDIR_ELKA)/parse_oms.o

$(OBJDIR_ELKA)/readimg.o: readimg.c
	$(CC) $(CFLAGS_ELKA) $(INC_ELKA) -c readimg.c -o $(OBJDIR_ELKA)/readimg.o

$(OBJDIR_ELKA)/string_works.o: string_works.c
	$(CC) $(CFLAGS_ELKA) $(INC_ELKA) -c string_works.c -o $(OBJDIR_ELKA)/string_works.o

$(OBJDIR_ELKA)/upload.o: upload.c
	$(CC) $(CFLAGS_ELKA) $(INC_ELKA) -c upload.c -o $(OBJDIR_ELKA)/upload.o

$(OBJDIR_ELKA)/url_utils.o: url_utils.c
	$(CC) $(CFLAGS_ELKA) $(INC_ELKA) -c url_utils.c -o $(OBJDIR_ELKA)/url_utils.o

$(OBJDIR_ELKA)/urlstack.o: urlstack.c
	$(CC) $(CFLAGS_ELKA) $(INC_ELKA) -c urlstack.c -o $(OBJDIR_ELKA)/urlstack.o

$(OBJDIR_ELKA)/file_works.o: file_works.c
	$(CC) $(CFLAGS_ELKA) $(INC_ELKA) -c file_works.c -o $(OBJDIR_ELKA)/file_works.o

$(OBJDIR_ELKA)/conf_loader.o: conf_loader.c
	$(CC) $(CFLAGS_ELKA) $(INC_ELKA) -c conf_loader.c -o $(OBJDIR_ELKA)/conf_loader.o

$(OBJDIR_ELKA)/config_data.o: config_data.c
	$(CC) $(CFLAGS_ELKA) $(INC_ELKA) -c config_data.c -o $(OBJDIR_ELKA)/config_data.o

$(OBJDIR_ELKA)/debug.o: debug.c
	$(CC) $(CFLAGS_ELKA) $(INC_ELKA) -c debug.c -o $(OBJDIR_ELKA)/debug.o

$(OBJDIR_ELKA)/destructors.o: destructors.c
	$(CC) $(CFLAGS_ELKA) $(INC_ELKA) -c destructors.c -o $(OBJDIR_ELKA)/destructors.o

$(OBJDIR_ELKA)/display_utils.o: display_utils.c
	$(CC) $(CFLAGS_ELKA) $(INC_ELKA) -c display_utils.c -o $(OBJDIR_ELKA)/display_utils.o

$(OBJDIR_ELKA)/additems.o: additems.c
	$(CC) $(CFLAGS_ELKA) $(INC_ELKA) -c additems.c -o $(OBJDIR_ELKA)/additems.o

$(OBJDIR_ELKA)/fileman.o: fileman.c
	$(CC) $(CFLAGS_ELKA) $(INC_ELKA) -c fileman.c -o $(OBJDIR_ELKA)/fileman.o

$(OBJDIR_ELKA)/history.o: history.c
	$(CC) $(CFLAGS_ELKA) $(INC_ELKA) -c history.c -o $(OBJDIR_ELKA)/history.o

$(OBJDIR_ELKA)/inet.o: inet.c
	$(CC) $(CFLAGS_ELKA) $(INC_ELKA) -c inet.c -o $(OBJDIR_ELKA)/inet.o

$(OBJDIR_ELKA)/lang.o: lang.c
	$(CC) $(CFLAGS_ELKA) $(INC_ELKA) -c lang.c -o $(OBJDIR_ELKA)/lang.o

clean_elka: 
	rm -f $(OBJ_ELKA) $(OUT_ELKA)
	rm -rf exe
	rm -rf $(OBJDIR_ELKA)

.PHONY: before_nsg after_nsg clean_nsg before_sg after_sg clean_sg before_elka after_elka clean_elka

