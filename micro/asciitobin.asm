.model small
.data
    inputmsg db 10,13,'Enter a Number : $'
    outputmsg db 10,13,'Binary Equivalent : $'

.code
    main proc
    mov ax,@data
    mov ds,ax

    mov ah,9
    lea dx,inputmsg
    int 21h

    mov ah,1
    int 21h

    mov bl,al

    mov ah,9
    lea dx,outputmsg
    int 21h

    mov cx,8
    print: rol bl,1
    mov dl,bl
    and dl,1
    add dl,30h
    mov ah,2
    int 21h
    loop print

    main endp
end

