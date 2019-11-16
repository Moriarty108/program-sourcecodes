.model small
.data
    num1 db 5h,47h
    num2 db 4h,28h
    result db 2 dup(0)
.code
    main proc
        mov ax,@data
        mov ds,ax

        mov al,num1+1
        mov bl,num2+1
        sub al,bl
        das
        mov result+1,al

        mov al,num1
        mov bl,num2
        sbb al,bl
        mov result,al

        main endp
end
