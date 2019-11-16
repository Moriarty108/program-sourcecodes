.model small
.data
    array db 8,4,2,9,1,6,7
    len db ($-array)-1
.code
    main proc
    mov ax,@data
    mov ds,ax

    mov bl,0    ; outer variable (i = 0)
    outer: cmp bl,len   ; i < n
    jge toEnd           ; if i >=n
    mov si,0 ; inner variable (j = 0)
    inner: mov cl,len   ; cl = n - 1
           sub cl,bl    ; cl = n - 1 - i
           cmp si,cx    ; j < n - 1 - i
           jge endinner 
           mov al,array[si] ; al = array[j]
           mov dl,array[si+1] ; dl = array[j+1]
           cmp al,dl        ; a[j] > a[j+1]
           jl increment
           mov array[si+1],al  ; array[j+1] = al
           mov array[si],dl     ; array[j] = dl
           
           increment: inc si    ; j++;
           jmp inner        ; loop through
            endinner: inc bl    ; i++
            jmp outer           ; loop through

    toEnd: mov ah,4ch   ; stop
    int 21h
    main endp
end


