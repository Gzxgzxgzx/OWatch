CC = arm-none-eabi-gcc
CP = arm-none-eabi-objcopy

CFLAGS  = -g -O2 -Wall -Tstm32_flash.ld
CFLAGS += -mlittle-endian -mthumb -mcpu=cortex-m4 -mthumb-interwork
CFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16

CFLAGS += -Isrc -Isrc/firmware -Ilib/inc -Ilib/inc/core -Ilib/inc/peripherals

vpath %.c src
vpath %.o obj
vpath %.a lib
vpath %.s lib

SRC  = main.c
SRC += firmware/stm32f4xx_it.c firmware/system_stm32f4xx.c

ASM = lib/startup_stm32f4xx.s

OBJ = $(SRC:.c=.o)
OBJDIR = obj
OBJPTH = $(addprefix $(OBJDIR)/, $(OBJ))

NAME = OWatch

DIR = bin
ELF = $(DIR)/$(NAME).elf
HEX = $(DIR)/$(NAME).hex
BIN = $(DIR)/$(NAME).bin

.PHONY: lib

build: lib $(ELF) $(HEX) $(BIN)

lib:
	$(MAKE) -C lib

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c -L ./lib -lstm32f4 -o $@ $^

$(ELF): $(OBJPTH)
	$(CC) $(CFLAGS) $(ASM) $^ -o $@ -L ./lib -lstm32f4

$(HEX): $(ELF)
	$(CP) -O ihex $^ $@

$(BIN): $(ELF)
	$(CP) -O binary $^ $@

flash: $(BUILD)
	st-flash write $(BIN) 0x8000000
