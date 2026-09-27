; Call real machine code with the arguments the recompiled code has already laid
; out on its own stack. MASM form of src/lib/trampoline.S; keep the two in step.
;
;     void rosemondNativeCall(NativeCallFrame* frame)
;     NativeCallFrame { target, esp, eax, ecx, edx }   esp and registers in/out
;
; ebx, esi and edi are callee-saved in the x86 ABI, so the frame pointer, our own
; stack pointer and the target address all survive the call in registers.

.386
.MODEL FLAT, C
.CODE

rosemondNativeCall PROC
    push ebp
    mov  ebp, esp
    push ebx
    push esi
    push edi

    mov  esi, [ebp+8]           ; the frame
    mov  ebx, [esi+0]           ; target address
    mov  eax, [esi+8]           ; registers a convention might pass in
    mov  ecx, [esi+12]
    mov  edx, [esi+16]

    mov  edi, esp               ; remember our own stack
    mov  esp, [esi+4]           ; stand on the emulated stack instead
    call ebx                    ; pushes its return address into the slot the
                                ; generated call already reserved
    mov  ecx, esp               ; however much the callee popped is now the
                                ; difference -- which is what tells us its
                                ; calling convention
    mov  esp, edi               ; back to our own stack

    mov  [esi+8], eax
    mov  [esi+16], edx
    mov  [esi+4], ecx

    pop  edi
    pop  esi
    pop  ebx
    pop  ebp
    ret
rosemondNativeCall ENDP

END
