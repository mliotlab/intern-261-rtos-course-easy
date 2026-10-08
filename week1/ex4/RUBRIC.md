# Rubric — Week 1 / Ex4

| Phần | Trọng số | Đạt điểm khi |
|---|---|---|
| Code | **30%** | `check_api.sh` = 0, cả 2 hook hiện thực và báo ra ngoài được, 2 callback static memory dùng đúng đơn vị words, kiểm tra mọi return value |
| Số đo phần cứng | **30%** | Bảng ngân sách cộng đúng 20480 và truy được về `.map` (commit kèm); log UART thật với đầy đủ HWM kể cả idle + timer |
| Giải thích | **25%** | Giải thích đúng chênh lệch `.map` vs runtime theo từng mục; giải thích đúng dynamic vs static; chứng minh hook tràn stack đã chạy |
| Vấn đáp | **15%** | Câu hỏi đánh đổi: 2 phương án kèm bytes, chọn 1, đã thực hiện và đo lại |

Code tối đa 30%. Số đo + giải thích + vấn đáp = 70%.

## Trượt ngay nếu
- Có `cmsis_os*` / `os*` trong code.
- `PREDICTION.md` commit sau khi nạp chương trình.
- Bảng ngân sách không cộng đúng 20480, hoặc không commit `.map`.
- Báo "hook đã chạy" mà không có log/ảnh.
- HWM lẫn lộn đơn vị words/bytes.
