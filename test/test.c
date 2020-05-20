#include <stdio.h>
#include <stdint.h>

#include "../Print/transmit_conf.h"
#include "../Format/format.h"
#include "../Print/print.h"
#include "../Asserts/asserts.h"
#include "../Queue_T/queue_t.h"

struct Msg
{
    uint32_t id;
    float value;
    uint16_t data[8];
};

void test_print()
{
    Print_fmt("This is a test program.\n");
    Print_fmt("The value is %d\n", 101);
}

void test_asserts()
{
    int i = 0;

    Asserts_param(i == 0);

    printf("Correct Parameters.\n");

    i = 1;

    Asserts_param(i == 0);
}

void print_msg(struct Msg *elem)
{
    printf("Msg ID is %x, value is %f, data is %d %d %d %d %d %d %d %d\n",
           elem->id, elem->value, elem->data[0], elem->data[1], elem->data[2],
           elem->data[3], elem->data[4], elem->data[5], elem->data[6], elem->data[7]);
}

void test_queue()
{
    struct Msg msg_buf[10];
    struct Msg elem;
    struct Msg *p_elem = NULL;
    Queue_T queue;

    int len = 0;
    int i = 0;

    // 队列初始化
    Queue_init(&queue, 5, sizeof(msg_buf[0]), &msg_buf);

    elem.id = 0x1896FC64;
    elem.value = 28.3;

    //连续向队列添加元素
    elem.data[0] = 0x10;
    elem.value = 29.5;
    Queue_push(&queue, &elem);
    elem.data[0] = 0x11;
    elem.value = 30.5;
    Queue_push(&queue, &elem);
    elem.data[0] = 0x12;
    elem.value = 31.5;
    Queue_push(&queue, &elem);
    elem.data[0] = 0x13;
    elem.value = 32.5;
    Queue_push(&queue, &elem);
    elem.data[0] = 0x14;
    elem.value = 33.5;
    Queue_push(&queue, &elem);

    // 获取队尾和队头元素
    p_elem = Queue_front(&queue);
    print_msg(p_elem);
    p_elem = Queue_back(&queue);
    print_msg(p_elem);

    // 队列大小
    len = Queue_size(&queue);
    printf("queue size is %d\n", len);
    for(i = 0; i < len; i++)
    {
        // 获取队列所有元素
        p_elem = (struct Msg*)Queue_pop(&queue);
        print_msg(p_elem);
    }
    printf("queue size is %d\n", Queue_size(&queue));
    printf("\n");

    elem.data[0] = 0x10;
    elem.value = 29.5;
    Queue_push(&queue, &elem);
    elem.data[0] = 0x11;
    elem.value = 30.5;
    Queue_push(&queue, &elem);
    elem.data[0] = 0x12;
    elem.value = 31.5;
    Queue_push(&queue, &elem);
    elem.data[0] = 0x13;
    elem.value = 32.5;
    Queue_push(&queue, &elem);
    elem.data[0] = 0x14;
    elem.value = 33.5;
    Queue_push(&queue, &elem);
    // 当队列已满时，继续向队列添加元素，将覆盖队头元素
    elem.data[0] = 0x15;
    elem.value = 34.5;
    Queue_push(&queue, &elem);
    elem.data[0] = 0x16;
    elem.value = 35.5;
    Queue_push(&queue, &elem);

    // 打印队头和队尾元素
    p_elem = Queue_front(&queue);
    print_msg(p_elem);
    p_elem = Queue_back(&queue);
    print_msg(p_elem);

    len = Queue_size(&queue);
    printf("queue size is %d\n", len);
    for(i = 0; i < len; i++)
    {
        //打印所有元素
        p_elem = (struct Msg*)Queue_pop(&queue);
        print_msg(p_elem);
    }
    printf("queue size is %d\n", Queue_size(&queue));
}


int main()
{
//    test_print();
//    test_asserts();
    test_queue();
    return 0;
}
