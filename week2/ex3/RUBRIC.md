# Rubric — Week 2 / Ex3

| Phần | Trọng số | Đạt điểm khi |
|---|---|---|
| Code | **30%** | `check_api.sh` = 0, dùng đúng `xSemaphoreCreateBinary`/`xSemaphoreCreateMutex`/`uxTaskPriorityGet`, 3 ưu tiên khác nhau rõ ràng và được justify |
| Số đo phần cứng | **30%** | 2 ảnh logic analyzer đủ 3 kênh, bảng thời gian block có số thực cho cả 2 cấu hình |
| Giải thích | **25%** | Chỉ đúng thời điểm bắt đầu/kết thúc inversion trên ảnh; giải thích đúng cơ chế priority inheritance |
| Vấn đáp | **15%** | Trả lời câu hỏi đánh đổi bằng số của mình và đã đo kiểm chứng |

Code tối đa 30%. Số đo + giải thích + vấn đáp = 70%.

## Trượt ngay nếu
- Có `cmsis_os*` / `os*` trong code.
- `PREDICTION.md` commit sau khi nạp chương trình.
- Không phân biệt được priority inversion với việc "task_low đơn giản là chạy lâu".
- Ảnh thiếu kênh hoặc không đọc được thời điểm inversion.
