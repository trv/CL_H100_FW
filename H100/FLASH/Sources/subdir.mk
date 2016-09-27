################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/main.c" \

ASM_SRCS += \
../Sources/asm_main.asm \

C_SRCS += \
../Sources/main.c \

ASM_SRCS_QUOTED += \
"../Sources/asm_main.asm" \

OBJS += \
./Sources/asm_main_asm.obj \
./Sources/main_c.obj \

ASM_DEPS += \
./Sources/asm_main_asm.d \

OBJS_QUOTED += \
"./Sources/asm_main_asm.obj" \
"./Sources/main_c.obj" \

C_DEPS += \
./Sources/main_c.d \

ASM_DEPS_QUOTED += \
"./Sources/asm_main_asm.d" \

C_DEPS_QUOTED += \
"./Sources/main_c.d" \

OBJS_OS_FORMAT += \
./Sources/asm_main_asm.obj \
./Sources/main_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/asm_main_asm.obj: ../Sources/asm_main.asm
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: HCS08 Assembler'
	"$(HC08ToolsEnv)/ahc08" -ArgFile"Sources/asm_main.args" -Objn"Sources/asm_main_asm.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.asm
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/main_c.obj: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/main.args" -ObjN="Sources/main_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '


