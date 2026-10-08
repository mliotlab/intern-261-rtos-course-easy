# Rubric — Week 3 / Ex4

| Phần | Trọng số | Đạt điểm khi |
|---|---|---|
| Code | **30%** | `check_api.sh` = 0, dùng đúng `vTaskGetRunTimeStats`/`uxTaskGetSystemState`/`xEventGroupWaitBits`, deadlock đã sửa, IWDG hoạt động |
| Số đo phần cứng | **30%** | Bảng CPU %, log/video watchdog reset thật |
| Giải thích | **25%** | Bằng chứng tìm deadlock bằng công cụ (không đoán), giải thích đúng nguyên nhân AB-BA |
| Vấn đáp | **15%** | Trả lời câu hỏi đánh đổi bằng số đo của mình |

Code tối đa 30%. Số đo + giải thích + vấn đáp = 70%.

## Trượt ngay nếu
- Có `cmsis_os*` / `os*` trong code.
- `PREDICTION.md` commit sau khi nạp chương trình.
- Không có bằng chứng `uxTaskGetSystemState` trước khi sửa (chỉ nói "em đoán do deadlock").
- Watchdog không thật sự reset được board khi tái tạo deadlock (chỉ mô tả lý thuyết).
