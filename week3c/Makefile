.PHONY:clean
.PHONY:remove 

addidas:encode.o channel.o decode.o
	gcc -o encode encode.o 
	gcc -o channel channel.o 
	gcc -o decode decode.o 
	@echo "compiled well"

encode.o:encode.c encode.h
	gcc -c -o encode.o encode.c 

channel.o:channel.c channel.h
	gcc -c -o channel.o channel.c 

decode.o:decode.c decode.h
	gcc -c -o decode.o decode.c 


clean:
	rm -rf encode channel decode channel.o decode.o encode.o
remove:
	rm -rf en cha de 


# all:
# 	gcc -o encode encode.c
# 	gcc -o channel channel.c
# 	gcc -o  decode decode.c
