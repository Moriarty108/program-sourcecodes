.model small
.data
    inputmsg db 10,13,'Enter a 8-bit Binary Number :$'
    outputmsg db 10,13,'Converted ascii character :$'
    bin db ?
.code
    main proc
    mov ax,@data
    mov ds,ax

    lea dx,inputmsg
    mov ah,9
    int 21h

    mov cx,8
    takeinput: mov ah,1
    int 21h
    sub al,30h
    dec cl
    shl al,cl
    inc cl
    add bin,al
    loop takeinput

    mov ah,9
    lea dx,outputmsg
    int 21h
    mov dl,bin
    mov ah,2
    int 21h

    main endp
end 
