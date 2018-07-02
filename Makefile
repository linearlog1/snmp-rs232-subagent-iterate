#
# Warning: you may need more libraries than are included here on the
# build line.  The agent frequently needs various libraries in order
# to compile pieces of it, but is OS dependent and we can't list all
# the combinations here.  Instead, look at the libraries that were
# used when linking the snmpd master agent and copy those to this
# file.
#

#CC=gcc

OBJS=rs232-daemon.o rs232Number.o rs232PortTable.o rs232AsyncPortTable.o charPortTable.o diProduct.o generalType.o
TARGETS=rs232-daemon-iter

CFLAGS=-I. `net-snmp-config --cflags`
BUILDLIBS=`net-snmp-config --libs`
BUILDAGENTLIBS=`net-snmp-config --agent-libs`


# shared library flags (assumes gcc)
DLFLAGS=-fPIC -shared

all: $(TARGETS)

rs232-daemon-iter: $(OBJS)
	$(CC) -o rs232-daemon-iter $(OBJS)  $(BUILDAGENTLIBS)

clean:
	rm -f  $(OBJS) $(TARGETS)

