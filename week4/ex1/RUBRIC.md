# Rubric — Week 4 / Ex1

| Phần | Trọng số | Đạt điểm khi |
|---|---|---|
| Timing budget | **35%** | Có số liệu us/Hz cụ thể, dựa trên latency đo thật ở tuần 3, kết luận đạt/không đạt rõ ràng |
| RAM budget | **30%** | Cộng dồn đúng queue + stack mọi task, nằm dưới `MAX_HEAP_BYTES`, có nguồn số liệu (không bịa) |
| Lựa chọn thiết kế | **20%** | Giải thích được priority và API đồng bộ đã chọn, có xử lý khi hàng đợi đầy |
| Vấn đáp / duyệt mentor | **15%** | Trả lời được vì sao chọn thiết kế này khi mentor hỏi trực tiếp |

## Trượt ngay nếu
- `PREDICTION.md` commit sau khi mentor duyệt.
- Timing/RAM budget không có số liệu (chỉ mô tả định tính).
- Thiết kế dùng `cmsis_os*` / `os*` (kể cả trong pseudo-code).
