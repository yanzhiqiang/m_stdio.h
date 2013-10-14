OBJECT=log.o m_time.o balance_tree.o date_type.o display_tree.o huffman.o min_tree.o
CC=g++
CFLAGS= -g 

All : clean test

test : $(OBJECT)
	$(CC)  $(CFLAGS) -o test test.cpp $(OBJECT)  
$(OBJECT) : %.o : %.cpp
	$(CC) -c  $(CFLAGS) $< -o $@   
                             
clean: 
	rm -rf test $(OBJECT) 
