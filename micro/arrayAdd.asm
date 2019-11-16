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

        mov cx,len1

        mov al,len1
        mov bl,len2
        cmp al,bl
        jne endpr

        mov si,0
        mov di,0
        addthem:cmp si,len1
        je done
        mov al,array1[si]
        mov bl,array2[si]

        add al,bl
        mov result[di],al
        inc di
        inc si
        jmp addthem

        done:mov si,0
        print: mov dl,result[si]
        add dl,30h
        mov ah,2
        int 21h
        inc si
        loop print

        endpr:main endp
end


