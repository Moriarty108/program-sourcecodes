.model small
.data
    num1 db 2h,98h
    num2 db 3h,05h
    result db 2 dup(0)
.code
    main proc
        mov ax,@data
        mov ds,ax

        mov al,num1+1
        mov bl,num2+1
        add al,bl
        daa
        mov result+1,al

        mov al,num1
        mov bl,num2
        adc al,bl
        mov result,al

        main endp
end