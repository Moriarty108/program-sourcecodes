.model small
.data
    arr  db 1h,2h,3h,4h,5h,6h,7h,8h
    len  = ($-arr) - 1
    target db 2h 
    msg1 db 10,13,'In Lower array$' 
    msg2 db 10,13,'In Upper array$'
    success db 10,13,'Found$'
    failed db 10,13,'Not Found$'
.code
    main proc
        mov ax,@data
        mov ds,ax

        mov cx,0
        mov di,len
        calcMid:
        cmp cx,di
        jg failure
        mov ax,cx
        add ax,di
        shr ax,1
        mov si,ax

        compare: mov bl,[si]
        mov al,target
        cmp al,bl
        je middle
        jg upper
        jl lower
    
        upper: mov cx,si
        inc cx
        jmp calcMid

        lower: mov di,si
        dec di
        jmp calcMid

        middle: lea dx,success
        mov ah,9
        int 21h
        jmp endpr

        failure: mov ah,9
        lea dx,failed
        int 21h
        
        endpr: main endp
        end 
    
    
    
    