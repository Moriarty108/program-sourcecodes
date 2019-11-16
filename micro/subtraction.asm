.model small
.data
    num1 dw 0ffffh,0ffffh
    num2 dw 1111h,1111h
    result dw ?,?
.code
    main proc
    mov ax,@data
    mov ds,ax

    mov ax,num1+2
    sub ax,num2+2
    mov result+2,ax

    mov ax,num1
    sbb ax,num2
    mov result,ax

    main endp
end

