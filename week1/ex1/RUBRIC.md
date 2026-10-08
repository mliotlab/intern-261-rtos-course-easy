# Rubric — Week 1 / Ex1

| Phần | Trọng số | Đạt điểm khi |
|---|---|---|
| Code | **30%** | Build sạch, `check_api.sh` = 0, kiểm tra return của `xTaskCreate`, task không return, không sửa Drivers/ |
| Số đo phần cứng | **30%** | Có ảnh PulseView đọc được, đủ min/max/tb, có stack high water mark thực tế |
| Giải thích | **25%** | Ba handler đúng tên + đúng nhiệm vụ; lý do TIM4 nối được đến priority của `HAL_IncTick()`; log lỗi link thật |
| Vấn đáp | **15%** | Trả lời được câu hỏi đánh đổi bằng số của mình; giải thích được mọi chỗ lệch dự đoán |

Code tối đa 30%. Số đo + giải thích + vấn đáp = 70%.

## Trượt ngay nếu
- Có bất kỳ `cmsis_os*` / `os*` trong code.
- `PREDICTION.md` commit sau khi đã nạp chương trình (kiểm bằng git log).
- Report dùng số không khớp `params.h` của chính mình.
- Không có ảnh đo thực tế.
