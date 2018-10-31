; Registers
; r16 - input
; r17 - counter / output
; r18 - mask
; r19 - loop variable
; r20 - mask check

	ldi r16, $FF ; load input (0xF = 0b1111)
	ldi r17, $0 ; clear counter
	ldi r18, $1 ; initialize mask
	ldi r19, $8 ; initialize loop variable
	
loop:	
	mov r20, r16 ; copy input to mask check
	and r20, r18 ; apply mask
	
	cpi r20, 1  ; if result >= 1
	brsh is_greater
	jmp endif
is_greater:
	
	inc r17	     ;	increment counter

endif:
	lsl r18      ; shift mask left
	dec r19	     ; decrement loop variable
	cpi r19, $0  ; if loop variable is 0 
	brne loop     ; end program

end:
	jmp end