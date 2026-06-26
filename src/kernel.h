#ifndef KERNEL_H
# define KERNEL_H

extern int cursor_x;
extern int cursor_y;

struct idt_entry {
    uint16_t base_low;   // bits 0-15 de l'adresse du handler
    uint16_t selector;   // segment code (0x08 en général)
    uint8_t  zero;       // toujours 0
    uint8_t  flags;      // type + privilège
    uint16_t base_high;  // bits 16-31 de l'adresse du handler
} __attribute__((packed));

struct idt_ptr
{
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));

extern struct idt_entry idt[256];
extern struct idt_ptr   idtp;

#define PIC1_CMD  0x20
#define PIC1_DATA 0x21
#define PIC2_CMD  0xA0
#define PIC2_DATA 0xA1

void outb(uint16_t port, uint8_t val);
void inb(uint16_t port);
void pic_init();
void idt_set_gate(uint8_t num, uint32_t base, uint16_t selector, uint8_t flags);
void idt_init();
void enable_cursor(uint8_t top, uint8_t bottom);
void update_cursor();
void putchar(char c);
void kernel_main(void);

#endif
