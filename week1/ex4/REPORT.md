# Report — Week 1 / Ex4

`student_id`: ______    Commit của PREDICTION.md: ______

## 1. Ngân sách RAM từ `.map`
| Mục | Symbol / section trong `.map` | Bytes |
|---|---|---|
| `.data` | | |
| `.bss` (không kể heap) | | |
| Heap FreeRTOS (`ucHeap`) | | |
| Stack của main (MSP) | | |
| Còn lại / chưa dùng | — | |
| **Tổng** | | **20480** |

`.map` commit tại: `______`

## 2. Số lúc chạy (dán nguyên văn log UART)
```
```

| Đại lượng | Words | Bytes |
|---|---|---|
| `xPortGetFreeHeapSize()` | — | |
| `xPortGetMinimumEverFreeHeapSize()` | — | |
| HWM `dyn_task` | | |
| HWM `stat_task` | | |
| HWM `ram_report_task` | | |
| HWM idle task | | |
| HWM timer task | | |

Heap còn trống >= `TARGET_FREE_HEAP_BYTES` (____)? ____

## 3. Đối chiếu `.map` vs runtime
Heap trong `.map` = ____ ; `xPortGetFreeHeapSize()` = ____ ; lệch = ____ bytes.
Lệch này gồm những gì (liệt kê từng mục kèm số bytes):

## 4. Dynamic vs static
HWM của `dyn_task` và `stat_task` lệch ____ words dù làm cùng một việc. Vì sao?
`xTaskCreate` và `xTaskCreateStatic` khác nhau ở đâu về **nơi** TCB và stack nằm?

## 5. Tràn stack
Log/ảnh chứng minh hook đã chạy:
```
```
Tại sao trong `vApplicationStackOverflowHook` không được gọi hàm UART blocking
(hoặc: nếu bạn vẫn gọi được, giải thích tại sao nó không crash — và tại sao đó là may):

## 6. Stack nhỏ nhất an toàn
| Lần thử | Stack (words) | HWM (words) | Kết quả |
|---|---|---|---|
| | | | |

Giá trị cuối cùng chọn: ____ words. Biên an toàn: ____ words. Lý do chọn biên đó:

## 7. Lệch so với dự đoán
Mỗi dòng lệch + nguyên nhân.

## 8. Câu hỏi đánh đổi
Với `HEAP_SIZE_BYTES` = ____ của bạn: nếu phải thêm một task nữa có stack 128 words,
**lấy RAM từ đâu**? Dựa vào bảng ngân sách của bạn, đưa ra 2 phương án kèm chi phí
cụ thể (bytes), rồi chọn một và **thực hiện, đo lại để chứng minh**.
