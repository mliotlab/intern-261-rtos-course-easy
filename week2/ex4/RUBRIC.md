# Rubric — Week 2 / Ex4

| Phần | Trọng số | Đạt điểm khi |
|---|---|---|
| Code | **30%** | `check_api.sh` = 0, dùng đúng `xEventGroupSetBits`/`WaitBits`, `xTaskNotifyGive`/`ulTaskNotifyTake`, clear-on-exit đúng |
| Số đo phần cứng | **30%** | Bảng RAM + bảng thời gian đánh thức có số thực đo bằng DWT |
| Giải thích | **25%** | Nêu đúng tình huống không dùng được notification; giải thích đúng cơ chế timeout của `xEventGroupWaitBits` |
| Vấn đáp | **15%** | Trả lời câu hỏi đánh đổi bằng số của mình và đã đo kiểm chứng |

Code tối đa 30%. Số đo + giải thích + vấn đáp = 70%.

## Trượt ngay nếu
- Có `cmsis_os*` / `os*` trong code.
- `PREDICTION.md` commit sau khi nạp chương trình.
- Bảng RAM lấy số từ tài liệu thay vì đo/tính từ cấu trúc dữ liệu thực tế.
- Không phân biệt được "đủ bit" với "timeout" trong code xử lý kết quả `xEventGroupWaitBits`.
