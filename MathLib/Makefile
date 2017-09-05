LIB_NAME = libNaN2Math

PROJECT_ROOT = ..
MODE = debug
CC = g++

TARGETS = $(wildcard src/*.cpp)

AdditionalIncludePath = include/nan2/math
AdditionalLibraryPath =
AdditionalLibrary =
CC_FLAGS = -std=c++14
OBJS_DIR =
BUILD_PATH = build/$(MODE)

SEPARATER = "========================================="

DEPEND_FILE = $(BUILD_PATH)/depend
DEPEND_SHELL_SCRIPT = $(PROJECT_ROOT)/scripts/make_depend.sh

OBJS = $(TARGETS:%.cpp=$(BUILD_PATH)/%.o)

all: $(LIB_NAME)

$(LIB_NAME): $(OBJS)
	@echo $(SEPARATER)
	@echo "= Packaging library $@ "
	ar rcv $@ $(OBJS)
	ranlib $@

$(BUILD_PATH)/%.o: %.cpp
	@echo $(SEPARATER)
	@echo " Compile $@ "
	@`[ -d $(@D) ] || mkdir -p $(@D)`
	$(CC) $(CC_FLAGS) -I $(AdditionalIncludePath) -c $< -o $@

depend:
	@`[ -d $(BUILD_PATH) ] || mkdir -p $(BUILD_PATH)`
	@echo $(SEPARATER)
	@echo "= Depend $@ "
	rm -f $(DEPEND_FILE)
	$(DEPEND_SHELL_SCRIPT) \
		"$(TARGETS:%.cpp=%)" \
		"$(CC)" "$(BUILD_PATH)" \
		"$(CC_FLAGS) -I $(AdditionalIncludePath)" "$(DEPEND_FILE)"

clean:
	rm -rf $(BUILD_PATH)

ifneq ($(MAKECMDGOALS), clean)
ifneq ($(MAKECMDGOALS), cleanall)
ifneq ($(MAKECMDGOALS), depend)
ifneq ($(MAKECMDGOALS), dependall)
-include $(DEPEND_FILE)
endif
endif
endif
endif