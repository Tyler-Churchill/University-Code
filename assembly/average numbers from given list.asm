.globl main
.data
	n: .word 7 				# This example has 7 points
 	x: .word 30, 12, 45, 34, 40, 14, 30 	# x0, x1, … xn-1
 	y: .word 32, 10, 39, 89, 24, 12, 67 	# y0, y1, … yn-1
 	z: .word 42, 20, 76, 23, 23, 65, 15 	# z0, z1, … zn-1
 	xc: .space 4 				# a word result
 	yc: .space 4 				# a word result
 	zc: .space 4 				# a word result 
 	
.text
main:
	la $t0, x 			# t0 is my current array of ints to average
	jal average_numbers	# average the x array (stored in the parameter $t0)
	sw $a0 xc		# take the returned value from the proc and store it into xc
	
	la $t0, y 			# t0 is my current array of ints to average
	jal average_numbers	# average the y array (stored in the parameter $t0)
	sw $a0 yc		# take the returned value from the proc and store it into yc
	
	
	la $t0, z 			# t0 is my current array of ints to average
	jal average_numbers	# average the z array (stored in the parameter $t0)
	sw $a0 zc		# take the returned value from the proc and store it into zc
	
	addi $v0, $zero, 1		# set system to print out integers
	lw $a0, xc		# grab the average of the x array to print 
	syscall			# print the x array's average value
	lw $a0, yc		# grab the average of the y array to print 
	syscall 			# print the y array's average value
	lw $a0, zc		# grab the average of the z array to print 
	syscall			# print the z array's average value
	
	jal finish			# call the program end function to exit/terminate the program
	
average_numbers:			# averages the numbers inside of array at $t0 and puts the result into $t7
	lw $t3, n			# stores n into $t3
	add $t5, $zero, $zero	# t5 is the current index of the array
	add $t1, $zero, $zero	# t1 is the current sum
for:
	beq $t5, $t3, endfor 	# check if we have gone through every element in the array
	lw $s0, ($t0)		# grab the next word in the array
	add $t1, $t1, $s0
	addi $t0, $t0, 4		# increment offset
	addi $t5, $t5, 1 		# increment index
	j for
endfor:
	div $t1, $t3		# divide the total sum of all the values by how many elements are in the array
	mflo $t1			# move the answer from the division into $t1
	add $a0, $zero, $t1		# set a0 to the average
	jr $ra			# jump back to the main label to average the next given array
finish:
	addi $v0, $zero, 10		# set the system function to exit
	syscall			# exit the program
