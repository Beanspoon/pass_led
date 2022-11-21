PROJECT = pass_led

SRCS += \
	$(wildcard src/*.c) \
	$(wildcard common/src/*.c) \
	$(wildcard chipsets/$(CHIPSET)/src/*.c)

INCLUDES += \
	include \
	common/include \
	chipsets/$(CHIPSET)/include \
	boards/$(BOARD)

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
	-Wl,-T link.ld

OBJ_DIR := .objects

OBJS := $(SRCS:%.c=$(OBJ_DIR)/%.o)
DEPS := $(OBJS:%.o=%.d)

CC := arm-none-eabi-gcc

BUILD_DIR := build

$(BUILD_DIR)/$(PROJECT).bin: $(BUILD_DIR)/$(PROJECT).elf $(BUILD_DIR)/$(PROJECT).lst | $(BUILD_DIR)
	@arm-none-eabi-objcopy $< $@ -O binary
	@arm-none-eabi-size $<

$(BUILD_DIR)/$(PROJECT).lst: $(BUILD_DIR)/$(PROJECT).elf | $(BUILD_DIR)
	@arm-none-eabi-objdump -D $< > $@

$(BUILD_DIR)/$(PROJECT).elf: $(OBJS) | $(BUILD_DIR)
	@echo "Linking $@"
	@$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
	@echo

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD_DIR): ; @mkdir -p $@

$(OBJ_DIR): ; @mkdir -p $@

clean: ; $(RM) -r $(OBJ_DIR) $(BUILD_DIR)

-include $(DEPS)