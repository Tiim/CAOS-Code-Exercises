; Registers
; r16 - input value
; r17 - counter
; r18 - sum / output
; r19 - temp


ldi r16, $8  ; Load imput value
 

ldi r17, 0 ; Load value 0
ldi r18, $0  ; initialize sum variable to 0

loop:
add r18, r16 ; Add input value to sum
inc r17 ; decrement the counter value

cpi r17, 14   ; compare the counter value to 12 (end of loop)
brne loop    ; if the counter value is not 12 continue with loop


ldi r19, 255
eor r18, r19 ; vorzeichen wechseln wie in den slides

end:
jmp end




