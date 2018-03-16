section .data
  fmt:    DB "%d", 10, 0 ; The printf format, "\n",'0'
	tmp: dd 300
	tmp2: dd 200
	msg db 'hello '
section .text
	extern printf
	global _start
global hello

_start:


	mov edi, tmp2
	mov esi,edi
	mov edi, tmp
	push esi
	push fmt
	call printf
	push DWORD [esi]
	push fmt
	call printf



	mov	eax,1
	int 0x80
