

#array example: 
.data
	arrayA: .word 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
	h: .word 0x0010
	EOL: .byte '\n'
	
.text
main: 
	la $s3, arrayA
	lw $s2, h
	
	lw $t0, 32($s3)
	add $t0, $s2, $t0
	sw $t0, 48($s3)
	
	add $a0, $zero, $t0
	li $v0, 1 # syscall to print integer $t0 (or v0?) 
	syscall
	
	lb $a0, EOL
	li $v0, 11 #syscall to print a character
	syscall

	li $v0, 
	syscall