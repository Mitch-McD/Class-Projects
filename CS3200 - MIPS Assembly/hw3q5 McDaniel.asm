.data

.text
main:			# HW 3 questions 5
     li $s0, 10		# initialize $s0 using immediate, variable g
     li $s1, -5		# initialize $s1 using immediate, variable h
     li $s2, 20		# initialize $s2 using immediate, variable i 
     li $s3, 15		# initialize $s3 using immediate, variable j 
     
     # need to complete 
     # need to initialize $a0-$a3 from $s0-$s3 
	add $a0, $s0, $zero
	add $a1, $s1, $zero
	add $a2, $s2, $zero
	add $a3, $s3, $zero 
     
     jal f
     
     add $a0, $v0, $zero
     li $v0, 1 		
     syscall		# syscall to print an integer 
	 
     li $v0 10		
     syscall		#syscall to exit the program

f:	
	add $t0, $ra, $zero	# store return address so it doesn't 
				# get overwritten by func
	jal func		
	
	add $a0, $v0, $zero 	# a = (x = func(a, b))
	add $a1, $a2, $a3 	# b = (y = c + d)
	
	jal func		
	# $v0 is carried from prior function
	jr $t0 			# return to main with stored return address
	
func:	
	slt $t1, $a1, $a0	# $a1 < $a0 ? 1 : 0
	addi $t2, $zero, 1	# $t2 = 1, used for beq compare
	beq $t1, $t2 Else 	# $t1 == $t2 ? Else : continue
	sub $v0, $a1, $a0	# $v0 = $a1 - $a0
	jr $ra			# return to f
	
Else:
	sub $v0, $a0, $a1	# $v0 = $a0 - $a1
	jr $ra			# return to f
	
	
	
	
	
