#include "syscall-init.h"
#include "print.h"
#include "thread.h"
#include "stdint.h"
#include "syscall.h"
#include "console.h"
#include "string.h"
#define syscall_nr 32 //最大支持系统调用子功能数
typedef void* syscall;
syscall syscall_table[syscall_nr];

uint32_t sys_getpid(void){
    return running_thread()->pid;
}

uint32_t sys_write(char* str){
    console_put_str(str);
    return strlen(str);
}

void syscall_init(){
    put_str("syscall_init start\n");
    syscall_table[SYS_GETPID] = sys_getpid;
    syscall_table[SYS_WRITE] = sys_write;
    put_str("syscalll_init done\n");
}