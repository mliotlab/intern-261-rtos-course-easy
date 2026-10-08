# Dự đoán — Week 1 / Ex4

> **Commit TRƯỚC khi nạp chương trình.**

`student_id`: ______    `HEAP_SIZE_BYTES` = ____    `DYN_TASK_STACK_WORDS` = ____
`STATIC_TASK_STACK_WORDS` = ____    `HOG_DEPTH_BYTES` = ____    `TARGET_FREE_HEAP_BYTES` = ____

1. Ngân sách RAM dự đoán (tổng phải = 20480 bytes):

| Mục | Bytes dự đoán |
|---|---|
| `.data` | |
| `.bss` (không kể heap FreeRTOS) | |
| Heap FreeRTOS (`ucHeap`) | |
| Stack của main (MSP) | |
| Còn lại / chưa dùng | |
| **Tổng** | **20480** |

2. `xPortGetFreeHeapSize()` ngay sau khi scheduler chạy: ____ bytes.
   `HEAP_SIZE_BYTES` − số này = ____ . Số đó là của những gì?
3. High water mark dự đoán (words): dyn ____ , stat ____ , idle ____ , timer ____ .
4. `dyn_task` có stack ____ words = ____ bytes. Mảng `HOG_DEPTH_BYTES` = ____ bytes.
   Hook tràn stack **có** chạy không? Vì sao?
5. Heap trong `.map` và `xPortGetFreeHeapSize()` sẽ lệch nhau. Lệch vì:
6. Stack nhỏ nhất an toàn của `dyn_task` dự đoán: ____ words. Dựa vào đâu?
