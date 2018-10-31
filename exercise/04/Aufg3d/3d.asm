; Registers
; 	r16 - Input (char c) low / output
;	r17 - Input high
;	r18 - Mask 0
;	r19 - Mask 1
;	r20 - Mask 2
;	r21 - tmp 1 ( c & mask )
;	r22 - tmp 2 ( c >> ) & mask


	; INIT
	
	ldi r16, 4 	; CHAR C
	ldi r17, 0
	
	ldi r18, $55	; MASK 0
	ldi r19, $33	; MASK 1
	ldi r20, $0f	; MASK 2
	
	
	; CODE
	
	; Part 1 (low)
	mov r21, r16
	and r21, r18	; ( c & mask[0] )
	
	mov r22, r16
	lsr r22		; ( c >> 1)
	and r22, r18	; & mask[0]
	
	mov r16, r21	; c = r21 + r22
	add r16, r22
	
	; Part 1 (high)
	mov r21, r17
	and r21, r18	; ( c & mask[0] )
	
	mov r22, r17
	lsr r22		; ( c >> 1)
	and r22, r18	; & mask[0]
	
	mov r17, r21	; c = r21 + r22
	add r17, r22
	
	
	; Part 2
	mov r21, r16
	and r21, r19	; ( c & mask[1] )
	
	mov r22, r16
	lsr r22		; ( c >> 2)
	lsr r22
	and r22, r19	; & mask[1]
	
	mov r16, r21	; c = r21 + r22
	add r16, r22
	
	; Part 2 high
	mov r21, r17
	and r21, r19	; ( c & mask[1] )
	
	mov r22, r17
	lsr r22		; ( c >> 2)
	lsr r22
	and r22, r19	; & mask[1]
	
	mov r17, r21	; c = r21 + r22
	add r17, r22
	
	
	
	; Part 3
	mov r21, r16
	and r21, r20	; ( c & mask[2] )
	
	mov r22, r16
	lsr r22		; ( c >> 4)
	lsr r22
	lsr r22
	lsr r22
	and r22, r20	; & mask[2]
	
	mov r16, r21	; c = r21 + r22
	add r16, r22
	
	
	mov r21, r17
	and r21, r20	; ( c & mask[2] )
	
	mov r22, r17
	lsr r22		; ( c >> 4)
	lsr r22
	lsr r22
	lsr r22
	and r22, r20	; & mask[2]
	
	mov r17, r21	; c = r21 + r22
	add r17, r22
	
	add r16, r17 	; add low and high together
	
end:
	jmp end