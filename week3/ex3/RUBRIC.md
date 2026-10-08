# Rubric — Week 3 / Ex3

| Phần | Trọng số | Đạt điểm khi |
|---|---|---|
| Code | **30%** | `check_api.sh` = 0, dùng đúng `xStreamBufferCreate`/`xStreamBufferSendFromISR`/`xStreamBufferReceive`/`vTaskSuspend`/`vTaskResume` |
| Số đo phần cứng | **30%** | Demo 3 loại lệnh có bằng chứng, bảng test gửi nhanh có số liệu |
| Giải thích | **25%** | Không mất byte ở baud bình thường (hoặc giải thích đúng nguyên nhân nếu có); giải thích đúng vì sao stream buffer |
| Vấn đáp | **15%** | Trả lời câu hỏi đánh đổi bằng số đo của mình |

Code tối đa 30%. Số đo + giải thích + vấn đáp = 70%.

## Trượt ngay nếu
- Có `cmsis_os*` / `os*` trong code.
- `PREDICTION.md` commit sau khi nạp chương trình.
- Mất byte ở tốc độ gõ tay bình thường (lỗi thiết kế, không phải điều kiện biên).
- Thiếu bất kỳ loại lệnh nào trong 3 loại `P`/`S`/`T`.
