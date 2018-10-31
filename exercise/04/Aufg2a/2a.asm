; Registers
; r16 - Input
; r17 - remainder division input by 16
; r18 - out 1
; r19 - out 2
; r20 - temp
;---
; https://www.quora.com/How-can-I-convert-from-decimal-to-hexadecimal-in-C-language

	ldi r16, $3F  ; input value

	mov r17, r16  ; copy value
	andi r17, $0F ; modulo 16
	
	mov r18, r17  ; copy remainder to output 1	
	
	cpi r17, $0A  ; if remainder >= 10
	brlt less1    ; then
	
	ldi r20, $57
	add r18, r20     ; add 87 to output 1
	jmp end1

less1:                ; else
	ldi r20, $30
	add r18, r20     ; add 48 to output 1

end1:                 ; endif

	lsr r16       ; divide by 16
	lsr r16 
	lsr r16 
	lsr r16 
	mov r17, r16  ;copy value
	andi r17, $0F ; modulo 16
	
	mov r19, r17  ; copy remainder to output 2 

	cpi r17, $0A  ; if remainder >= 10
	brlt less2    ; then

	ldi r20, $57
	add r19, r20     ; add 87 to output 2
	jmp end2

less2:                ; else
	ldi r20, $30
	add r19, r20     ; add 48 to output 2

end2:                 ; endif

jmp end2