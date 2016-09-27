################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
ASM_SRCS += \
../Sources/fw.asm \

ASM_SRCS_QUOTED += \
"../Sources/fw.asm" \

OBJS += \
./Sources/fw_asm.obj \

ASM_DEPS += \
./Sources/fw_asm.d \

OBJS_QUOTED += \
"./Sources/fw_asm.obj" \

ASM_DEPS_QUOTED += \
"./Sources/fw_asm.d" \

OBJS_OS_FORMAT += \
./Sources/fw_asm.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/fw_asm.obj: ../Sources/fw.asm
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: HCS08 Assembler'
	"$(HC08ToolsEnv)/ahc08" -ArgFile"Sources/fw.args" -Objn"Sources/fw_asm.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.asm
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '


