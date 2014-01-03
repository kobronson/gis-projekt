CFLAGS = -g	

OBJS = graph.o main.o set.o

LIBS =

TARGET = g_algo

$(TARGET):	$(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LIBS) 

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
