.model small
.data
    array db 4,6,2,4,8,3,5,4
    len = ($-array)
    target db 3
    success db 10,13,'Found$'
    failure db 10,13,'Not Found$'
.code
    main proc
    mov ax,@data
    mov ds,ax

    mov si,0
    mov cx,len

    search: mov bl,target
    mov al,array[si]
    cmp al,bl
    je found
    inc si
    loop search

    lea dx,failure
    mov ah,9
    int 21h
    jmp endpr

    found: mov ah,9
    lea dx,success
    int 21h

    endpr: mov ah,4ch
    int 21h
    main endp
end

