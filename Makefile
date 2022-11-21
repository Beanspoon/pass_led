PROJECT = pass_led

SRCS += \
	$(wildcard src/*.c) \
	$(wildcard common/src/*.c) \
	$(wildcard chipsets/$(CHIPSET)/src/*.c)

INCLUDES = \
	include \
	common/include \
	chipsets/$(CHIPSET)/include \
	boards/$(BOARD)

SRCS_MAIN = \
	chipsets/$(CHIPSET)/src/startup.c \
	src/main.c

CFLAGS += \
	-mthumb \
	-mcpu=cortex-m4 \
	-mfloat-abi=hard \
	-mfpu=fpv4-sp-d16 \
	-std=c99 \
	-Og \
	-g \
	-ffreestanding \
	-ffunction-sections \
	-fdata-sections

CFLAGS += $(foreach i,$(INCLUDES),-I $(i))

DEPFLAGS = \
	-MMD \
	-MP

CFLAGS += $(DEPFLAGS)

LDFLAGS += \
	-specs=nosys.specs \
	-Wl,--print-memory-usage \
	-Wl,-Map=flash.map \
	-Wl,--gc-sections \

OBJS := $(SRCS:.c=.o)
DEPS := $(SRCS:.c=.d)

CC := arm-none-eabi-gcc

BUILD_DIR := build

all: $(BUILD_DIR)/$(PROJECT).elf

$(BUILD_DIR)/$(PROJECT).elf: $(OBJS)

clean: ; $(RM) $(OBJS) $(DEPS)

-include $(DEPS)