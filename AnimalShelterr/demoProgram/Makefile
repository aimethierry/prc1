#give PN the name of your c file wihich contains main
PN=myProgram

CFLAGS=-Wall -Werror -Iproduct -I../Unity -Itest

#add your own other c files here
SHARED=product/otherFile.c \
             product/mySecondFile.c 
                                 
TEST=$(SHARED) \
             ../Unity/unity.c \

$(PN): 
	gcc $(CFLAGS) product/$(PN).c $(SHARED) -o $(PN) 

$(PN)Test: 
	gcc $(CFLAGS) test/$(PN)Test.c $(TEST) -o $(PN)Test 

test: $(PN)Test
	./$(PN)Test
    
clean:
	rm -rf $(PN)Test $(PN) 

valgrind: 
	valgrind ./$(PN)
