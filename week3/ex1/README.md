# Week 3 — Ex1: Ngắt → task, NVIC priority

**Thời lượng dự kiến: 3 giờ**

## Mục tiêu
Đánh thức một task từ ISR đúng cách, đo **latency ISR → task** trên logic
analyzer, và tự tay gây ra lỗi "đặt priority ngắt cao hơn
`configMAX_SYSCALL_INTERRUPT_PRIORITY`" để thấy `configASSERT` bắt lỗi đó.

## Đọc trước
- *Mastering the FreeRTOS Real Time Kernel* — Ch.7 (Interrupt Management)
- *RTOS for ARM Cortex-M* — chương về NVIC priority grouping & priority ceiling

## Việc cần làm
1. Cấu hình EXTI trên `PB<EXTI_PIN>` (nút nhấn), ngắt cạnh xuống.
2. Trong ISR: gọi `vTaskNotifyGiveFromISR` để đánh thức `ack_task`, kết thúc
   bằng `portYIELD_FROM_ISR(xHigherPriorityTaskWoken)`.
3. `ack_task`: `ulTaskNotifyTake(pdTRUE, portMAX_DELAY)`, ngay khi thức dậy
   toggle `PA<ACK_PIN>` — đây là cạnh dùng để đo latency ISR → task (kênh
   `EXTI_PIN` cạnh xuống → kênh `ACK_PIN` cạnh lên).
4. **Trước tiên**, đặt `HAL_NVIC_SetPriority` cho dòng EXTI bằng một giá trị
   **cao hơn** `configMAX_SYSCALL_INTERRUPT_PRIORITY` (số nhỏ hơn = ưu tiên
   phần cứng cao hơn). Nạp chương trình, quan sát `configASSERT` bị kích hoạt
   khi ISR gọi `vTaskNotifyGiveFromISR`. Chụp lại log/trạng thái lúc assert.
5. Sửa priority về đúng `ISR_NVIC_PRIO` (đã được kiểm chứng nằm dưới ngưỡng
   `configMAX_SYSCALL_INTERRUPT_PRIORITY`). Nạp lại, xác nhận hết assert.
6. Đo latency ISR → task bằng logic analyzer, 2 cấu hình: có và không có
   `portYIELD_FROM_ISR` (tạm xoá dòng này để so sánh). So với
   `LATENCY_BUDGET_US`.

## Cần nộp
- `app/exti_button.c`, `app/app_main.c`.
- Ảnh logic analyzer: cạnh `EXTI_PIN` → cạnh `ACK_PIN`, đủ để đọc latency,
  2 cấu hình (có/không `portYIELD_FROM_ISR`).
- Ghi lại chính xác hành vi/log khi `configASSERT` kích hoạt ở bước 4.
- `REPORT.md`, `PREDICTION.md` commit trước khi nạp.

## Đạt yêu cầu khi
- Giải thích đúng quan hệ giữa số priority NVIC (càng nhỏ càng ưu tiên cao),
  `configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY`, và vì sao gọi API FreeRTOS
  `FromISR` từ một ISR có priority cao hơn ngưỡng là undefined behavior.
- Latency đo được ở cấu hình đúng (`ISR_NVIC_PRIO` + `portYIELD_FROM_ISR`)
  nằm trong `LATENCY_BUDGET_US` — hoặc giải thích được vì sao không.
- Chỉ ra đúng latency tăng thêm bao nhiêu khi thiếu `portYIELD_FROM_ISR`.
