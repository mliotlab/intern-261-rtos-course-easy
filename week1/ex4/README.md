# Week 1 — Ex4: Ngân sách RAM 20 KB

**Thời lượng dự kiến: 4 giờ**

## Mục tiêu
Biết **chính xác từng byte** RAM đi đâu. Chứng minh bằng 3 nguồn độc lập:
`.map` file, API của FreeRTOS lúc chạy, và một lần tràn stack có chủ ý.

## Đọc trước
- *Mastering the FreeRTOS Real Time Kernel* — Ch.2 (Heap Memory Management), Ch.3 mục 3.4
  (`xTaskCreateStatic`), Ch.12 mục 12.3 (Stack Overflow)
- RM0008 — mục 3.3 Memory map (xác nhận SRAM = 20 KB)

## Việc cần làm
1. Đặt `configTOTAL_HEAP_SIZE` = `HEAP_SIZE_BYTES`. Bật
   `configCHECK_FOR_STACK_OVERFLOW` = 2 và `configUSE_MALLOC_FAILED_HOOK` = 1,
   hiện thực **cả hai hook**; hook phải báo ra ngoài được (UART hoặc LED pattern riêng).
2. Tạo 2 task làm cùng một việc:
   - `dyn_task` bằng `xTaskCreate`, stack `DYN_TASK_STACK_WORDS`
   - `stat_task` bằng `xTaskCreateStatic`, stack `STATIC_TASK_STACK_WORDS`
3. Lập bảng **ngân sách RAM** từ `.map`: `.data`, `.bss`, heap FreeRTOS,
   stack của main (MSP), và phần còn lại. Tổng phải = 20480 bytes.
4. Lúc chạy, in ra UART: `xPortGetFreeHeapSize()`,
   `xPortGetMinimumEverFreeHeapSize()`, và `uxTaskGetStackHighWaterMark()` của
   từng task (kể cả idle và timer task).
   Chứng minh heap còn trống >= `TARGET_FREE_HEAP_BYTES`.
5. **Đối chiếu**: số heap từ `.map` và số từ `xPortGetFreeHeapSize()` phải giải thích
   được chênh lệch. Chênh lệch đó là gì?
6. Làm tràn stack có chủ ý: trong `dyn_task`, khai báo mảng cục bộ
   `HOG_DEPTH_BYTES` bytes và ghi vào nó. Chứng minh hook đã chạy (ảnh/log).
   Sau đó tính **giá trị stack nhỏ nhất** mà `dyn_task` vẫn chạy an toàn, đặt lại,
   và chứng minh bằng high water mark.

## Cần nộp
- `app/app_main.c`, `app/hooks.c`, `app/ram_report.c`.
- `.map` file commit kèm (hoặc đoạn trích có đầy đủ các section).
- Log UART thật (copy nguyên văn) cho bước 4 và bước 6.
- Bảng ngân sách RAM cộng đúng 20480.
- `PREDICTION.md` commit trước khi nạp.

## Đạt yêu cầu khi
- Bảng ngân sách cộng **đúng** 20480 bytes, mỗi dòng truy được về `.map`.
- Giải thích được chênh lệch giữa heap trong `.map` và `xPortGetFreeHeapSize()`.
- Chứng minh được hook tràn stack đã chạy thật.
- Stack cuối cùng của `dyn_task` có biên an toàn >= 32 words và bạn giải thích
  được tại sao chọn con số đó.
