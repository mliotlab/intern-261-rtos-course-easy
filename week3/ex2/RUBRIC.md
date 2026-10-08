# Rubric — Week 3 / Ex2

| Phần | Trọng số | Đạt điểm khi |
|---|---|---|
| Code | **30%** | `check_api.sh` = 0, dùng đúng `xTimerCreate`/`xTimerResetFromISR`/`xTimerStartFromISR`/`xTimerStopFromISR`, callback không block trong bản nộp cuối |
| Số đo phần cứng | **30%** | Ảnh nảy phím trước/sau rõ ràng, log timestamp long-press |
| Giải thích | **25%** | Giải thích đúng cơ chế daemon task + vì sao callback không được block |
| Vấn đáp | **15%** | Trả lời câu hỏi đánh đổi bằng số đo thật trên board của mình |

Code tối đa 30%. Số đo + giải thích + vấn đáp = 70%.

## Trượt ngay nếu
- Có `cmsis_os*` / `os*` trong code.
- `PREDICTION.md` commit sau khi nạp chương trình.
- Bản nộp cuối còn callback bị block (`vTaskDelay`/busy-wait dài trong timer callback).
- Không có ảnh nảy phím trước/sau.
