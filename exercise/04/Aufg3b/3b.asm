;	Registers
;	r16 - Input
;	r17 - Decremented input
;	r18 - Counter / Output

	ldi r16, 255 	; load input
	ldi r18, 0	; clear counter
loop:			
	cpi r16, 0	; check if input is 0
	breq end 
	
	mov r17, r16	; make r17 <= r16 - 1
	dec r17
	
	and r16, r17 	; remove single one
	
	inc r18		; increment counter
	
	
	jmp loop	; repeat
	
	
end:
	jmp end