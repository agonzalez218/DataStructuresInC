###########################################################################
#
# makefile
# Makefile for Data Structures and Sort Algorithms in C
# Author: Abel Gonzalez
#
###########################################################################

# headers is the folder with the shared header file
CFLAGS += -Iheaders

# Makefile runs this menu/info panel instead of one of the below commands
all:
	@echo "**********************************************************"
	@echo " "
	@echo "Name: Abel Gonzalez"
	@echo "Data Structures and Sort Algorithms in C"
	@echo "Use make CDataStruct to create executable"
	@echo "Use make RunCDataStruct to run executable"
	@echo "Use make CleanCDataStruct to delete executable"
	@echo " "
	@echo "**********************************************************"
	gcc -o main main.c BST.c LinkedList.c minheap.c queue.c set.c sort.c stack.c

# creates the executable
CDataStruct: main.c BST.c LinkedList.c minheap.c queue.c set.c sort.c stack.c
	gcc -o exec/CDataStruct $^ -lm

# Runs the executable
RunCDataStruct: 
	./exec/CDataStruct

# Deletes the executable
CleanCDataStruct:
	rm ./exec/CDataStruct

# Deletes
CleanAll:
	rm *.