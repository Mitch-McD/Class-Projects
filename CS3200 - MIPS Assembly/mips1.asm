.data
	arrayA: .word 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
	arrayB: .space 100

.text
main:
	la $s6, arrayA
	la $s7, arrayB
	li $s0, 0
	li $s1, 5

	j While
	
While: 
    beq $s0, $s1, Exit		# if i == j, exit, else continue
    sll $t0, $s0, 2		# i * 4
    
    add $t1, $t0, $s6
    lw $t2, 0($t1)		# A[i]
    
    addi $t1, $t1, 4		# next position in array
    lw $t3, 0($t1)		# A[i+1]
    
    add $t1, $t2, $t3   	# A[i] + A[i+1]
    
    add $t4, $t0, $s6		# B[i]
    sw $t1, 0($t4)		# B[i] = A[i] + A[i+1]
    
            
    #add $a0, $zero, $t1		
    #li $v0, 1
    #syscall   
            
    addi $s0, $s0, 1		# i++
    j While

Exit:
	li $v0, 10
	syscall