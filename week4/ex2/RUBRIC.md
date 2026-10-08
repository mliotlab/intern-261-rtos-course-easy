# Rubric — Week 4 / Ex2

| Phần | Trọng số | Đạt điểm khi |
|---|---|---|
| Code | **40%** | `check_api.sh` = 0, không còn API non-`FromISR` trong ISR, kiến trúc khớp design doc đã duyệt |
| Vận hành | **25%** | Build CMake sạch, chạy ổn định, UART ra đúng khối `LOG_BLOCK_SAMPLES` |
| Giải thích lỗi | **20%** | Giải thích đúng cơ chế vì sao API non-`FromISR` trong ISR là lỗi (không chỉ "sửa theo mẫu") |
| AI_LOG.md | **15%** | Đầy đủ, tự giải thích được mọi dòng code đã nộp khi vấn đáp |

## Trượt ngay nếu
- Có `cmsis_os*` / `os*` trong code → phần Code = 0.
- Không có `AI_LOG.md` hoặc không giải thích được code tự nộp → phần vấn
  đáp (tính chung ở ex4) = 0.
- Vẫn còn API queue non-`FromISR` gọi trong ISR ở bản nộp cuối.
