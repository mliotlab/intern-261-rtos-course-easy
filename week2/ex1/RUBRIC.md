# Rubric — Week 2 / Ex1

| Phần | Trọng số | Đạt điểm khi |
|---|---|---|
| Code | **30%** | `check_api.sh` = 0, dùng đúng `xQueueCreate`/`xQueueSend`/`xQueueReceive`/`uxQueueMessagesWaiting`, không dùng mảng/con trỏ chia sẻ thay cho queue |
| Số đo phần cứng | **30%** | Đồ thị độ đầy 2 cấu hình, đếm được số mẫu mất/trễ khi UART chậm |
| Giải thích | **25%** | Phép tính kích thước queue tối thiểu đúng và khớp số đo (hoặc giải thích lệch); giải thích đúng 3 kiểu timeout |
| Vấn đáp | **15%** | Trả lời câu hỏi đánh đổi bằng số của mình và đã đo kiểm chứng |

Code tối đa 30%. Số đo + giải thích + vấn đáp = 70%.

## Trượt ngay nếu
- Có `cmsis_os*` / `os*` trong code.
- `PREDICTION.md` commit sau khi nạp chương trình.
- Kích thước queue tối thiểu không có phép tính, chỉ đoán.
- Không có đồ thị độ đầy queue theo thời gian.
