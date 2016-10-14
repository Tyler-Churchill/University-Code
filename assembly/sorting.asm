        .globl main		# consider "main" a global name
	.data			# start program's data segment
size:   .word 10		# space for the list size in words
list:   .word 70		# assume the list has up to 10 elements
	.word 26		# remember that each element has 4 bytes
	.word 20
	.word 45
	.word 78
	.word 140
	.word 48
	.word 98
	.word 32
	.word 30

        
	.text			# start program's text segment
# register usage in sort program
#  $a0: pointer to the first element in the list
#  $a1: pointer to the last element in the list
#  $t0: temporary place for value of the last element
#  $v0:	 pointer to the max element in the unsorted part
#  $v1:	 value of the max element in the unsorted part        	
				# input "size" and "list"
main:	la   $a0, list		# init pointer to the first element
	lw   $a1, size		# put "size" into $a1
	addi $a1, $a1, -1	# offset in words to the last element
	sll  $a1, $a1, 2	# offset in byte to the last element
	add  $a1, $a0, $a1	# init pointer to the last element
sort:	beq  $a0, $a1, done	# the list is sorted
	jal  max		# call the max procedure
	lw   $t0, 0($a1)	# load the last element into $t0
	sw   $t0, 0($v0)	# copy the last element into max location
	sw   $v1, 0($a1)	# copy the max value to the last element
	addi $a1, $a1, -4	# decrement pointer to the last element
	j    sort		# repeat sort for a smaller list
	
done:   # prepare to print out the elements to the console.
	la   $t0, list		# $t0 points to the first element in the "list"
	lw   $t1, size		# put "size" into $t1
	sll  $t1, $t1, 2	# Offset in bytes afer the last element
	add  $t1, $t0, $t1	# init pointer to the one after the last element
	add  $v0, $zero, 1	# print an integer by calling syscall
pdone:	beq  $t0, $t1, fin	# done printing
	lw   $a0, 0($t0)	# load the integer into $a0
	syscall			# print out the integer
	addi $t0, $t0, 4	# increment the pointer to the next element
        j pdone			# goto the next element
fin:	addi $v0, $zero, 10	# exit the program
	syscall			# call the syscall to exit

# register usage in max procedure
# $a0	pointer to the first element
# $a1	pointer to the last element
# $t0	pointer to the next element
# $t1   value of the next element
# $t2   result of the comparison "(next) < max"
# $v0	pointer to max element
# $v1	value of max element

max:	addi $v0, $a0, 0	# init max pointer to the first element
	lw   $v1, 0($v0)	# init max value to the first element
	addi $t0, $a0, 0	# init next pointer to the first element
loop:	beq  $t0, $a1, ret	# if next = last, we return
	addi $t0, $t0, 4	# advance to the next element
	lw   $t1, 0($t0)	# load the next element into $t1
	slt  $t2, $v1, $t1	# (next) < (max)
	bne  $t2, $zero, loop	# if (next) < (max), then repeat the loop
	addi $v0, $t0, 0	# next element is the new max element
	addi $v1, $t1, 0	# next value is the max value
	j    loop
ret:	jr $ra			# return to calling program
	