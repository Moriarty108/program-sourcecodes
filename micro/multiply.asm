.model small
.data
    num1 dw 2521h,3206h
    num2 dw 0a26h,6400h
    result dw 4 dup(0)

.code
    main proc
    mov ax,@data
    mov ds,ax

    mov ax,num1+2
    mul num2+2
    mov result+6,ax
    mov result+4,dx

    mov ax,num1
    mul num2+2
    add result+4,ax
    adc result+2,dx

    mov ax,num1+2
    mul num2
    add result+4,ax
    adc result+2,dx

    mov ax,num1
    mul num2
    add result+2,ax
    adc result,dx

    main endp
end

