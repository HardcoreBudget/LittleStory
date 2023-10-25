################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/GIE/Source/subdir.mk
-include MCAL/EXTI/Source/subdir.mk
-include MCAL/DIO/Source/subdir.mk
-include MCAL/ADC/Source/subdir.mk
-include HAL/SevSeg/Source/subdir.mk
-include HAL/LCD/Source/subdir.mk
-include HAL/Keypad/Source/subdir.mk
-include App/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
LittleStory.lss \

FLASH_IMAGE += \
LittleStory.hex \

EEPROM_IMAGE += \
LittleStory.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: LittleStory.elf secondary-outputs

# Tool invocations
LittleStory.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,LittleStory.map -mmcu=atmega32 -o "LittleStory.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

LittleStory.lss: LittleStory.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S LittleStory.elf  >"LittleStory.lss"
	@echo 'Finished building: $@'
	@echo ' '

LittleStory.hex: LittleStory.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex LittleStory.elf  "LittleStory.hex"
	@echo 'Finished building: $@'
	@echo ' '

LittleStory.eep: LittleStory.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex LittleStory.elf  "LittleStory.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: LittleStory.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 LittleStory.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) LittleStory.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
