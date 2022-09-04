BUILD_DIR := rohit
OPENOCD_HOME := /usr/local/bin/openocd
CPU_CORES :=1
CFG_FILE :=stm32f1x.cfg


all: source
	${MAKE} -C $(BUILD_DIR) -j$(CPU_CORES)

source:
	cmake -B$(BUILD_DIR)

build:
	${MAKE} -C $(BUILD_DIR) -j$(CPU_CORES)

flash:
	openocd -d2 -s $(OPENOCD_HOME)/scripts -f interface/stlink.cfg -c "transport select hla_swd" -f target/$(CFG_FILE) -c "program {./$(BUILD_DIR)/zephyr/zephyr.elf}  verify reset; shutdown;"

clean:
	rm -rf $(BUILD_DIR)

.phony: flash clean