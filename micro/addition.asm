.model small
.data
    num1 dw 1231h,3278h
    num2 dw 0abcdh,0fa25h
    result dw ?,?,?
.code
    main proc
    mov ax,@data
    mov ds,ax

    mov ax,num1+2
    add ax,num2+2
    mov result+4,ax

    mov ax,num1
    adc ax,num2
    mov result+2,ax

    jnc noCarry
    mov result,1h
    
    noCarry: mov ah,4ch
    int 21h
    main endp
    
end