/* Call real machine code with the arguments the recompiled code has already
   laid out on its own stack.
       void rosemondNativeCall(Frame* frame)
       Frame { target, esp, eax, ecx, edx }   esp and the registers are in/out
   ebx, esi and edi are callee-saved in the x86 ABI, so the target preserves
   them: the frame pointer, our own stack pointer and the target address all
   survive the call in registers. */
	.text
	.globl	_rosemondNativeCall
_rosemondNativeCall:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%esi
	pushl	%edi

	movl	8(%ebp), %esi		/* the frame */
	movl	0(%esi), %ebx		/* target address */
	movl	8(%esi), %eax		/* registers a convention might pass in */
	movl	12(%esi), %ecx
	movl	16(%esi), %edx

	movl	%esp, %edi		/* remember our own stack */
	movl	4(%esi), %esp		/* stand on the emulated stack instead */
	call	*%ebx			/* pushes its return address into the slot
					   the generated call already reserved */
	movl	%esp, %ecx		/* however much the callee popped is now
					   the difference -- which is what tells
					   us its calling convention */
	movl	%edi, %esp		/* back to our own stack */

	movl	%eax, 8(%esi)
	movl	%edx, 16(%esi)
	movl	%ecx, 4(%esi)

	popl	%edi
	popl	%esi
	popl	%ebx
	popl	%ebp
	ret
