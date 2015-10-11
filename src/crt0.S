.set MAGIC, 0x1badb002
.set FLAGS, (1<<0 | 1<<1) # align, provide mem map
.set CHECKSUM, -(MAGIC + FLAGS)

.section .multiboot
    .long MAGIC
    .long FLAGS
    .long CHECKSUM

.section .text
.extern kmain
.global _start

_start:
    push %ebx /* multiboot info */
    push %eax /* magic */
    call _Z5kmainjP14multiboot_info /* kernel entry point */
    hlt
