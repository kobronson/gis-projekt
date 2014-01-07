CFLAGS = -g	

OBJS = graph.o main.o set.o prim.o kruskal.o

LIBS =

TARGET = mst

$(TARGET):	$(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LIBS) 

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
