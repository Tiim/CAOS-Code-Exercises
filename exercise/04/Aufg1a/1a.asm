; Registers
; r16 - input value
; r17 - counter
; r18 - sum/output


ldi r16, $8  ; Load imput value
 

ldi r17, $c ; Load value 12
ldi r18, $0  ; initialize sum variable to 0

loop:
add r18, r16 ; Add input value to sum
subi r17, $1 ; decrement the counter value

cpi r17, 0   ; compare the counter value to 0 (end of loop)
brne loop    ; if the counter value is not 0 continue with loop

end:
jmp end


