; Registers
; 	r16 - Input (char c) / Output
;	r17 - Mask 0
;	r18 - Mask 1
;	r19 - Mask 2
;	r20 - tmp 1 ( c & mask )
;	r21 - tmp 2 ( c >> ) & mask


	; INIT
	
	ldi r16, 4 	; CHAR C
	
	ldi r17, $55	; MASK 0
	ldi r18, $33	; MASK 1
	ldi r19, $0f	; MASK 2
	
	
	; CODE
	
	; Part 1
	mov r20, r16
	and r20, r17	; ( c & mask[0] )
	
	mov r21, r16
	lsr r21		; ( c >> 1)
	and r21, r17	; & mask[0]
	
	mov r16, r20	; c = r20 + r21
	add r16, r21
	
	
	; Part 2
	mov r20, r16
	and r20, r18	; ( c & mask[1] )
	
	mov r21, r16
	lsr r21		; ( c >> 2)
	lsr r21
	and r21, r18	; & mask[1]
	
	mov r16, r20	; c = r20 + r21
	add r16, r21
	
	
	; Part 3
	mov r20, r16
	and r20, r19	; ( c & mask[2] )
	
	mov r21, r16
	lsr r21		; ( c >> 4)
	lsr r21
	lsr r21
	lsr r21
	and r21, r19	; & mask[2]
	
	mov r16, r20	; c = r20 + r21
	add r16, r21
	
end:
	jmp end