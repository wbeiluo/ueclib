
SRCS := test.c \
    ../Print/transmit_conf.c \
    ../Print/print.c \
    ../Format/format.c \
    ../Asserts/asserts.c \
    ../Queue_T/queue_t.c \
    ../Array_T/array_t.c

HEARERS := ../Print/transmit_conf.h \
    ../Print/print.h \
    ../Format/format.h \
    ../Asserts/asserts.h \
    ../Queue_T/queue_t.h \
    ../Array_T/array_t.h

DEFINES := -D"USE_ASSERTS" -D"USE_PRINT"

INCLUDES := -I../Print/ \
    -I../Format/ \
    -I../Asserts/ \
    -I../Queue_T/ \
    -I../Array_T

all: $(SRCS) $(HEADERS)
	gcc -o test $(INCLUDES) $(DEFINES) -g -Wall $(SRCS)

clean:
	rm -f *.o test
