# Rubric — Week 2 / Ex2

| Phần | Trọng số | Đạt điểm khi |
|---|---|---|
| Code | **30%** | `check_api.sh` = 0, dùng đúng `xSemaphoreCreateMutex`/`xSemaphoreTake`/`Give`, `taskENTER_CRITICAL`/`EXIT_CRITICAL`, không khóa lộn xộn (take không give) |
| Số đo phần cứng | **30%** | Log lỗi tái hiện được, bảng so sánh 3 cách có số thực |
| Giải thích | **25%** | Giải thích đúng vì sao lỗi xảy ra (interleaving ở mức byte UART), đúng vì sao critical section nguy hiểm nhất |
| Vấn đáp | **15%** | Trả lời câu hỏi đánh đổi bằng số của mình và đã đo kiểm chứng |

Code tối đa 30%. Số đo + giải thích + vấn đáp = 70%.

## Trượt ngay nếu
- Có `cmsis_os*` / `os*` trong code.
- `PREDICTION.md` commit sau khi nạp chương trình.
- Không tái hiện được lỗi gốc một cách ổn định (chỉ nói "có vẻ có lẫn").
- Mutex take không có give tương ứng trên mọi nhánh return.
