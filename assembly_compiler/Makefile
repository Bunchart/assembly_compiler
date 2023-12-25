# Compiler
CC = gcc
CFLAGS = -w

# Directories
BIN_DIR = bin
LEXYACC_DIR = lexyacc-code
BUILD_ARTIFACTS_DIR = $(LEXYACC_DIR)/build-artifacts
LIB_DIR = lib
SRC_DIR = src

# Targets
A_TARGET = $(BIN_DIR)/calc3a.exe
B_TARGET = $(BIN_DIR)/calc3b.exe
G_TARGET = $(BIN_DIR)/calc3g.exe
I_TARGET = $(BIN_DIR)/calc3i.exe
GCD_TARGET = $(LIB_DIR)/gcd.so
FACT_TARGET = $(LIB_DIR)/fact.so
LNTWO_TARGET = $(LIB_DIR)/lntwo.so
BUILD_TARGET = $(LEXYACC_DIR)/y.tab.c $(LEXYACC_DIR)/lex.yy.c
COMPILE_TARGET_YACC = $(BUILD_ARTIFACTS_DIR)/y.tab.o
COMPILE_TARGET_LEX = $(BUILD_ARTIFACTS_DIR)/lex.yy.o

# Source files
A_SRC = $(wildcard $(LEXYACC_DIR)/calc3a.c)
B_SRC = $(wildcard $(LEXYACC_DIR)/calc3b.c)
G_SRC = $(wildcard $(LEXYACC_DIR)/calc3g.c)
I_SRC = $(wildcard $(LEXYACC_DIR)/calc3i.c)
GCD_SRC = $(wildcard $(SRC_DIR)/gcd.c)
FACT_SRC = $(wildcard $(SRC_DIR)/fact.c)
LNTWO_SRC = $(wildcard $(SRC_DIR)/lntwo.c)

# Default target
all: $(GCD_TARGET) $(FACT_TARGET) $(LNTWO_TARGET) $(BUILD_TARGET) $(COMPILE_TARGET_YACC) $(COMPILE_TARGET_LEX) $(A_TARGET) $(B_TARGET) $(G_TARGET) $(I_TARGET)

# Compile shared objects
$(GCD_TARGET): $(GCD_SRC)
	$(CC) -shared -o $(GCD_TARGET) -fPIC $(GCD_SRC)

$(FACT_TARGET): $(FACT_SRC)
	$(CC) -shared -o $(FACT_TARGET) -fPIC $(FACT_SRC)

$(LNTWO_TARGET): $(LNTWO_SRC)
	$(CC) -shared -o $(LNTWO_TARGET) -fPIC $(LNTWO_SRC) -lm

# Build Lex and Yacc files
$(BUILD_TARGET): $(LEXYACC_DIR)/calc3.y $(LEXYACC_DIR)/calc3.l
	bison -y -d $(LEXYACC_DIR)/calc3.y -o $(LEXYACC_DIR)/y.tab.c
	flex -o $(LEXYACC_DIR)/lex.yy.c $(LEXYACC_DIR)/calc3.l
	mv $(LEXYACC_DIR)/y.tab.* $(BUILD_ARTIFACTS_DIR)
	mv $(LEXYACC_DIR)/lex.yy.* $(BUILD_ARTIFACTS_DIR)

# Compile Lex and Yacc output
$(COMPILE_TARGET_YACC): $(LEXYACC_DIR)/y.tab.c
	$(CC) -c $(BUILD_ARTIFACTS_DIR)/y.tab.c -o $(BUILD_ARTIFACTS_DIR)/y.tab.o

$(COMPILE_TARGET_LEX): $(LEXYACC_DIR)/lex.yy.c
	$(CC) -c $(BUILD_ARTIFACTS_DIR)/lex.yy.c -o $(BUILD_ARTIFACTS_DIR)/lex.yy.o

# Compile targets
$(A_TARGET): $(A_SRC) $(BUILD_ARTIFACTS_DIR)/y.tab.o $(BUILD_ARTIFACTS_DIR)/lex.yy.o
	$(CC) $(CFLAGS) $(BUILD_ARTIFACTS_DIR)/y.tab.o $(BUILD_ARTIFACTS_DIR)/lex.yy.o $(A_SRC) -o $(A_TARGET)

$(B_TARGET): $(B_SRC) $(BUILD_ARTIFACTS_DIR)/y.tab.o $(BUILD_ARTIFACTS_DIR)/lex.yy.o
	$(CC) $(CFLAGS) $(BUILD_ARTIFACTS_DIR)/y.tab.o $(BUILD_ARTIFACTS_DIR)/lex.yy.o $(B_SRC) -o $(B_TARGET)

$(G_TARGET): $(G_SRC) $(BUILD_ARTIFACTS_DIR)/y.tab.o $(BUILD_ARTIFACTS_DIR)/lex.yy.o
	$(CC) $(CFLAGS) $(BUILD_ARTIFACTS_DIR)/y.tab.o $(BUILD_ARTIFACTS_DIR)/lex.yy.o $(G_SRC) -o $(G_TARGET)

$(I_TARGET): $(I_SRC) $(BUILD_ARTIFACTS_DIR)/y.tab.o $(BUILD_ARTIFACTS_DIR)/lex.yy.o
	$(CC) $(CFLAGS) $(BUILD_ARTIFACTS_DIR)/y.tab.o $(BUILD_ARTIFACTS_DIR)/lex.yy.o $(I_SRC) -o $(I_TARGET)

# Clean build artifacts
clean:
	rm -rf $(LEXYACC_DIR)/lex.yy.* $(LEXYACC_DIR)/y.tab.* $(BUILD_ARTIFACTS_DIR)/* $(BIN_DIR)/*.exe $(LIB_DIR)/*
