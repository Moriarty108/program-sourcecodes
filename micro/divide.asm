.model small

.data
    dividend dw 12A3h,65B2h
    divisor dw 32A1h
    
    quotient dw 2 dup(0)
    remainder dw ?
.code
    main proc
    mov ax,@data
    mov ds,ax

    mov ax,dividend
    div divisor
    mov quotient,ax
    mov remainder,dx

    mov ax,dividend+2
    add ax,remainder
    div divisor
    mov quotient+2,ax
    mov remainder,dx

    main endp
end