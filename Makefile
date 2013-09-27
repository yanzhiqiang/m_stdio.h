OBJECT=log.o m_time.o
CC=g++
CFLAGS= -g 

All : clean test

test : $(OBJECT)
	$(CC)  $(CFLAGS) -o test test.cpp $(OBJECT)  
$(OBJECT) : %.o : %.cpp
	$(CC) -c  $(CFLAGS) $< -o $@   
                             
clean: 
	rm -rf test $(OBJECT) 
