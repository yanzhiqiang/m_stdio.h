OBJECT=log.o
CC=g++
CFLAGS= -g 

test : $(OBJECT)
	$(CC)  $(CFLAGS) -o test test.cpp $(OBJECT)  
$(OBJECT) : %.o : %.cpp
	$(CC) -c  $(CFLAGS) $< -o $@   
                             
clean: 
	rm -rf test $(OBJECT) 
