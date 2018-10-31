; Registers
; r16 - input value low
; r17 - input value high
; r18 - counter
; r19 - sum low
; r20 - sum high


ldi r16, $8  ; Load imput value
ldi r17, $0


ldi r18, $c ; Load value 12

ldi r19, $0  ; initialize sum variable to 0
ldi r20, $0 


loop:
add r19, r16 ; Add input value to sum (low)
adc r20, r17 ; Add input to sum (high) + carry

subi r18, $1 ; decrement the counter value

cpi r18, 0   ; compare the counter value to 0 (end of loop)
brne loop    ; if the counter value is not 0 continue with loop

end:
jmp end


