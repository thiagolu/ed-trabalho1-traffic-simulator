CC := g++
CFLAGS := -std=c++14 -Wall -O3 -g
LIB := -Llib
DISTFLAGS := -static-libstdc++
INC := -I include
BINDIR :=./bin

SRCDIR := src
BUILDDIR := build
TESTDIR := test
APPDIR := app
INCDIR := include

SRCEXT := cpp
HEADEXT := hpp

SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
TESTS := $(shell find $(TESTDIR) -type f -name *.$(SRCEXT))
APPS := $(shell find $(APPDIR) -type f -name *.$(SRCEXT))

OBJECTS := $(patsubst %,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
TESTOBJECTS := $(patsubst %,$(BUILDDIR)/%,$(TESTS:.$(SRCEXT)=.o))
BINARIES := $(patsubst $(APPDIR)/%,bin/%,$(APPS:.$(SRCEXT)=))

COMPILE := $(CC) $(CFLAGS) $(INC) -c
MAKEDEPS := $(COMPILE) -MMD
LINKEDIT := $(CC) $(CFLAGS) $(LIB)

app: $(BINARIES)
	@./bin/traffic_simulator

compila: $(BINARIES)

bin/%: $(BUILDDIR)/$(APPDIR)/%.o $(OBJECTS)
	@$(LINKEDIT) -o $@ $^

# Standalone distributable file
bin/dist/%: $(BUILDDIR)/$(APPDIR)/%.o $(OBJECTS)
	@mkdir -p bin/dist/
	$(LINKEDIT) $(DISTFLAGS) -o $@ $^

bin/test: $(OBJECTS) $(TESTOBJECTS)
	@$(LINKEDIT) -o $@ $^

$(BUILDDIR)/%.o: %.$(SRCEXT)
	@mkdir -p $(dir $@)
	@$(MAKEDEPS) -o $@ $<
	@$(COMPILE) -o $@ $<

test: bin/test
	@./bin/test

.PHONY: test clean

clean:
	@rm -rf $(BUILDDIR) $(BINTESTDIR)
	@rm -r $(BINDIR)/*
