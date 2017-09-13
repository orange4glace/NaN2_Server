OUTPUT = nan2_server

PROJECT_ROOT = ..
MODE = debug
CC = g++

TARGETS = $(shell find src -name '*.cpp')
MAIN = main.cpp

AdditionalIncludePath = include src ../MathLib/include ${PROUDNET_HOME}/include
AdditionalLibraryPath = ../MathLib lib/sslv2-enabled ${PROUDNET_HOME}/lib/x86_x64-linux/Debug
AdditionalLibrary = NaN2Math ProudNet pthread boost_system boost_thread boost_log ssl crypto odbc
CC_FLAGS = -std=c++14 -DDEBUG -D_DEBUG -DBOOST_LOG_DYN_LINK
OBJS_DIR =
BUILD_PATH = build/$(MODE)

INCLUDE_PATH_ARGS = $(addprefix -I, $(AdditionalIncludePath))
LIBRARY_PATH_ARGS = $(addprefix -L, $(AdditionalLibraryPath))
LIBRARY_ARGS = $(addprefix -l, $(AdditionalLibrary))

SEPARATER = "========================================="

DEPEND_FILE = $(BUILD_PATH)/depend
DEPEND_SHELL_SCRIPT = $(PROJECT_ROOT)/scripts/make_depend.sh

OBJS = $(TARGETS:%.cpp=$(BUILD_PATH)/%.o)

all: $(OUTPUT)

$(OUTPUT): $(OBJS) $(MAIN)
	@echo $(SEPARATER)
	@echo " Linking files to main.. "
	$(CC) $(CC_FLAGS) \
	-c $(MAIN) \
	$(INCLUDE_PATH_ARGS) $(LIBRARY_PATH_ARGS) $(LIBRARY_ARGS)
	$(CC) $(CC_FLAGS) \
	-o $@ $(MAIN:%.cpp=%.o) $(OBJS) \
	$(INCLUDE_PATH_ARGS) $(LIBRARY_PATH_ARGS) $(LIBRARY_ARGS)

$(BUILD_PATH)/%.o: %.cpp
	@echo $(SEPARATER)
	@echo " Compile $@ "
	@`[ -d $(@D) ] || mkdir -p $(@D)`
	$(CC) $(CC_FLAGS) -c $< -o $@ \
	$(INCLUDE_PATH_ARGS) $(LIBRARY_PATH_ARGS) $(LIBRARY_ARGS)
	

depend:
	@`[ -d $(BUILD_PATH) ] || mkdir -p $(BUILD_PATH)`
	@echo $(SEPARATER)
	@echo "= Depend $@ "
	rm -f $(DEPEND_FILE)
	$(DEPEND_SHELL_SCRIPT) \
		"$(TARGETS:%.cpp=%)" \
		"$(CC)" "$(BUILD_PATH)" \
		"$(CC_FLAGS) $(INCLUDE_PATH_ARGS)" "$(DEPEND_FILE)"

clean:
	rm -rf $(BUILD_PATH) $(OUTPUT) $(MAIN:%.cpp=%.o)

ifneq ($(MAKECMDGOALS), clean)
ifneq ($(MAKECMDGOALS), cleanall)
ifneq ($(MAKECMDGOALS), depend)
ifneq ($(MAKECMDGOALS), dependall)
-include $(DEPEND_FILE)
endif
endif
endif
endif