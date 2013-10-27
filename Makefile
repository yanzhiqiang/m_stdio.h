OBJECT=log.o m_time.o balance_tree.o date_type.o display_tree.o huffman.o min_tree.o
CC=g++
CFLAGS= -g
TFLAGS=-s -fPIC -pipe -pthread -O3  
LDLIBS = -Wl,-Bsymbolic -lpthread 

All : clean test

test : $(OBJECT)
	$(CC)  $(CFLAGS) -o test test.cpp $(OBJECT) 
	 $(CC)  $(TFLAGS) -fPIC -shared -o libmstdio.so $(OBJECT)  $(LDLIBS)

$(OBJECT) : %.o : %.cpp
	$(CC) -c  $(CFLAGS) $< -o $@   
                             
clean: 
	rm -rf test $(OBJECT) 
