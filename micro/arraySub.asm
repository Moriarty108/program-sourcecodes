.model small
.data
    array1 db 7h,5h,4h
    len1 = ($-array1)
    array2 db 1h,2h,9h
    len2 = ($-array2)
    result db 4 dup(0)
.code
    main proc
    mov ax,@data
    mov ds,ax

    mov al,len1
    mov bl,len2
    cmp al,bl
    jne endpr

    mov si,0
    mov di,0
    mov cx,len1
    subtract: mov al,array1[si]
    mov bl,array2[si]
    sub al,bl
    mov result[di],al
    inc si
    inc di
    loop subtract

    mov cx,len1
    mov si,0
    mov ah,2
    print: mov dl,result[si]
    add dl,30h
    int 21h
    inc si
    loop print

    endpr: mov ah,4ch
    int 21h
    main endp
end
