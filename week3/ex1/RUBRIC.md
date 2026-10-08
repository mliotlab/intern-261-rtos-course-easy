# Rubric — Week 3 / Ex1

| Phần | Trọng số | Đạt điểm khi |
|---|---|---|
| Code | **30%** | `check_api.sh` = 0, dùng đúng `vTaskNotifyGiveFromISR`/`portYIELD_FROM_ISR`, `ISR_NVIC_PRIO` hợp lệ trong bản nộp cuối |
| Số đo phần cứng | **30%** | Ảnh latency 2 cấu hình (có/không `portYIELD_FROM_ISR`), đọc được số từ ảnh |
| Giải thích | **25%** | Giải thích đúng quan hệ priority NVIC/`configMAX_SYSCALL_INTERRUPT_PRIORITY`; mô tả đúng hiện tượng assert |
| Vấn đáp | **15%** | Trả lời câu hỏi đánh đổi bằng số đo của mình |

Code tối đa 30%. Số đo + giải thích + vấn đáp = 70%.

## Trượt ngay nếu
- Có `cmsis_os*` / `os*` trong code.
- `PREDICTION.md` commit sau khi nạp chương trình.
- Bản nộp cuối vẫn còn priority sai (cao hơn `configMAX_SYSCALL_INTERRUPT_PRIORITY`).
- Không có bằng chứng (ảnh/log) cho bước configASSERT.
